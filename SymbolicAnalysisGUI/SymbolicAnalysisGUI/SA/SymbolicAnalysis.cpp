#include "SymbolicAnalysis.h"


SymbolicAnalysis::SymbolicAnalysis(const float& left, const float& right, const float& top, const float& bot,
    const string& formulaX, const string& formulaY,
    const int& maxIter, const int& dotsPerCell, const int& splitNum,
    const float& eps,
    const string& projectiveFormulaX, const string& projectiveFormulaY,
    const int& maxIterProjective, const int& splitNumProjective,
    const string& arcWeightFormula)
    : Localization(left, right, top, bot, formulaX, formulaY, maxIter, dotsPerCell, splitNum), eps(eps),
    Mapping(formulaX, formulaY, projectiveFormulaX, projectiveFormulaY, arcWeightFormula),
    MorseSpectrum(left, right, top, bot, formulaX, formulaY, maxIter, dotsPerCell, splitNum, projectiveFormulaX, projectiveFormulaY, maxIterProjective, splitNumProjective, arcWeightFormula),
    RomanovskyAlgorithm(left, right, top, bot, formulaX, formulaY, maxIter, dotsPerCell, splitNum, arcWeightFormula) {}

const float SymbolicAnalysis::getDiameterOfCell() const
{
    return pow(pow(getCellSizeX(), 2) + pow(getCellSizeY(), 2), 0.5);
}

void SymbolicAnalysis::startTime()
{
    start_time = clock();
}

const float SymbolicAnalysis::endTime()
{
    return float(clock() - start_time) / CLOCKS_PER_SEC;
}

void SymbolicAnalysis::prepareLocalization()
{
    startTime();

    LocalizationOfTheChainRecurrentSet();
    colors = getDifferentColors(getSCs().size());

    _time = endTime();

    info["v"] = { to_string(getGraph().size()) };
    info["sc"] = { to_string(getSCs().size()) };

    for (int i = 0; i < getSCs().size(); ++i)
    {
        info["scALL"].push_back(to_string(getSCs()[i].size()));
    }

    info["d"] = { to_string(getDiameterOfCell()) };

    info["t"] = { to_string(_time) };
}

void SymbolicAnalysis::prepareBalancingMethod()
{
    prepareLocalization();

    startTime();

    const float cellArea = getCellSizeX() * getCellSizeY();

    invariantMeasure = BalancingMethod(getGraph(), eps, cellArea);

    _time += endTime();

    info["t"] = { to_string(_time) };
}

void SymbolicAnalysis::prepareJohnson()
{
    prepareLocalization();

    startTime();

    graphForMaxCycle = longestElementaryCycleInDirectedGraph(getGraph());

    _time += endTime();

    info["t"] = { to_string(_time) };

    info["mc"] = { to_string(graphForMaxCycle.size()) };
}

void SymbolicAnalysis::prepareProjectiveLocalization()
{
    prepareLocalization();

    startTime();

    LocalizationOfTheChainRecurrentSetInProjectiveSpace(getGraph());

    _time += endTime();

    info["t"] = { to_string(_time) };

    info["vp"] = { to_string(getGraphP().size()) };
    info["scp"] = { to_string(getSCsP().size()) };

    for (int i = 0; i < getSCsP().size(); ++i)
    {
        info["scALLp"].push_back(to_string(getSCsP()[i].size()));
    }

    info["dp"] = { to_string(getMapSegmentSize()) };
}

void SymbolicAnalysis::prepareMorseSpectrum()
{
    prepareProjectiveLocalization();

    startTime();

    MorseSpectrumÑalculation(getGraphP());

    _time += endTime();

    info["t"] = { to_string(_time) };
    
    for (auto& item : MorseSpectrum::getSCorder())
    {
        info["scOrder"].push_back(to_string(item));
    }

    for (auto& item : MorseSpectrum::getMinCircuitsWeights())
    {
        info["min"].push_back(to_string(item));
    }

    for (auto& item : MorseSpectrum::getMaxCircuitsWeights())
    {
        info["max"].push_back(to_string(item));
    }
}

void SymbolicAnalysis::prepareRomanovskyAlgorithm()
{
    prepareLocalization();

    startTime();

    RomanovskyAlgorithmCalculation(getGraph());

    _time += endTime();

    info["t"] = { to_string(_time) };

    for (auto& item : RomanovskyAlgorithm::getSCorder())
    {
        info["scOrder"].push_back(to_string(item));
    }

    for (auto& item : RomanovskyAlgorithm::getMinCircuitsWeights())
    {
        info["min"].push_back(to_string(item));
    }

    for (auto& item : RomanovskyAlgorithm::getMaxCircuitsWeights())
    {
        info["max"].push_back(to_string(item));
    }
}

void SymbolicAnalysis::prepareMaxCycleInProjective()
{
    prepareJohnson();

    startTime();

    LocalizationOfTheChainRecurrentSetInProjectiveSpace(graphForMaxCycle);

    _time += endTime();

    info["t"] = { to_string(_time) };

    info["vp"] = { to_string(getGraphP().size()) };
    info["scp"] = { to_string(getSCsP().size()) };

    for (int i = 0; i < getSCsP().size(); ++i)
    {
        info["scALLp"].push_back(to_string(getSCsP()[i].size()));
    }

    info["dp"] = { to_string(getMapSegmentSize()) };

    for (auto& item : MorseSpectrum::getSCorder())
    {
        info["scOrder"].push_back(to_string(item));
    }

    for (auto& item : MorseSpectrum::getMinCircuitsWeights())
    {
        info["min"].push_back(to_string(item));
    }

    for (auto& item : MorseSpectrum::getMaxCircuitsWeights())
    {
        info["max"].push_back(to_string(item));
    }
}

void SymbolicAnalysis::prepareMaxCycleMorseSpectrum()
{
    prepareMaxCycleInProjective();

    startTime();

    MorseSpectrumÑalculation(getGraphP());

    _time += endTime();

    info["t"] = { to_string(_time) };

    for (auto& item : MorseSpectrum::getSCorder())
    {
        info["scOrder"].push_back(to_string(item));
    }

    for (auto& item : MorseSpectrum::getMinCircuitsWeights())
    {
        info["min"].push_back(to_string(item));
    }

    for (auto& item : MorseSpectrum::getMaxCircuitsWeights())
    {
        info["max"].push_back(to_string(item));
    }
}

vector<vector<float>>& SymbolicAnalysis::getColors()
{
    return colors;
}

unordered_map<int, float>& SymbolicAnalysis::getInvariantMeasure()
{
    return invariantMeasure;
}

unordered_map<int, unordered_set<int>>& SymbolicAnalysis::getGraphForMaxCycle()
{
    return graphForMaxCycle;
}

unordered_map<string, vector<string>>& SymbolicAnalysis::getInfo()
{
    return info;
}
