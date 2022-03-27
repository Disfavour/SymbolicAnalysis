#include "JohnsonAlgorithm.h"


unordered_map<int, unordered_set<int>> JohnsonAlgorithm::longestElementaryCycleInDirectedGraph(unordered_map<int, unordered_set<int>>& graph)
{
    vector<int> maxCycle;
    unordered_map<int, unordered_set<int>> graphForCycle;

    // Для возможного переиспользования
    blockedSet.clear();
    blockedMap.clear();
    _stack = stack<int>();

    maxCycle = Johnson(graph);

    // Граф для максимального цикла
    for (int i = 0; i < maxCycle.size() - 1; ++i)
    {
        graphForCycle[maxCycle[i]].insert(maxCycle[i + 1]);
    }
    graphForCycle[maxCycle[maxCycle.size() - 1]].insert(maxCycle[0]);

    graphForCycle = getReversedGraph(graphForCycle);

    return graphForCycle;
}

vector<int> JohnsonAlgorithm::Johnson(unordered_map<int, unordered_set<int>>& graph)
{
    vector<int> maxCycle;
    vector<vector<int>> strongComponents = getStrongComponents(graph);
    unordered_map<int, unordered_set<int>> curGraph = graph;

    int maxSCsize = 0;
    for (auto& SC : strongComponents)
    {
        if (SC.size() > maxSCsize)
        {
            maxSCsize = SC.size();
        }
    }

    int iterWithChange = 0;
    const int smallTolerance = 5;
    const int neededPart = 0.25f * maxSCsize;

    for (int i = 1; strongComponents.size() > 0; ++i)
    {
        if ((maxCycle.size() > neededPart && i - iterWithChange > smallTolerance))
        {
            break;
        }

        // Рассматриваем наибольшую компоненту сильной связности
        vector<int> longestSC;
        for (auto& strongComponent : strongComponents)
        {
            if (longestSC.size() < strongComponent.size())
            {
                longestSC = strongComponent;
            }
        }

        strongComponents.clear();

        if (maxCycle.size() > longestSC.size())
        {
            break;
        }

        curGraph = getReducedGraph(curGraph, longestSC);

        const int startVertex = longestSC[0];

        vector<int> cycle = DFS(curGraph, startVertex);

        if (cycle.size() > maxCycle.size())
        {
            maxCycle = cycle;
            iterWithChange = i;
        }

        blockedSet.clear();
        blockedMap.clear();
        _stack = stack<int>();

        curGraph.erase(startVertex);
        for (auto& keyValue : curGraph)
        {
            keyValue.second.erase(startVertex);
        }

        strongComponents = getStrongComponents(curGraph);
    }

    return maxCycle;
}

vector<int> JohnsonAlgorithm::DFS(unordered_map<int, unordered_set<int>>& graph, const int& startVertex)
{
    vector<int> cycle, maxCycle;

    unordered_set<int> visited;

    stack<int> stackDFS;
    stackDFS.push(startVertex);

    while (!stackDFS.empty())
    {
        const int curVertex = stackDFS.top();

        if (!inContainer(curVertex, visited))
        {
            _stack.push(curVertex);
            blockedSet.insert(curVertex);

            visited.insert(curVertex);

            for (auto& linkedVertex : graph[curVertex])
            {
                if (linkedVertex == startVertex)
                {
                    cycle = getCycleFromStack(_stack);

                    if (cycle.size() > maxCycle.size())
                    {
                        maxCycle = cycle;
                    }

                    return maxCycle;
                }
                else if (!inContainer(linkedVertex, blockedSet))
                {
                    stackDFS.push(linkedVertex);
                }
            }
        }
        else
        {
            // Если цикл не найден, то убираем из стека и пишем в мапу
            if (!inContainer(curVertex, cycle))
            {
                for (auto& linkedVertex : graph[curVertex])
                {
                    // Они могут повторятся
                    blockedMap[linkedVertex].insert(curVertex);
                }
            }
            else
            {
                // Иначе убираем везде и еще рекурсивно мапу
                blockedSet.erase(curVertex);
                emptyMapRecursively(curVertex);
            }
            _stack.pop();
            stackDFS.pop();
            visited.erase(curVertex);
        }
    }

    return maxCycle;
}

vector<int> JohnsonAlgorithm::getCycleFromStack(stack<int>& stack)
{
    vector<int> cycle;

    while (!stack.empty())
    {
        cycle.push_back(stack.top());
        stack.pop();
    }

    return cycle;
}

void JohnsonAlgorithm::emptyMapRecursively(const int& vertex)
{
    if (inContainer(vertex, blockedMap))
    {
        vector<int> dependentVertexes(blockedMap[vertex].begin(), blockedMap[vertex].end());
        blockedMap.erase(vertex);

        for (auto& dependentVertex : dependentVertexes)
        {
            blockedSet.erase(dependentVertex);
        }

        for (auto& dependentVertex : dependentVertexes)
        {
            emptyMapRecursively(dependentVertex);
        }
    }
}
