#include "Kosaraju.h"


vector<vector<int>> Kosaraju::getStrongComponents(unordered_map<int, unordered_set<int>>& graph)
{
    vector<vector<int>> strongComponents;
    stack<int> numeration;

    for (const auto& keyValue : graph)
    {
        if (!(inContainer(keyValue.first, visited)))
        {
            numerationDFS(keyValue.first, graph, numeration);
        }
    }
    visited.clear();
    visitedTwice.clear();

    unordered_map<int, unordered_set<int>> reversedGraph = getReversedGraph(graph);

    while (!numeration.empty())
    {
        const int vertex = numeration.top();
        numeration.pop();

        if (!(inContainer(vertex, visited)))
        {
            vector<int> strongComponent = DFS(vertex, reversedGraph);

            if (strongComponent.size() == 1 && inContainer(strongComponent[0], graph) && inContainer(strongComponent[0], graph[strongComponent[0]]))
            {
                strongComponents.push_back(strongComponent);
            }
            else if (strongComponent.size() > 1)
            {
                strongComponents.push_back(strongComponent);
            }
        }
    }
    visited.clear();
    visitedTwice.clear();

    return strongComponents;
}

void Kosaraju::numerationDFS(const int& startVertex, unordered_map<int, unordered_set<int>>& graph, stack<int>& numeration)
{
    stack<int> stackDFS;
    stackDFS.push(startVertex);

    while (!stackDFS.empty())
    {
        const int curVertex = stackDFS.top();

        if (!(inContainer(curVertex, visited)))
        {
            visited.insert(curVertex);

            if (inContainer(curVertex, graph))
            {
                for (auto& linkedCell : graph[curVertex])
                {
                    if (!(inContainer(linkedCell, visited)))
                    {
                        stackDFS.push(linkedCell);
                    }
                }
            }
        }
        else
        {
            if (!inContainer(curVertex, visitedTwice))
            {
                visitedTwice.insert(curVertex);
                stackDFS.pop();
                numeration.push(curVertex);
            }
            else
            {
                stackDFS.pop();
            }
        }
    }
}

vector<int> Kosaraju::DFS(const int& startVertex, unordered_map<int, unordered_set<int>>& reversedGraph)
{
    vector<int> strongComponent;
    stack<int> stackDFS;
    stackDFS.push(startVertex);

    while (!stackDFS.empty())
    {
        const int curVertex = stackDFS.top();

        if (!(inContainer(curVertex, visited)))
        {
            visited.insert(curVertex);

            if (inContainer(curVertex, reversedGraph))
            {
                for (auto& linkedCell : reversedGraph[curVertex])
                {
                    if (!(inContainer(linkedCell, visited)))
                    {
                        stackDFS.push(linkedCell);
                    }
                }
            }
        }
        else
        {
            if (!inContainer(curVertex, visitedTwice))
            {
                stackDFS.pop();
                visitedTwice.insert(curVertex);
                strongComponent.push_back(curVertex);
            }
            else
            {
                stackDFS.pop();
            }
        }
    }
    return strongComponent;
}
