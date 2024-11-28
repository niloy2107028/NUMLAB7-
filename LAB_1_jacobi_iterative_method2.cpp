#include <iostream>
#include <vector>
using namespace std;

vector<float> jacobiMethod(int n, const vector<vector<float>>& coefficients, int iterations) {
    vector<float> prev_values(n, 0.0), cur_values(n, 0.0);

    while (iterations--) {
        for (int i = 0; i < n; i++) {
            float sum = coefficients[i][n];
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum -= coefficients[i][j] * prev_values[j];
                }
            }
            cur_values[i] = sum / coefficients[i][i];
        }
        prev_values = cur_values;
    }

    return cur_values;
}

int main() {
    int n, iterations;
    cin >> n;
    vector<vector<float>> coefficients(n, vector<float>(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            cin >> coefficients[i][j];
        }
    }
    cin >> iterations;

    vector<float> result = jacobiMethod(n, coefficients, iterations);
    for (float value : result) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}

/*


sample input for :

diagonally dominant

27x + 6y - z = 85
6x + 15y + 2z = 72
1x + 1y + 54z = 110

3
27 6 -1 85
6 15 2 72
1 1 54 110



6x + 2y − z = 4 
 
x + 5y + z = 3 
 
2x + y + 4z = 27 

3
6 2 -1 4
1 4 1 3
2 1 4 27



3x + 2y + z = 8
 
x + 2y + z = 4 
 
2x + 4y + z = 9

3
3 2 1 8
1 2 1 4
2 4 1 9

3
10 2 3 15
5 3 15 10
1 8 2 7

final input:

126x + 56y + 57z = 2899
 
45x + 225y + 98z = 4936 
 
28x + 93y + 547z = 5557


3
126 56 57 2899
45 225 98 4936
28 93 547 5557
20


*/
