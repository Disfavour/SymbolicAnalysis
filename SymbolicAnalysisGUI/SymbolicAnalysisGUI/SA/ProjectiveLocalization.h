#pragma once
#include "Localization.h"


class ProjectiveLocalization : virtual public Localization
{
private:
	// 2 отрезочка (карты) над каждой ячейкой
	const int mapsInCell;

	// Размер карты (отрезка) 2 [-1; 1]
	const float mapSize;

	const int
		splitNum,
		maxIter,
		dotsPerCell;

	int partsInMap;
	float
		segmentSize,
		deltaSegmentSize;

	vector<vector<int>> strongComponents;
	unordered_map<int, unordered_set<int>> graph;
	
	vector<int> getMaps(const vector<int>& maps);
	
	unordered_map<int, unordered_set<int>> getGraphP(unordered_map<int, unordered_set<int>>& baseGraph, vector<int>& maps);
	
	const int getNumInMap(const int& map);
	
protected:
	const int getCellFromMap(const int& map);
	const float getLeftMapX(const int& map);
	const int getNumInCell(const int& map);

	const float& getMapSegmentSize();
	const int& getPatrsNumInMap();

public:
	ProjectiveLocalization(const float& left, const float& right, const float& top, const float& bot,
		const string& formulaX, const string& formulaY,
		const int& maxIter, const int& dotsPerCell, const int& splitNum,
		const string& projectiveFormulaX, const string& projectiveFormulaY,
		const int& maxIterProjective, const int& splitNumProjective);

	void LocalizationOfTheChainRecurrentSetInProjectiveSpace(unordered_map<int, unordered_set<int>>& baseGraph);

	vector<vector<int>>& getSCsP();
	unordered_map<int, unordered_set<int>>& getGraphP();
};
