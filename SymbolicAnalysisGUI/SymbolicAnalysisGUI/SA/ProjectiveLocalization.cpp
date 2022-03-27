#include "ProjectiveLocalization.h"


ProjectiveLocalization::ProjectiveLocalization(const float& left, const float& right, const float& top, const float& bot,
    const string& formulaX, const string& formulaY,
    const int& maxIter, const int& dotsPerCell, const int& splitNum,
    const string& projectiveFormulaX, const string& projectiveFormulaY,
    const int& maxIterProjective, const int& splitNumProjective)
    : Localization(left, right, top, bot, formulaX, formulaY, maxIter, dotsPerCell, splitNum),
    maxIter(maxIterProjective), dotsPerCell(dotsPerCell), mapsInCell(2), splitNum(splitNumProjective), mapSize(2.0f),
    Mapping(formulaX, formulaY, projectiveFormulaX, projectiveFormulaY) {};

void ProjectiveLocalization::LocalizationOfTheChainRecurrentSetInProjectiveSpace(unordered_map<int, unordered_set<int>>& baseGraph)
{
    strongComponents.clear();
    graph.clear();

    // Создаем по 2 (mapsInCell) отрезочка для каждой ячейки
    vector<int> maps;
    for (const auto& keyValue : baseGraph)
    {
        for (int i = 0; i < mapsInCell; ++i)
        {
            maps.push_back(keyValue.first * mapsInCell - i);
        }
    }

    partsInMap = 1;
    segmentSize = mapSize;
    deltaSegmentSize = segmentSize / (dotsPerCell * dotsPerCell - 1);

    for (int iter = 1; iter <= maxIter; ++iter)
    {
        maps = getMaps(maps);

        partsInMap *= splitNum;
        segmentSize /= splitNum;
        deltaSegmentSize /= splitNum;

        graph = getGraphP(baseGraph, maps);

        maps.clear();

        strongComponents = getStrongComponents(graph);

        for (const auto& strongComponent : strongComponents)
        {
            maps.insert(maps.end(), strongComponent.begin(), strongComponent.end());
        }

        if (iter < maxIter)
        {
            graph.clear();
            strongComponents.clear();
        }
        else
        {
            graph = getReducedGraph(graph, maps);

            maps.clear();
            maps.shrink_to_fit();
        }
    }
}

vector<int> ProjectiveLocalization::getMaps(const vector<int>& maps)
{
    vector<int> newMaps;
    for (auto& map : maps)
    {
        for (int i = 0; i < splitNum; ++i)
        {
            newMaps.push_back(map * splitNum - i);
        }
    }
    return newMaps;
}

unordered_map<int, unordered_set<int>> ProjectiveLocalization::getGraphP(unordered_map<int, unordered_set<int>>& baseGraph, vector<int>& maps)
{
    unordered_map<int, unordered_set<int>> graph;

    for (auto& map : maps)
    {
        const int cell = getCellFromMap(map);

        float leftX, topY;
        getLeftTopXY(leftX, topY, cell);

        // Центр ячейки
        const float
            x = leftX + getCellSizeX() / 2,
            y = topY - getCellSizeY() / 2;

        const int numInCell = getNumInCell(map);
        const float
            leftMapX = getLeftMapX(map),
            rightMapX = leftMapX + segmentSize + deltaSegmentSize / 2;

        for (float mapX = leftMapX; mapX < rightMapX; mapX += deltaSegmentSize)
        {
            // Если в первой карте, то у вектора x = 1. Иначе, y = 1.
            const float
                vecX = (numInCell <= partsInMap) ? (1.0f) : (mapX),
                vecY = (numInCell <= partsInMap) ? (mapX) : (1.0f);

            float
                newVecX,
                newVecY;

            calculateProjectiveMapping(newVecX, newVecY, x, y, vecX, vecY);

            int newMapNumPart;

            // 1-ая карта
            if (abs(newVecX) >= abs(newVecY))
            {
                newVecY /= newVecX;
                newVecX = 1.f;

                newMapNumPart = (int)((newVecY + 1.f) / segmentSize) + 1;
            }
            // 2-ая карта
            else
            {
                newVecX /= newVecY;
                newVecY = 1.f;

                newMapNumPart = partsInMap + (int)((newVecX + 1.f) / segmentSize) + 1;
            }

            for (auto& linkedCell : baseGraph[cell])
            {
                const int newMapNum = (linkedCell - 1) * mapsInCell * partsInMap + newMapNumPart;
                graph[map].insert(newMapNum);
            }
        }
    }

    return graph;
}

const int ProjectiveLocalization::getCellFromMap(const int& map)
{
    return (map - 1) / (mapsInCell * partsInMap) + 1;
}

const int ProjectiveLocalization::getNumInCell(const int& map)
{
    return (map - 1) % (mapsInCell * partsInMap) + 1;
}

const int ProjectiveLocalization::getNumInMap(const int& map)
{
    return (map - 1) % partsInMap + 1;
}

const float ProjectiveLocalization::getLeftMapX(const int& map)
{
    return (getNumInMap(map) - 1) * segmentSize - mapSize / 2;
}

const float& ProjectiveLocalization::getMapSegmentSize()
{
    return segmentSize;
}

const int& ProjectiveLocalization::getPatrsNumInMap()
{
    return partsInMap;
}

vector<vector<int>>& ProjectiveLocalization::getSCsP()
{
    return strongComponents;
}

unordered_map<int, unordered_set<int>>& ProjectiveLocalization::getGraphP()
{
    return graph;
}
