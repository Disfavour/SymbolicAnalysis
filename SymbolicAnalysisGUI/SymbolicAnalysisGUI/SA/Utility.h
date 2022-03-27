#pragma once
#include <time.h>
#include <chrono>
#include <random>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <deque>
using namespace std;


class Utility
{
protected:
	// Минимум 1 лишний цвет гарантируется
	vector<vector<float>> getDifferentColors(const int& colorsNum);
	
	template <class Container>
	bool inContainer(const int& item, const Container& container);

	// Превращает в множество и производит поиск
	template <class Container>
	bool inContainerSpecial(const int& item, const Container& container);

	bool inContainer(const int& item, const vector<int>& container);

	bool inContainer(const int& item, const deque<int>& container);

	unordered_map<int, unordered_set<int>> getReducedGraph(unordered_map<int, unordered_set<int>>& graph, const vector<int>& cells);

	unordered_map<int, unordered_set<int>> getReversedGraph(const unordered_map<int, unordered_set<int>>& graph);

	unordered_map<int, unordered_set<int>> getGraphWithoutSelfLoops(unordered_map<int, unordered_set<int>>& graph);
};
