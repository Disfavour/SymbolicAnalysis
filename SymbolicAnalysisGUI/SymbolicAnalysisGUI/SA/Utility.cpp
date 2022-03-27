#include "Utility.h"


vector<vector<float>> Utility::getDifferentColors(const int& colorsNum)
{
    vector<vector<float>> colors;

    const float
        minColor = 0.3f,
        colorSpace = 1.0f - minColor;

    const int colorParts = (int)pow(colorsNum, 1.0f / 3.0f) + 1;
    const float deltaColor = colorSpace / colorParts;

    const float endColor = 1 - deltaColor / 2;

    for (float i = minColor; i < endColor; i += deltaColor)
    {
        for (float j = minColor; j < endColor; j += deltaColor)
        {
            for (float k = minColor; k < endColor; k += deltaColor)
            {
                //vector<float> curColor{ i, j, k };
                colors.push_back({ i, j, k });
            }
        }
    }
    unsigned int seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(colors.begin(), colors.end(), default_random_engine(seed));

    return colors;
}

template<class Container>
inline bool Utility::inContainer(const int& item, const Container& container)
{
    return container.find(item) != container.end();
}

template<class Container>
bool Utility::inContainerSpecial(const int& item, const Container& container)
{
    unordered_set<int> uniq(container.begin(), container.end());

    return inContainer(item, uniq);
}

bool Utility::inContainer(const int& item, const vector<int>& container)
{
    return inContainerSpecial(item, container);
}

bool Utility::inContainer(const int& item, const deque<int>& container)
{
    return inContainerSpecial(item, container);
}

unordered_map<int, unordered_set<int>> Utility::getReducedGraph(unordered_map<int, unordered_set<int>>& graph, const vector<int>& cells)
{
    unordered_set<int> uniq(cells.begin(), cells.end());

    unordered_map<int, unordered_set<int>> newGraph;

    for (auto& vertex : cells)
    {
        if (inContainer(vertex, graph))
        {
            for (auto& linkedVertex : graph[vertex])
            {
                if (inContainer(linkedVertex, uniq))
                {
                    newGraph[vertex].insert(linkedVertex);
                }
            }
        }
    }

    return newGraph;
}

unordered_map<int, unordered_set<int>> Utility::getReversedGraph(const unordered_map<int, unordered_set<int>>& graph)
{
    unordered_map<int, unordered_set<int>> reversedGraph;

    for (auto& keyValue : graph)
    {
        for (auto& linkedVertex : keyValue.second)
        {
            reversedGraph[linkedVertex].insert(keyValue.first);
        }
    }
    return reversedGraph;
}

unordered_map<int, unordered_set<int>> Utility::getGraphWithoutSelfLoops(unordered_map<int, unordered_set<int>>& graph)
{
    unordered_map<int, unordered_set<int>> graphWithoutSelfLoops;
    for (auto& keyValue : graph)
    {
        for (auto& linkedCell : keyValue.second)
        {
            if (linkedCell != keyValue.first)
            {
                graphWithoutSelfLoops[keyValue.first].insert(linkedCell);
            }
        }
    }
    return graphWithoutSelfLoops;
}
