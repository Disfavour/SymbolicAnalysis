#include "Localization.h"


Localization::Localization(const float& left, const float& right, const float& top, const float& bot,
    const string& formulaX, const string& formulaY,
    const int& maxIter, const int& dotsPerCell, const int& splitNum)
    : Area(left, right, top, bot), Mapping(formulaX, formulaY), splitNum(splitNum), dotsPerCell(dotsPerCell), maxIter(maxIter) {}

void Localization::LocalizationOfTheChainRecurrentSet()
{
    graph.clear();
    strongComponents.clear();

    vector<int> cells{ 1 };

	partsInRow = 1;
    cellSizeX = sizeX();
    cellSizeY = sizeY();
    deltaX = cellSizeX / (dotsPerCell - 1);
    deltaY = cellSizeY / (dotsPerCell - 1);

	for (int iter = 1; iter <= maxIter; ++iter)
	{
        cells = getCells(cells);
        
        partsInRow *= splitNum;
        cellSizeX /= splitNum;
        cellSizeY /= splitNum;
        deltaX /= splitNum;
        deltaY /= splitNum;
        
        graph = getGraph(cells);

        cells.clear();

        strongComponents = getStrongComponents(graph);

        for (const auto& strongComponent : strongComponents)
        {
            cells.insert(cells.end(), strongComponent.begin(), strongComponent.end());
        }

        if (iter < maxIter)
        {
            graph.clear();
            strongComponents.clear();
        }
        else
        {
            graph = getReducedGraph(graph, cells);

            cells.clear();
            cells.shrink_to_fit();
        }
	}
}

vector<int> Localization::getCells(const vector<int>& cells)
{
    vector<int> newCells;
    const int newPartsNumRow = partsInRow * splitNum;

    for (const int& cell : cells)
    {
        int newLeftTopCell = (cell - 1) / partsInRow * newPartsNumRow * splitNum + (cell - 1) % partsInRow * splitNum + 1;

        for (int i = 0; i < splitNum; i++)
        {
            for (int j = 0; j < splitNum; j++)
            {
                newCells.push_back(newLeftTopCell + i * newPartsNumRow + j);
            }
        }
    }

    return newCells;
}

unordered_map<int, unordered_set<int>> Localization::getGraph(const vector<int>& cells)
{
    unordered_map<int, unordered_set<int>> graph;

    for (const int& cell : cells)
    {
        float leftX, topY;
        getLeftTopXY(leftX, topY, cell);

        // ѕоловины дельт нужны потому, что float-у становитс€ плохо при маленьких значени€х.
        const float
            rightX = leftX + cellSizeX + deltaX / 2,
            botY = topY - cellSizeY - deltaY / 2;
        
        for (float y = topY; y > botY; y -= deltaY)
        {
            for (float x = leftX; x < rightX; x += deltaX)
            {
                float newX, newY;
                calculateMapping(newX, newY, x, y);

                if (inArea(newX, newY))
                {
                    graph[cell].insert(getCellFromXY(newX, newY));
                }
            }
        }
    }

    return graph;
}

void Localization::getLeftTopXY(float& x, float& y, const int& cell)
{
    x = left() + (cell - 1) % partsInRow * cellSizeX;
    y = top() - (cell - 1) / partsInRow * cellSizeY;
}

int Localization::getCellFromXY(const float& x, const float& y)
{
    return (int)((top() - y) / cellSizeY) * partsInRow + (int)((x - left()) / cellSizeX) + 1;
}

const float& Localization::getCellSizeX() const
{
    return cellSizeX;
}

const float& Localization::getCellSizeY() const
{
    return cellSizeY;
}

unordered_map<int, unordered_set<int>>& Localization::getGraph()
{
    return graph;
}

vector<vector<int>>& Localization::getSCs()
{
    return strongComponents;
}
