#pragma once
#include "ProjectiveLocalization.h"


// Ñïåêòð Ìîðñà
class MorseSpectrum : public ProjectiveLocalization
{
private:
	vector<vector<int>> minCircuits, maxCircuits;
	vector<float> minCircuitsWeights, maxCircuitsWeights;

	unordered_map<int, float> cellToWeight;

	// Strong Component sizes in order
	vector<int> SCorder;

	unordered_map<int, int> getStartCircuit(unordered_map<int, unordered_set<int>>& graph, const int& multiplier);
	void runAlgorithmForConstructingTreeAndOptimalContour(unordered_map<int, int>& circuit, const int& multiplier, unordered_map<int, unordered_set<int>>& graph);

	void getArcStartXYMAPX(float& xW, float& yW, float& mapVecX, float& mapVecY, const int& map, const int& linkedMap);
	float getArcWeight(const int& vertex, const int& linkedVertex, const float& multiplier);
	// Äëÿ cellToWeight
	float getArcWeightForMap(const int& vertex, const int& linkedVertex, const float& multiplier);
	float getCircuitWeight(unordered_map<int, int>& circuit, const float& multiplier);

public:
	MorseSpectrum(const float& left, const float& right, const float& top, const float& bot,
		const string& formulaX, const string& formulaY,
		const int& maxIter, const int& dotsPerCell, const int& splitNum,
		const string& projectiveFormulaX, const string& projectiveFormulaY,
		const int& maxIterProjective, const int& splitNumProjective,
		const string& arcWeightFormula);

	void MorseSpectrumÑalculation(unordered_map<int, unordered_set<int>>& mapGraph);

	vector<vector<int>>& getMinCircuits();
	vector<vector<int>>& getMaxCircuits();

	vector<float>& getMinCircuitsWeights();
	vector<float>& getMaxCircuitsWeights();

	vector<int>& getSCorder();
};
