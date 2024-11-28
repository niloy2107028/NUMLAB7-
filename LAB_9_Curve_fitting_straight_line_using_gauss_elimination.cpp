#include <iostream>
#include <vector>

using namespace std;

vector<double> solveLinearSystem(vector<vector<double>> A, vector<double> B)
{
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double ratio = A[j][i] / A[i][i];
            for (int k = i; k < n; k++)
            {
                A[j][k] -= ratio * A[i][k];
            }
            B[j] -= ratio * B[i];
        }
    }

    vector<double> X(n);
    for (int i = n - 1; i >= 0; i--)
    {
        X[i] = B[i];
        for (int j = i + 1; j < n; j++)
        {
            X[i] -= A[i][j] * X[j];
        }
        X[i] /= A[i][i];
    }
    return X;
}

void calculateSums(const vector<double> &x, const vector<double> &y, double &sumX, double &sumY, double &sumX2, double &sumXY)
{
    sumX = 0;
    sumY = 0;
    sumX2 = 0;
    sumXY = 0;
    int n = x.size();
    for (int i = 0; i < n; i++)
    {
        sumX += x[i];
        sumY += y[i];
        sumX2 += x[i] * x[i];
        sumXY += x[i] * y[i];
    }
}

void linearFit(const vector<double> &x, const vector<double> &y, double &slope, double &intercept)
{
    double sumX, sumY, sumX2, sumXY;
    calculateSums(x, y, sumX, sumY, sumX2, sumXY);
    int n = x.size();

    vector<vector<double>> A = {{(double)n, sumX}, {sumX, sumX2}};
    vector<double> B = {sumY, sumXY};

    vector<double> result = solveLinearSystem(A, B);

    intercept = result[0];
    slope = result[1];
}

void printEquation(double slope, double intercept)
{
    cout << "Fitted line equation: y = " << slope << "x + " << intercept << endl;
}

int main()
{
    vector<double> x = {1, 2, 3, 4, 6, 8};
    vector<double> y = {2.4, 3, 3.6, 4, 5, 6};
    double slope, intercept;

    linearFit(x, y, slope, intercept);
    printEquation(slope, intercept);

    return 0;
}
