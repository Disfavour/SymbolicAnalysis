#include "Mapping.h"


Mapping::Mapping(const string& formulaX, const string& formulaY, const string& projectiveFormulaX, const string& projectiveFormulaY, const string& arcWeightFormula)
	: formulaX(getCString(getModifiedString(formulaX))), formulaY(getCString(getModifiedString(formulaY))),
	projectiveFormulaX(getCString(getModifiedProjectiveString(projectiveFormulaX))), projectiveFormulaY(getCString(getModifiedProjectiveString(projectiveFormulaY))),
	arcWeightFormula(getCString(getModifiedProjectiveString(arcWeightFormula)))
{
	mappingX.Compile(this->formulaX);
	mappingY.Compile(this->formulaY);

	projectiveMappingX.Compile(this->projectiveFormulaX);
	projectiveMappingY.Compile(this->projectiveFormulaY);

	arcWeight.Compile(this->arcWeightFormula);
}

Mapping::Mapping(const string& formulaX, const string& formulaY)
	: formulaX(getCString(getModifiedString(formulaX))), formulaY(getCString(getModifiedString(formulaY))),
	projectiveFormulaX(nullptr), projectiveFormulaY(nullptr),
	arcWeightFormula(nullptr)
{
	mappingX.Compile(this->formulaX);
	mappingY.Compile(this->formulaY);
}

Mapping::Mapping(const string& formulaX, const string& formulaY, const string& projectiveFormulaX, const string& projectiveFormulaY)
	: formulaX(getCString(getModifiedString(formulaX))), formulaY(getCString(getModifiedString(formulaY))),
	projectiveFormulaX(getCString(getModifiedProjectiveString(projectiveFormulaX))), projectiveFormulaY(getCString(getModifiedProjectiveString(projectiveFormulaY))),
	arcWeightFormula(nullptr)
{
	mappingX.Compile(this->formulaX);
	mappingY.Compile(this->formulaY);

	projectiveMappingX.Compile(this->projectiveFormulaX);
	projectiveMappingY.Compile(this->projectiveFormulaY);
}

Mapping::Mapping(const string& formulaX, const string& formulaY, const string& arcWeightFormula)
	: formulaX(getCString(getModifiedString(formulaX))), formulaY(getCString(getModifiedString(formulaY))),
	projectiveFormulaX(nullptr), projectiveFormulaY(nullptr),
	arcWeightFormula(getCString(getModifiedProjectiveString(arcWeightFormula)))
{
	mappingX.Compile(this->formulaX);
	mappingY.Compile(this->formulaY);

	arcWeight.Compile(this->arcWeightFormula);
}

Mapping::~Mapping()
{
	delete[] formulaX;
	delete[] formulaY;

	delete[] projectiveFormulaX;
	delete[] projectiveFormulaY;

	delete[] arcWeightFormula;
}

void Mapping::calculateMapping(float& newX, float& newY, const float& x, const float& y)
{
	float tmp[]{ x, y };

	newX = mappingX.Evaluate(tmp);
	newY = mappingY.Evaluate(tmp);

	/*newX = mappingX.Evaluate(x, y);
	newY = mappingY.Evaluate(x, y);*/
}

void Mapping::calculateProjectiveMapping(float& newX, float& newY, const float& x, const float& y, const float& b, const float& d)
{
	float tmp[]{ x, y, b, d };

	newX = projectiveMappingX.Evaluate(tmp);
	newY = projectiveMappingY.Evaluate(tmp);
}

const float Mapping::calculateArcWeight(const float& x, const float& y, const float& b, const float& d)
{
	float tmp[]{ x, y, b, d };
	return arcWeight.Evaluate(tmp);
}

const float Mapping::calculateArcWeight(const float& x, const float& y)
{
	float tmp[]{ x, y };
	return arcWeight.Evaluate(tmp);
}

char* Mapping::getCString(const string& str)
{
	char* cstr = new char[str.length() + 1];
	strcpy(cstr, str.c_str());
	return cstr;
}

// x, y -> x[0], x[1]
string Mapping::getModifiedString(const string& str)
{
	string modifiedString = "";

	for (auto& symbol : str)
	{
		if (symbol == 'x')
		{
			modifiedString += "x[0]";
		}
		else if (symbol == 'y')
		{
			modifiedString += "x[1]";
		}
		else
		{
			modifiedString += symbol;
		}
	}

	return modifiedString;
}

// x, y, b, d -> x[0], x[1], x[2], x[3]
string Mapping::getModifiedProjectiveString(const string& str)
{
	string withoutXY = getModifiedString(str);

	string modifiedString = "";

	for (auto& symbol : withoutXY)
	{
		if (symbol == 'b')
		{
			modifiedString += "x[2]";
		}
		else if (symbol == 'd')
		{
			modifiedString += "x[3]";
		}
		else
		{
			modifiedString += symbol;
		}
	}

	return modifiedString;
}
