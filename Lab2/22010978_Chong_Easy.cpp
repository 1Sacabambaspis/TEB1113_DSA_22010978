#include <iostream>
using namespace std;

bool is_magicsquare(int matrix[100][100], int n) {
    int sum_diag1 = 0, sum_diag2 = 0;

    int target_sum = 0;
    for (int j = 0; j < n; j++)
        target_sum += matrix[0][j];

    for (int i = 0; i < n; i++) {
        int row_sum = 0;
        for (int j = 0; j < n; j++)
            row_sum += matrix[i][j];
        if (row_sum != target_sum)
            return false;
    }

    for (int j = 0; j < n; j++) {
        int col_sum = 0;
        for (int i = 0; i < n; i++)
            col_sum += matrix[i][j];
        if (col_sum != target_sum)
            return false;
    }

    for (int i = 0; i < n; i++) {
        sum_diag1 += matrix[i][i];
        sum_diag2 += matrix[i][n - 1 - i];
    }

    if (sum_diag1 != target_sum || sum_diag2 != target_sum){
        return false;
    }
    return true;
}

int main() {
    int n;
    cout << "Enter matrix size: ";
    cin >> n;

    if (n > 100) {
        cout << "Matrix size too large! Max is 100x100." << endl;
        return 1;
    }

    int matrix[100][100];
    cout << "Enter the matrix values row by row:\n";

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    
    if (is_magicsquare(matrix, n)) {
        cout << "This matrix is a magic square" << endl;
    } 
    else {
        cout << "This matrix is not a magic square" << endl;
    }

    return 0;
}
