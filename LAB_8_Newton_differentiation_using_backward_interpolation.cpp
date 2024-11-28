
// Numerical Differentiation using Newton's Backward Interpolation

#include <bits/stdc++.h>
using namespace std;

void differenceTable(vector<double> &x, vector<double> &y, vector<vector<double>> &diffTable)
{
    int n = x.size();

    for (int i = 0; i < n; i++)
    {
        diffTable[i][0] = y[i];
    }

    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            diffTable[i][j] = diffTable[i + 1][j - 1] - diffTable[i][j - 1];
        }
    }
}

double calculateDerivative(vector<double> &x, vector<vector<double>> &diffTable, double x0, double h)
{

    int n = x.size();
    double s = (x0 - x[n - 1]) / h;
    double derivative;

    derivative = diffTable[n - 1 - 1][1];
    derivative += ((s + s + 1) * diffTable[n - 1 - 2][2] / 2);
    derivative = derivative + (s * (s + 1) + s * (s + 2) + (s + 1) * (s + 2)) * diffTable[n - 1 - 3][3] / 6;
    derivative = derivative + (s * (s + 1) * (s + 2) + s * (s + 1) * (s + 3) + s * (s + 2) * (s + 3) + (s + 1) * (s + 2) * (s + 3)) * diffTable[n - 1 - 4][4] / 24;
    return derivative / h;
}

int main()
{
    // y=x^2
    // dy/dx=2x

    vector<double> x = {1, 2, 3, 4, 5};
    vector<double> y = {1, 4, 9, 16, 25};

    int n = x.size();
    vector<vector<double>> diffTable(n, vector<double>(n));

    differenceTable(x, y, diffTable);

    //showing table
    // for (auto row : diffTable)
    // {
    //     for (auto val : row)
    //     {
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }

    double x0;
    cout << "Enter the value of x0 : ";
    cin >> x0;
    double h = x[1] - x[0];
    double derivative = calculateDerivative(x, diffTable, x0, h);

    cout << "f'(x) at x = " << x0 << " is: " << setprecision(5) << fixed << derivative << endl;

    return 0;
}
