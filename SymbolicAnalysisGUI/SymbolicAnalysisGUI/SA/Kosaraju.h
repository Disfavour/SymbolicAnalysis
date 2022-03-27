#pragma once
#include "Utility.h"


// Алгоритм Косарайю - алгоритм поиска компонент сильной связности в ориентированном графе.
class Kosaraju : virtual public Utility
{
private:
	unordered_set<int> visited;
	unordered_set<int> visitedTwice;

	void numerationDFS(const int& startVertex, unordered_map<int, unordered_set<int>>& graph, stack<int>& numeration);
	vector<int> DFS(const int& startVertex, unordered_map<int, unordered_set<int>>& reversedGraph);
	
public:
	vector<vector<int>> getStrongComponents(unordered_map<int, unordered_set<int>>& graph);
};
