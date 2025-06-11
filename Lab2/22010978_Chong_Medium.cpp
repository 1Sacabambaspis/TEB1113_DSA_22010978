#include <iostream>
#include <climits>
using namespace std;

bool is_peak(int mat[][100], int i, int j, int n, int m) {
    int current = mat[i][j];

    int top    = (i > 0) ? mat[i - 1][j] : INT_MIN;
    int bottom = (i < n - 1) ? mat[i + 1][j] : INT_MIN;
    int left   = (j > 0) ? mat[i][j - 1] : INT_MIN;
    int right  = (j < m - 1) ? mat[i][j + 1] : INT_MIN;

    return current >= top && current >= bottom && current >= left && current >= right;
}

int main() {
    int n, m;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    int mat[100][100];
    cout << "Enter the matrix values:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (is_peak(mat, i, j, n, m)) {
                cout << "Peak element found at (" << i << ", " << j << ") = " << mat[i][j] << endl;
                return 0;
            }
        }
    }

    
    cout << "No peak element found." << endl;
    return 0;
}
