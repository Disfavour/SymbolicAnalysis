#pragma once
#include "Localization.h"


// Ёкстремальные циклы (минимальный и максимальный)
class RomanovskyAlgorithm : virtual public Localization
{
private:
	vector<vector<int>> minCircuits, maxCircuits;
	vector<float> minCircuitsWeights, maxCircuitsWeights;

	unordered_map<int, float> cellToWeight;

	// Strong Component sizes in order
	vector<int> SCorder;

	unordered_map<int, int> getStartCircuit(unordered_map<int, unordered_set<int>>& graph, const int& multiplier);
	void runAlgorithmForConstructingTreeAndOptimalContour(unordered_map<int, int>& circuit, const int& multiplier, unordered_map<int, unordered_set<int>>& graph);

	void getArcStartXY(float& xW, float& yW, const int& vertex, const int& linkedVertex);
	float getArcWeight(const int& vertex, const int& linkedVertex, const float& multiplier);
	// ƒл€ cellToWeight
	float getArcWeightForMap(const int& vertex, const int& linkedVertex, const float& multiplier);
	float getCircuitWeight(unordered_map<int, int>& circuit, const float& multiplier);

public:
	RomanovskyAlgorithm(const float& left, const float& right, const float& top, const float& bot,
		const string& formulaX, const string& formulaY,
		const int& maxIter, const int& dotsPerCell, const int& splitNum,
		const string& arcWeightFormula);

	void RomanovskyAlgorithmCalculation(unordered_map<int, unordered_set<int>>& baseGraph);

	vector<vector<int>>& getMinCircuits();
	vector<vector<int>>& getMaxCircuits();

	vector<float>& getMinCircuitsWeights();
	vector<float>& getMaxCircuitsWeights();

	vector<int>& getSCorder();
};

