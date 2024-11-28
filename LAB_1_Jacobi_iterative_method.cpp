#include <iostream>
#include <vector>
using namespace std;

vector<float> jacobiMethod(const vector<vector<float>> &augmentedMatrix, int iterations)
{
    int n = augmentedMatrix.size();
    vector<float> prev_values(n, 0.0f), cur_values(n, 0.0f);

    while (iterations--)
    {
        for (int i = 0; i < n; ++i)
        {
            float sum = augmentedMatrix[i][n];
            for (int j = 0; j < n; ++j)
            {
                if (i != j)
                {
                    sum -= augmentedMatrix[i][j] * prev_values[j];
                }
            }
            cur_values[i] = sum / augmentedMatrix[i][i];
        }
        prev_values = cur_values;
    }

    return cur_values;
}

int main()
{

    // only diagonally dominant
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

    vector<float> result = jacobiMethod(augmentedMatrix, iterations);
    for (int i = 0; i < n; ++i)
    {
        cout << "x" << i + 1 << " = " << result[i] << "\n";
    }

    return 0;
}
