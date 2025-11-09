#include <bits/stdc++.h>
using namespace std;

// Function to print the N-Queens board
void printBoard(vector<vector<int>> &board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

// Function to check if placing a queen at (row, col) is safe
bool isSafe(vector<vector<int>> &board, int row, int col, int n) {
    // Check column (above)
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // Check upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

// Recursive function to solve N-Queens problem
bool solveNQueens(vector<vector<int>> &board, int row, int n) {
    if (row >= n) {
        cout << "Final N-Queens Matrix:\n";
        printBoard(board, n);
        return true; // One valid solution found
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            if (solveNQueens(board, row + 1, n))
                return true;
            board[row][col] = 0; // Backtrack
        }
    }
    return false;
}

// Function to solve N-Queens when the first queen position is fixed
void nQueensWithFirstFixed(int n, int first_row, int first_col) {
    vector<vector<int>> board(n, vector<int>(n, 0));

    // Place the first queen at fixed position
    board[first_row][first_col] = 1;

    // Start solving from the next row
    if (!solveNQueens(board, first_row + 1, n))
        cout << "No solution exists.\n";
}

int main() {
    int n, r, c;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter first queen row (0-indexed): ";
    cin >> r;
    cout << "Enter first queen col (0-indexed): ";
    cin >> c;

    nQueensWithFirstFixed(n, r, c);

    return 0;
}
