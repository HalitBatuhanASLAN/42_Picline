#include<stdio.h>
#include<stdlib.h>

int backtracking(int map[5][5], int n, int current_row, int *num);
int is_valid(int map[5][5], int n, int current_row, int current_column);

int main() {
    int n, map[5][5];
    int i, j;

    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++)
            map[i][j] = 0;
    }

    printf("Enter n : ");
    scanf("%d", &n);
    printf("\n");

    int num = 0; // Initialize num variable

    backtracking(map, n, 0, &num); // Pass num by reference

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            printf("%d  ", map[i][j]);
        printf("\n");
    }

    return 0;
}

int backtracking(int map[5][5], int n, int current_row, int *num) {
    int j;

    if(*num == n) // All queens are placed successfully
        return 1;

    if(current_row == n) // Reached the end of the board
        return 0;

    for(j = 0; j < n; j++) {
        if(is_valid(map, n, current_row, j)) {
            map[current_row][j] = 1; // Place queen

            *num += 1; // Increment num

            // Recur for the next row
            if(backtracking(map, n, current_row + 1, num)) {
                return 1; // If successful, return
            }

            // Backtrack
            map[current_row][j] = 0;
            *num -= 1;
        }
    }
    return 0;
}

int is_valid(int map[5][5], int n, int current_row, int current_column) {
    int i, j;

    // Check row and column
    for(i = 0; i < n; i++) {
        if(map[current_row][i] == 1 || map[i][current_column] == 1)
            return 0;
    }

    // Check diagonals
    for(i = current_row, j = current_column; i >= 0 && j >= 0; i--, j--) {
        if(map[i][j] == 1)
            return 0;
    }

    for(i = current_row, j = current_column; i < n && j >= 0; i++, j--) {
        if(map[i][j] == 1)
            return 0;
    }

    return 1;
}