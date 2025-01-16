#include <iostream>
#include <vector>
using namespace std;

void displayBoard(const vector<char>& board) {
    for (int i = 0; i < 9; i++) {
        cout << " " << board[i] << " ";
        if (i % 3 != 2) cout << "|";
        if (i % 3 == 2 && i != 8) cout << "\n---|---|---\n";
    }
    cout << "\n";
}

bool isWin(const vector<char>& board, char player) {
    return (board[0] == player && board[1] == player && board[2] == player) ||
           (board[3] == player && board[4] == player && board[5] == player) ||
           (board[6] == player && board[7] == player && board[8] == player) ||
           (board[0] == player && board[3] == player && board[6] == player) ||
           (board[1] == player && board[4] == player && board[7] == player) ||
           (board[2] == player && board[5] == player && board[8] == player) ||
           (board[0] == player && board[4] == player && board[8] == player) ||
           (board[2] == player && board[4] == player && board[6] == player);
}

bool isDraw(const vector<char>& board) {
    for (char cell : board) {
        if (cell == ' ') return false;
    }
    return true;
}

void resetBoard(vector<char>& board) {
    for (int i = 0; i < 9; i++) {
        board[i] = ' ';
    }
}

int main() {
    vector<char> board(9, ' ');
    char currentPlayer = 'X';
    bool gameOngoing = true;
    char playAgain;

    do {
        resetBoard(board);
        gameOngoing = true;
        displayBoard(board);

        while (gameOngoing) {
            int move;
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            if (move < 1 || move > 9 || board[move - 1] != ' ') {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            board[move - 1] = currentPlayer;
            displayBoard(board);

            if (isWin(board, currentPlayer)) {
                cout << "Player " << currentPlayer << " wins!\n";
                gameOngoing = false;
            } else if (isDraw(board)) {
                cout << "It's a draw!\n";
                gameOngoing = false;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
