#include <iostream>
using namespace std;

bool is_winner(char board[3][3], char player){
    for (int i = 0; i < 3; i++)
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || // row
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))   // column
            return true;

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||     // main diagonal
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))       // anti-diagonal
        return true;

    return false;
}

bool is_validboard(char board [3][3]){
    int countX = 0, countO = 0;

    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X') countX++;
            else if (board[i][j] == 'O') countO++;
        }

    
    if (!(countX == countO || countX == countO + 1))
        return false;

    
    bool xWins = is_winner(board, 'X');
    bool oWins = is_winner(board, 'O');

    
    if (xWins && oWins)
        return false;

    
    if (xWins && countX != countO + 1)
        return false;

    
    if (oWins && countX != countO)
        return false;

    return true;
}

int main(){
    char board [3][3];
    for(int i = 0; i<3;i++){
        for (int j = 0; j<3;j++) {
            cout<<"Enter X or O for this square in the board: "<<endl;cin>>board[i][j];
        }
    }

    if (is_validboard(board)) {
        cout << "Valid board" << endl;
    } else {
        cout << "Invalid board" << endl;
    }

    return 0;

}

