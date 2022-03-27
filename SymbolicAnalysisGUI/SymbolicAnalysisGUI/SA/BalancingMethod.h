#pragma once
#include "Utility.h"


class Balancing : virtual public Utility
{
private:
	float getSumOfMatrixElements(const unordered_map<int, vector<float>>& matrix);

	// ћера -  сумма элементов строки дл€ каждой вершины
	unordered_map<int, float> calculateInvariantMeasureFromMatrix(const unordered_map<int, vector<float>>& matrix);

	void normalizeMatrix(unordered_map<int, vector<float>>& matrix, const float& sum);

	// ƒелим меру на площадь €чейки - получаем плотность
	unordered_map<int, float> getMeasureDensity(unordered_map<int, float>& invariantMeasure, const float& cellArea);

public:
	unordered_map<int, float> BalancingMethod(const unordered_map<int, unordered_set<int>>& graph, const float& eps, const float& cellArea);
};
