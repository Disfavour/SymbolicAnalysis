#pragma once
#include "Kosaraju.h"


// ����� �������� ����� ������������ ����� � ��������������� �����
class JohnsonAlgorithm : virtual public Kosaraju
{
private:
	unordered_set<int> blockedSet;
	unordered_map<int, unordered_set<int>> blockedMap;
	stack<int> _stack;

	vector<int> Johnson(unordered_map<int, unordered_set<int>>& graph);

	// ���������� ������������ ���� ����������
	vector<int> DFS(unordered_map<int, unordered_set<int>>& graph, const int& startVertex);

	vector<int> getCycleFromStack(stack<int>& stack);
	void emptyMapRecursively(const int& vertex);

public:
	unordered_map<int, unordered_set<int>> longestElementaryCycleInDirectedGraph(unordered_map<int, unordered_set<int>>& graph);
};
