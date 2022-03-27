#include "MorseSpectrum.h"


MorseSpectrum::MorseSpectrum(const float& left, const float& right, const float& top, const float& bot,
    const string& formulaX, const string& formulaY,
    const int& maxIter, const int& dotsPerCell, const int& splitNum,
    const string& projectiveFormulaX, const string& projectiveFormulaY,
    const int& maxIterProjective, const int& splitNumProjective,
    const string& arcWeightFormula)
    : Localization(left, right, top, bot, formulaX, formulaY, maxIter, dotsPerCell, splitNum),
    ProjectiveLocalization(left, right, top, bot, formulaX, formulaY, maxIter, dotsPerCell, splitNum, projectiveFormulaX, projectiveFormulaY, maxIterProjective, splitNumProjective),
    Mapping(formulaX, formulaY, projectiveFormulaX, projectiveFormulaY, arcWeightFormula) {};

// Экстремальные циклы (минимальный и максимальный)
void MorseSpectrum::MorseSpectrumСalculation(unordered_map<int, unordered_set<int>>& mapGraph)
{
    minCircuits.clear();
    maxCircuits.clear();
    minCircuitsWeights.clear();
    maxCircuitsWeights.clear();

    const float
        FINDMAX = -1.0f,
        FINDMIN = 1.0f;

    // Если компонента длины 1, то она не учитывается и надо самому
    vector<vector<int>> _strongComponents = getStrongComponents(mapGraph);
    for (auto& SC : _strongComponents)
    {
        if (SC.size() == 1)
        {
            const float weight = getArcWeightForMap(SC[0], SC[0], 1.0f);

            minCircuits.push_back(SC);
            minCircuitsWeights.push_back(weight);

            maxCircuits.push_back(SC);
            maxCircuitsWeights.push_back(weight);

            SCorder.push_back(SC.size());
        }
    }
    _strongComponents.clear();

    unordered_map<int, unordered_set<int>> graph = getGraphWithoutSelfLoops(mapGraph);
    vector<vector<int>> strongComponents = getStrongComponents(graph);

    // Рассчитываем вес ребер.
    for (auto& SC : strongComponents)
    {
        for (auto& cell : SC)
        {
            cellToWeight[cell] = getArcWeightForMap(cell, *mapGraph[cell].begin(), 1.0f);
        }
    }

    // Надо сравнить с характеристиками петель графа
    for (auto& SC : strongComponents)
    {
        unordered_map<int, unordered_set<int>> reducedGraph = getReducedGraph(graph, SC);
        unordered_map<int, int> circuit;

        vector<int> minCircuit;
        vector<int> maxCircuit;

        float minWeight;
        float maxWeight;

        // Максимальная и минимальная петля
        vector<int>
            minSelfLoop,
            maxSelfLoop;
        float minSelfLoopWeight,
            maxSelfLoopWeight;
        for (auto& cell : SC)
        {
            if (inContainer(cell, mapGraph[cell]))
            {
                const float weight = getArcWeight(cell, cell, FINDMIN);

                if (!minSelfLoop.size() || weight < minSelfLoopWeight)
                {
                    minSelfLoopWeight = weight;
                    minSelfLoop = { cell };
                }
                if (!maxSelfLoop.size() || weight > maxSelfLoopWeight)
                {
                    maxSelfLoopWeight = weight;
                    maxSelfLoop = { cell };
                }
            }
        }

        // min
        circuit = getStartCircuit(reducedGraph, FINDMIN);

        runAlgorithmForConstructingTreeAndOptimalContour(circuit, FINDMIN, reducedGraph);
        
        for (auto& keyValue : circuit)
        {
            minCircuit.push_back(keyValue.first);
        }

        // Сравнение с петлями
        minWeight = getCircuitWeight(circuit, FINDMIN);
        if (minSelfLoop.size() && minWeight > minSelfLoopWeight)
        {
            minWeight = minSelfLoopWeight;
            minCircuit = minSelfLoop;
        }

        minCircuits.push_back(minCircuit);
        minCircuitsWeights.push_back(minWeight);

        // max
        circuit = getStartCircuit(reducedGraph, FINDMAX);

        runAlgorithmForConstructingTreeAndOptimalContour(circuit, FINDMAX, reducedGraph);
        
        for (auto& keyValue : circuit)
        {
            maxCircuit.push_back(keyValue.first);
        }

        // Сравнение с петлями
        maxWeight = getCircuitWeight(circuit, FINDMIN);
        if (minSelfLoop.size() && maxWeight < maxSelfLoopWeight)
        {
            maxWeight = maxSelfLoopWeight;
            maxCircuit = maxSelfLoop;
        }

        maxCircuits.push_back(maxCircuit);
        maxCircuitsWeights.push_back(maxWeight);

        SCorder.push_back(SC.size());
    }

    cellToWeight.clear();
}

void MorseSpectrum::getArcStartXYMAPX(float& xW, float& yW, float& mapVecX, float& mapVecY, const int& map, const int& linkedMap)
{
    const int cell = getCellFromMap(map);

    float leftX, topY;
    getLeftTopXY(leftX, topY, cell);

    // Центр ячейки
    const float
        x = leftX + getCellSizeX() / 2,
        y = topY - getCellSizeY() / 2;

    // Центр кусочка отрезка
    const float
        leftMapX = getLeftMapX(map),
        mapX = leftMapX + getMapSegmentSize() / 2;

    const int numInCell = getNumInCell(map);

    const float
        vecX = (numInCell <= getPatrsNumInMap()) ? (1.0f) : (mapX),
        vecY = (numInCell <= getPatrsNumInMap()) ? (mapX) : (1.0f);

    xW = x;
    yW = y;
    mapVecX = vecX;
    mapVecY = vecY;
}

float MorseSpectrum::getArcWeightForMap(const int& vertex, const int& linkedVertex, const float& multiplier)
{
    float x, y, mapVecX, mapVecY;
    getArcStartXYMAPX(x, y, mapVecX, mapVecY, vertex, linkedVertex);
    return multiplier * calculateArcWeight(x, y, mapVecX, mapVecY);
}

float MorseSpectrum::getArcWeight(const int& vertex, const int& linkedVertex, const float& multiplier)
{
    return multiplier * cellToWeight[vertex];
}

float MorseSpectrum::getCircuitWeight(unordered_map<int, int>& circuit, const float& multiplier)
{
    float weight = 0;
    for (auto& keyValue : circuit)
    {
        weight += getArcWeight(keyValue.first, keyValue.second, multiplier);
    }
    return weight / circuit.size();
}

// Поиск начального контура (Процедура И.В. Романовского)
unordered_map<int, int> MorseSpectrum::getStartCircuit(unordered_map<int, unordered_set<int>>& graph, const int& multiplier)
{
    // 1 Для каждой вершины выбрать одну выходящую дугу с минимальным весом (N_s - множество этих дуг)
    unordered_map<int, int> N_s;

    for (auto& keyValue : graph)
    {
        int bestLinkedVertex = *graph[keyValue.first].begin();
        float lowestWeight = getArcWeight(keyValue.first, bestLinkedVertex, multiplier);

        for (auto& linkedVertex : keyValue.second)
        {
            float arcWeight = getArcWeight(keyValue.first, linkedVertex, multiplier);

            if (arcWeight < lowestWeight)
            {
                bestLinkedVertex = linkedVertex;
                lowestWeight = arcWeight;
            }
        }

        N_s[keyValue.first] = bestLinkedVertex;
    }

    // 2 Для каждой вершины подсчитать число входящих в неё отобранных дуг
    unordered_map<int, int> vertexPower;
    for (auto& keyValue : N_s)
    {
        ++vertexPower[keyValue.second];
    }

    // 3 Составить список вершин с нулевой степенью
    vector<int> zeroPower;

    for (auto& keyValue : graph)
    {
        //if (!inContainer(keyValue.first, vertexPower))
        if (vertexPower[keyValue.first] == 0)
        {
            zeroPower.push_back(keyValue.first);
        }
    }

    // 4 Пока список не пуст, выполнять следующие действия
    while (!zeroPower.empty())
    {
        // а Исключить из списка первую вершину i_1 (какая разница первая или последняя)
        const int i_1 = zeroPower.back();
        zeroPower.pop_back();

        // b Исключить ребро с началом в i_1 и концом в i_2 из N_s
        const int i_2 = N_s[i_1];
        N_s.erase(i_1);

        // c Уменьшить на единицу степень вершины i_2, если эта степень стала нулевой, то включить i_2 в список
        --vertexPower[i_2];
        if (vertexPower[i_2] == 0)
        {
            zeroPower.push_back(i_2);
        }
    }

    // 5 Теперь дуги, входящие в N_s, образуют изолированные контуры. Нужно выбрать контур с минимальной характеристикой из них.
    unordered_set<int> visited;
    vector<unordered_map<int, int>> circuits;

    for (auto& keyValue : N_s)
    {
        if (!inContainer(keyValue.first, visited))
        {
            unordered_map<int, int> circuit;

            stack<int> _stack;
            _stack.push(keyValue.first);
            while (!_stack.empty())
            {
                const int vertex = _stack.top();
                _stack.pop();

                visited.insert(vertex);

                const int linkedVertex = N_s[vertex];

                circuit[vertex] = linkedVertex;

                if (linkedVertex != keyValue.first)
                {
                    _stack.push(linkedVertex);
                }
            }

            circuits.push_back(circuit);
        }
    }
    visited.clear();

    unordered_map<int, int> minCircuit;
    float minWeight = 0;

    minCircuit = circuits[0];
    minWeight = getCircuitWeight(minCircuit, multiplier);

    for (auto& circuit : circuits)
    {
        const float weight = getCircuitWeight(circuit, multiplier);

        if (weight < minWeight)
        {
            minCircuit = circuit;
            minWeight = weight;
        }
    }
    return minCircuit;
}

void MorseSpectrum::runAlgorithmForConstructingTreeAndOptimalContour(unordered_map<int, int>& circuit, const int& multiplier, unordered_map<int, unordered_set<int>>& graph)
{
    bool newCircuitFound = false;
    for (; ; )
    {
        unordered_set<int> M_c;
        for (auto& keyValue : circuit)
        {
            M_c.insert(keyValue.first);
        }

        const float z = getCircuitWeight(circuit, multiplier);

        const int i_0 = circuit.begin()->first;

        unordered_map<int, float> v{ {i_0, 0.0f} };

        stack<int> _stack;
        _stack.push(i_0);
        while (!_stack.empty())
        {
            const int vertex = _stack.top();
            _stack.pop();

            const int linkedVertex = circuit[vertex];

            v[linkedVertex] = v[vertex] + getArcWeight(vertex, linkedVertex, multiplier) - z;

            if (linkedVertex != i_0)
            {
                _stack.push(linkedVertex);
            }
        }

        int i_0_start;  // i_0_start -> i_0
        unordered_map<int, unordered_set<int>> tree;
        unordered_map<int, int> reversedTree;
        for (auto& keyValue : circuit)
        {
            if (keyValue.second != i_0)
            {
                tree[keyValue.first].insert(keyValue.second);
                reversedTree[keyValue.second] = keyValue.first;
            }
            else
            {
                i_0_start = keyValue.first;
            }
        }

        deque<int> M_1;
        for (auto& keyValue : circuit)
        {
            M_1.push_back(keyValue.first);
        }

        unordered_set<int> M_0;
        unordered_set<int> M_2;
        for (auto& keyValue : graph)
        {
            if (!inContainer(keyValue.first, M_c))
            {
                M_2.insert(keyValue.first);
            }
        }

        while (!M_1.empty())
        {
            const int i_1 = M_1.front();
            M_1.pop_front();

            M_0.insert(i_1);

            for (auto& i_2 : graph[i_1])
            {
                const float w = v[i_1] + getArcWeight(i_1, i_2, multiplier) - z;

                if (inContainer(i_2, M_2))
                {
                    M_2.erase(i_2);
                    M_1.push_back(i_2);

                    v[i_2] = w;

                    tree[i_1].insert(i_2);
                    reversedTree[i_2] = i_1;
                }

                //if ((inContainer(i_2, M_0) || inContainerSpecial(i_2, M_1)) && (v[i_2] - w > 0.0f))
                else if (v[i_2] - w > 0.01f)
                {
                    bool i2Beforei1 = false;
                    stack<int> _stack;
                    _stack.push(i_1);
                    while (!_stack.empty())
                    {
                        const int vertex = _stack.top();
                        _stack.pop();

                        const int linkedVertex = reversedTree[vertex];

                        if (linkedVertex != 0)
                        {
                            if (linkedVertex == i_2)
                            {
                                i2Beforei1 = true;
                            }
                            else
                            {
                                _stack.push(linkedVertex);
                            }
                        }
                    }

                    if (i2Beforei1 || inContainer(i_2, M_c))
                    {
                        unordered_map<int, int> newCircuit;

                        tree[i_0_start].insert(i_0);
                        reversedTree[i_0] = i_0_start;

                        tree[i_1].insert(i_2);
                        reversedTree[i_2] = i_1;

                        stack<int> _stack;
                        _stack.push(i_1);
                        while (!_stack.empty())
                        {
                            const int vertex = _stack.top();
                            _stack.pop();

                            const int linkedVertex = reversedTree[vertex];

                            if (linkedVertex != 0)
                            {
                                newCircuit[linkedVertex] = vertex;

                                if (linkedVertex != i_1)
                                {
                                    _stack.push(linkedVertex);
                                }
                            }
                        }

                        circuit = newCircuit;

                        newCircuitFound = true;
                        break;
                    }

                    const int i_2_start = reversedTree[i_2];
                    reversedTree.erase(i_2);
                    tree[i_2_start].erase(i_2);

                    tree[i_1].insert(i_2);
                    reversedTree[i_2] = i_1;

                    if (inContainer(i_2, M_0))
                    {
                        M_0.erase(i_2);
                    }
                }
            }

            if (newCircuitFound)
            {
                break;
            }
        }
        if (newCircuitFound)
        {
            newCircuitFound = false;
            continue;
        }

        break;
    }
}

vector<vector<int>>& MorseSpectrum::getMinCircuits()
{
    return minCircuits;
}

vector<vector<int>>& MorseSpectrum::getMaxCircuits()
{
    return maxCircuits;
}

vector<float>& MorseSpectrum::getMinCircuitsWeights()
{
    return minCircuitsWeights;
}

vector<float>& MorseSpectrum::getMaxCircuitsWeights()
{
    return maxCircuitsWeights;
}

vector<int>& MorseSpectrum::getSCorder()
{
    return SCorder;
}
