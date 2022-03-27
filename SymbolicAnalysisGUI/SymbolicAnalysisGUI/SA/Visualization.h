#pragma once
#include "../../freeGlut/GL/glut.h"
#include "../../freeGlut/GL/freeglut.h"
#include "SymbolicAnalysis.h"
using namespace std;

class Visualization
{
private:
	SymbolicAnalysis symbolicAnalysis;
	const int
		winSizeX,
		winSizeY;

	unordered_map<string, vector<string>> info;

	void invokeWindow(void (*display)(), void (*keyboard)(unsigned char, int, int));

public:
	Visualization(const float& left, const float& right, const float& top, const float& bot,
		const string& formulaX, const string& formulaY,
		const int& maxIter, const int& dotsPerCell, const int& splitNum,
		const float& eps,
		const string& projectiveFormulaX, const string& projectiveFormulaY,
		const int& maxIterProjective, const int& splitNumProjective,
		const string& arcWeightFormula);

	void Localization();
	void BalancingMethod();
	void JohnsonAlgorithm();
	void ProjectiveLocalization();
	void RomanovskyAlgorithm();
	void MorseSpectrum();

	void maxCycleInProjective();
	void maxCycleMorseSpectrum();

	unordered_map<string, vector<string>>& getInfo();
};

