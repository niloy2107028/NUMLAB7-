   #include <iostream>
#include <vector>

using namespace std;

void lu_factorizing(const vector<vector<float>> &matrix, vector<vector<float>> &l_matrix, vector<vector<float>> &u_matrix)
{
    u_matrix[0][0] = matrix[0][0];
    u_matrix[0][1] = matrix[0][1];
    u_matrix[0][2] = matrix[0][2];
    u_matrix[0][3] = matrix[0][3];

    l_matrix[1][0] = matrix[1][0] / u_matrix[0][0];
    u_matrix[1][1] = matrix[1][1] - l_matrix[1][0] * u_matrix[0][1];
    u_matrix[1][2] = matrix[1][2] - l_matrix[1][0] * u_matrix[0][2];
    u_matrix[1][3] = matrix[1][3] - l_matrix[1][0] * u_matrix[0][3];

    l_matrix[2][0] = matrix[2][0] / u_matrix[0][0];
    l_matrix[2][1] = (matrix[2][1] - l_matrix[2][0] * u_matrix[0][1]) / u_matrix[1][1];
    u_matrix[2][2] = matrix[2][2] - l_matrix[2][0] * u_matrix[0][2] - l_matrix[2][1] * u_matrix[1][2];
    u_matrix[2][3] = matrix[2][3] - l_matrix[2][0] * u_matrix[0][3] - l_matrix[2][1] * u_matrix[1][3];

    l_matrix[3][0] = matrix[3][0] / u_matrix[0][0];
    l_matrix[3][1] = (matrix[3][1] - l_matrix[3][0] * u_matrix[0][1]) / u_matrix[1][1];
    l_matrix[3][2] = (matrix[3][2] - l_matrix[3][0] * u_matrix[0][2] - l_matrix[3][1] * u_matrix[1][2]) / u_matrix[2][2];
    u_matrix[3][3] = matrix[3][3] - l_matrix[3][0] * u_matrix[0][3] - l_matrix[3][1] * u_matrix[1][3] - l_matrix[3][2] * u_matrix[2][3];

    l_matrix[0][0] = 1;
    l_matrix[1][1] = 1;
    l_matrix[2][2] = 1;
    l_matrix[3][3] = 1;
}

vector<float> solve_ly(const vector<vector<float>> &l_matrix, const vector<float> &b)
{
    vector<float> y(4, 0);
    y[0] = b[0];
    y[1] = b[1] - l_matrix[1][0] * y[0];
    y[2] = b[2] - l_matrix[2][0] * y[0] - l_matrix[2][1] * y[1];
    y[3] = b[3] - l_matrix[3][0] * y[0] - l_matrix[3][1] * y[1] - l_matrix[3][2] * y[2];
    return y;
}

vector<float> solve_ux(const vector<vector<float>> &u_matrix, const vector<float> &y)
{
    vector<float> x(4, 0);
    x[3] = y[3] / u_matrix[3][3];
    x[2] = (y[2] - u_matrix[2][3] * x[3]) / u_matrix[2][2];
    x[1] = (y[1] - u_matrix[1][2] * x[2] - u_matrix[1][3] * x[3]) / u_matrix[1][1];
    x[0] = (y[0] - u_matrix[0][1] * x[1] - u_matrix[0][2] * x[2] - u_matrix[0][3] * x[3]) / u_matrix[0][0];
    return x;
}

int main()
{
    int size_of_matrix = 4;
    vector<vector<float>> matrix(size_of_matrix, vector<float>(size_of_matrix + 1));
    vector<float> b(size_of_matrix);

    for (int i = 0; i < size_of_matrix; i++)
    {
        for (int j = 0; j < size_of_matrix + 1; j++)
        {
            cin >> matrix[i][j];
            if (j == size_of_matrix)
            {
                b[i] = matrix[i][j];
            }
        }
    }

    vector<vector<float>> l_matrix(size_of_matrix, vector<float>(size_of_matrix, 0));
    vector<vector<float>> u_matrix(size_of_matrix, vector<float>(size_of_matrix, 0));

    lu_factorizing(matrix, l_matrix, u_matrix);

    vector<float> y = solve_ly(l_matrix, b);
    vector<float> x = solve_ux(u_matrix, y);

    cout << "X Vector (Solution):" << endl;
    for (const auto &value : x)
    {
        cout << value << " ";
    }
    cout << endl;

    return 0;

/*

2 3 4 1 30
1 1 2 3 20
4 0 1 2 25
3 2 0 1 15

*/
