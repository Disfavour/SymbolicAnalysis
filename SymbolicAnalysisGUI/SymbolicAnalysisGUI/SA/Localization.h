#pragma once
#include "Area.h"
#include "Kosaraju.h"
#include "Mapping.h"


// Ћокализаци€ цепно-рекуррентного множества
class Localization : virtual public Kosaraju, public Area, virtual public Mapping
{
private:
	const int maxIter, dotsPerCell, splitNum;
	int partsInRow;
	float
		cellSizeX,
		cellSizeY,
		deltaX,
		deltaY;

	unordered_map<int, unordered_set<int>> graph;
	vector<vector<int>> strongComponents;

	vector<int> getCells(const vector<int>& cells);
	unordered_map<int, unordered_set<int>> getGraph(const vector<int>& cells);

protected:
	int getCellFromXY(const float& x, const float& y);

public:
	Localization(const float& left, const float& right, const float& top, const float& bot,
		const string& formulaX, const string& formulaY,
		const int& maxIter, const int& dotsPerCell, const int& splitNum);

	void LocalizationOfTheChainRecurrentSet();

	unordered_map<int, unordered_set<int>>& getGraph();
	vector<vector<int>>& getSCs();

	// Ћева€ верхн€€ точка €чейки
	void getLeftTopXY(float& x, float& y, const int& cell);

	const float& getCellSizeX() const;
	const float& getCellSizeY() const;
};
