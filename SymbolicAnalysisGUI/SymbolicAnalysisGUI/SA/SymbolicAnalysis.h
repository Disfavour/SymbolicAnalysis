#pragma once
#include "Localization.h"
#include "BalancingMethod.h"
#include "JohnsonAlgorithm.h"
#include "ProjectiveLocalization.h"
#include "MorseSpectrum.h"
#include "RomanovskyAlgorithm.h"


class SymbolicAnalysis : public Balancing, public JohnsonAlgorithm, public RomanovskyAlgorithm, public MorseSpectrum
{
private:
    clock_t start_time;
    float _time;

    // Localization
    vector<vector<float>> colors;

    // Balancing
    const float eps;
    unordered_map<int, float> invariantMeasure;

    // Max cycle
    unordered_map<int, unordered_set<int>> graphForMaxCycle;

    // Projective Localization

    // v - количество возвратных вершин
    // sc - количество компонент сильной связности
    // scALL - размеры компонент сильной связности
    // d - диаметр ячейки
    // t - время
    // mc - длина максимального цикла
    // vp - количество возвратных вершин
    // scp - количество компонент сильной связности
    // scALLp - размеры компонент сильной связности
    // dp - диаметр ячейки
    // scOrder - порядок размеров компонент
    // min - минимальный вес
    // max - максимальный вес
    unordered_map<string, vector<string>> info;

    const float getDiameterOfCell() const;
    void startTime();
    const float endTime();

public:
    SymbolicAnalysis(const float& left, const float& right, const float& top, const float& bot,
        const string& formulaX, const string& formulaY,
        const int& maxIter, const int& dotsPerCell, const int& splitNum,
        const float& eps,
        const string& projectiveFormulaX, const string& projectiveFormulaY,
        const int& maxIterProjective, const int& splitNumProjective,
        const string& arcWeightFormula);

    // Localization
    vector<vector<float>>& getColors();

    // Balancing
    unordered_map<int, float>& getInvariantMeasure();

    // Max cycle
    unordered_map<int, unordered_set<int>>& getGraphForMaxCycle();

    void prepareLocalization();
    void prepareBalancingMethod();
    void prepareJohnson();
    void prepareProjectiveLocalization();
    void prepareRomanovskyAlgorithm();
    void prepareMorseSpectrum();

    void prepareMaxCycleInProjective();
    void prepareMaxCycleMorseSpectrum();

    unordered_map<string, vector<string>>& getInfo();
};
