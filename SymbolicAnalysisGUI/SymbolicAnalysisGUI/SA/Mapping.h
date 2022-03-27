#pragma once
#include "parser/parser.h"
#include <string>

class Mapping
{
private:
	TParser mappingX, mappingY;
	char* formulaX, * formulaY;

	TParser projectiveMappingX, projectiveMappingY;
	char* projectiveFormulaX, * projectiveFormulaY;

	TParser arcWeight;
	char* arcWeightFormula;

	string getModifiedString(const string& str);
	char* getCString(const string& str);
	string getModifiedProjectiveString(const string& str);

protected:
	Mapping(const string& formulaX, const string& formulaY, const string& projectiveFormulaX, const string& projectiveFormulaY, const string& arcWeightFormula);

	// ����������� �����������
	Mapping(const string& formulaX, const string& formulaY);

	// ��� ������������
	Mapping(const string& formulaX, const string& formulaY, const string& projectiveFormulaX, const string& projectiveFormulaY);

	// ��� ��������� ������������
	Mapping(const string& formulaX, const string& formulaY, const string& arcWeightFormula);

	void calculateMapping(float& newX, float& newY, const float& x, const float& y);
	void calculateProjectiveMapping(float& newX, float& newY, const float& x, const float& y, const float& b, const float& d);

	const float calculateArcWeight(const float& x, const float& y, const float& b, const float& d);
	const float calculateArcWeight(const float& x, const float& y);

public:
	// �� ����, ��������� �� ���������� � protected, �� ��� ����� ���������.
	~Mapping();
};
