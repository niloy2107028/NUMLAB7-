#include <iostream>
#include <vector>
#include <cmath>

const double epsilon = 1e-9;

using namespace std;

void printing_matrix(vector<vector<double>> matrix)
{
    cout << "printing matrix :" << endl;
    for (const auto row : matrix)
    {
        for (double element : row)
        {
            cout << element << " ";
        }
        cout << endl;
    }
}

void gauss_eli(vector<vector<double>> &matrix)
{
    int size = matrix.size();

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (abs(matrix[i][i]) < epsilon)
            {
                cout << "Error! Near zero pivot element at row " << i << " (element: " << matrix[i][i] << ")." << endl;
                exit(EXIT_FAILURE);
            }

            double factor = matrix[j][i] / matrix[i][i];

            for (int k = i; k < size + 1; k++)  //constant o count e ase
            {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }
}

void jordan_eli(vector<vector<double>> &matrix)
{
    int size = matrix.size();

    for (int i = size - 1; i > -1; i--)
    {
        for (int j = i - 1; j > -1; j--)
        {
            if (abs(matrix[i][i]) < epsilon)
            {
                cout << "Error! Near zero pivot element at row " << i << " (element: " << matrix[i][i] << ")." << endl;
                exit(EXIT_FAILURE);
            }

            double factor = matrix[j][i] / matrix[i][i];

            for (int k = size; k > -1; k--)
            {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }
}

void row_eche(vector<vector<double>> &matrix)
{
    int size = matrix.size();
    for (int i = 0; i < size; i++)
    {

        double diag = matrix[i][i];
        if (abs(diag) > epsilon)
        {
            for (int j = 0; j <= size; j++)
            {
                matrix[i][j] /= diag;
            }
        }
    }
}

vector<double> gauss_elimination(vector<vector<double>> &matrix)
{

    gauss_eli(matrix);
    row_eche(matrix);
    
    int size = matrix.size();
    vector<double> result(size, 0);
    for (int i = size - 1; i > -1; i--)
    {
        result[i] = matrix[i][size];
        for (int j = i + 1; j < size; j++)
        {
            result[i] -= matrix[i][j] * result[j];
        }
    }

    return result;
}

vector<double> gauss_jordan_elimination(vector<vector<double>> &matrix)
{

    gauss_eli(matrix);
    jordan_eli(matrix);
    row_eche(matrix);

    int size = matrix.size();
    vector<double> result(size, 0);
    for (int i = size - 1; i > -1; i--)
    {
        result[i] = matrix[i][size];
    }

    return result;
}

void print_root(vector<double> result)
{
    cout << "Printing roots :" << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << "Root " << i + 1 << " : " << result[i] << endl;
    }
}

/*

3
1 1 -1 7
1 -1 2 3
2 1 1 9

3
4 1 -1 7
2 2 2 3
3 1 1 9

3
1 2 3 10
4 5 6 20
7 8 9 30
*/

int main()

{
    int no_of_variable = 0;
    cin >> no_of_variable;

    vector<vector<double>> matrix(no_of_variable, vector<double>(no_of_variable + 1, 0));

    for (int i = 0; i < no_of_variable; i++)
    {
        for (int j = 0; j < no_of_variable + 1; j++)
        {
            cin >> matrix[i][j];
        }
    }

    vector<double> result(no_of_variable, 0);

    result = gauss_elimination(matrix);

    print_root(result);

    result = gauss_jordan_elimination(matrix);

    print_root(result);

    printing_matrix(matrix);

    return 0;
}
