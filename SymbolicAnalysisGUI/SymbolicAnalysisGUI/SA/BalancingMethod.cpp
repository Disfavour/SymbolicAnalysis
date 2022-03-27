#include "BalancingMethod.h"


unordered_map<int, float> Balancing::BalancingMethod(const unordered_map<int, unordered_set<int>>& graph, const float& eps, const float& cellArea)
{
    unordered_map<int, vector<float>> matrix;
    unordered_map<int, vector<int>>
        rowToPosition,      // номера столбцов в строке с значениями
        columnToPosition;   // номера строк в столбце с значениями

    vector<int> cells;

    for (auto& keyValue : graph)
    {
        cells.push_back(keyValue.first);

        for (auto& linkedVertex : keyValue.second)
        {
            matrix[keyValue.first].push_back(1.0f);
            rowToPosition[keyValue.first].push_back(linkedVertex);
            columnToPosition[linkedVertex].push_back(keyValue.first);
        }
    }

    float sumOld = 0;

    while (true)
    {
        const float sum = getSumOfMatrixElements(matrix);

        if (abs(sum - sumOld) < eps)
        {
            unordered_map<int, float> invariantMeasure = calculateInvariantMeasureFromMatrix(matrix);

            invariantMeasure = getMeasureDensity(invariantMeasure, cellArea);

            return invariantMeasure;
        }

        normalizeMatrix(matrix, sum);

        // Фиксируем i
        for (auto& cell : cells)
        {
            float
                rowSum = 0,
                columnSum = 0;

            for (auto& value : matrix[cell])
            {
                rowSum += value;
            }

            for (auto& rowNum : columnToPosition[cell])
            {
                int i = 0;
                for (auto& linkedVertex : rowToPosition[rowNum])
                {
                    if (cell == linkedVertex)
                    {
                        columnSum += matrix[rowNum][i];
                        break;
                    }

                    i++;
                }
            }

            float Xi = 0;
            int XiPos = 0;
            for (auto& linkedVertex : rowToPosition[cell])
            {
                if (cell == linkedVertex)
                {
                    Xi = matrix[cell][XiPos];
                    break;
                }
                XiPos++;
            }

            rowSum -= Xi;
            columnSum -= Xi;
            if (rowSum <= 0 || columnSum <= 0)
            {
                continue;
            }

            const float
                kForRows = sqrt(columnSum / rowSum),
                kForColumns = sqrt(rowSum / columnSum);

            // Преобразования в строке
            for (auto& value : matrix[cell])
            {
                value *= kForRows;
            }

            // Преобразования в столбце
            for (auto& rowNum : columnToPosition[cell])
            {
                int i = 0;
                for (auto& linkedVertex : rowToPosition[rowNum])
                {
                    if (cell == linkedVertex)
                    {
                        matrix[rowNum][i] *= kForColumns;
                        break;
                    }

                    i++;
                }
            }

            // Возвращаем Хi
            if (Xi != 0)
            {
                matrix[cell][XiPos] = Xi;
            }
        }
        sumOld = sum;
    }
}

float Balancing::getSumOfMatrixElements(const unordered_map<int, vector<float>>& matrix)
{
    float sum = 0;
    for (auto& keyValue : matrix)
    {
        for (auto& value : keyValue.second)
        {
            sum += value;
        }
    }
    return sum;
}

void Balancing::normalizeMatrix(unordered_map<int, vector<float>>& matrix, const float& sum)
{
    for (auto& keyValue : matrix)
    {
        for (auto& value : keyValue.second)
        {
            value /= sum;
        }
    }
}

unordered_map<int, float> Balancing::calculateInvariantMeasureFromMatrix(const unordered_map<int, vector<float>>& matrix)
{
    unordered_map<int, float> invariantMeasure;

    for (auto& keyValue : matrix)
    {
        float sumInRow = 0;
        for (auto& value : keyValue.second)
        {
            sumInRow += value;
        }
        invariantMeasure[keyValue.first] = sumInRow;
    }

    return invariantMeasure;
}

unordered_map<int, float> Balancing::getMeasureDensity(unordered_map<int, float>& invariantMeasure, const float& cellArea)
{
    unordered_map<int, float> measureDensity;

    for (auto& keyValue : invariantMeasure)
    {
        measureDensity[keyValue.first] = keyValue.second / cellArea;
    }

    return measureDensity;
}
