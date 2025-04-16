#include <stdio.h>

#define N 8

int board[N][N];

int isSafe(int row, int col) {
    int i, j;

    // Check this row on left side
    for(i = 0; i < col; i++)
        if(board[row][i])
            return 0;

    // Check upper diagonal on left side
    for(i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if(board[i][j])
            return 0;

    // Check lower diagonal on left side
    for(i = row, j = col; j >= 0 && i < N; i++, j--)
        if(board[i][j])
            return 0;

    return 1;
}

int solveNQ(int col) {
    if(col >= N) // If all queens are placed
        return 1;

    for(int i = 0; i < N; i++) {
        if(isSafe(i, col)) {
            board[i][col] = 1;
            if(solveNQ(col + 1))
                return 1;
            board[i][col] = 0; // Backtrack
        }
    }
    return 0;
}

void printBoard() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

int main() {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            board[i][j] = 0;

    if(solveNQ(0) == 1)
        printBoard();
    else
        printf("Solution does not exist.\n");

    return 0;
}
