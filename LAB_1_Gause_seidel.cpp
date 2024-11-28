#include <iostream>
#include <vector>
using namespace std;

vector<float> gaussSeidel(const vector<vector<float>> &augmentedMatrix, int iterations)
{
    int n = augmentedMatrix.size();
    vector<float> values(n, 0.0f);

    for (int iter = 0; iter < iterations; ++iter)
    {
        for (int i = 0; i < n; ++i)
        {
            float sum = augmentedMatrix[i][n];
            for (int j = 0; j < n; ++j)
            {
                if (i != j)
                {
                    sum -= augmentedMatrix[i][j] * values[j];
                }
            }
            values[i] = sum / augmentedMatrix[i][i];
        }
    }

    return values;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<float>> augmentedMatrix(n, vector<float>(n + 1));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n + 1; ++j)
        {
            cin >> augmentedMatrix[i][j];
        }
    }

    int iterations;
    cin >> iterations;

    vector<float> result = gaussSeidel(augmentedMatrix, iterations);
    for (int i = 0; i < n; ++i)
    {
        cout << "x" << i + 1 << " = " << result[i] << "\n";
    }

    return 0;
}
