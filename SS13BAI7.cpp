#include <stdio.h>

// H�m tao ma tran 2 chieu
void createMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Nh?p c�c gi� tr? cho ma tr?n (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Nh?p ph?n t? [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// H�m in ma tr?n ra m�n h�nh
void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Ma tr?n (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    // Y�u c?u ngu?i d�ng nh?p s? h�ng v� s? c?t
    printf("Nh?p s? h�ng c?a ma tr?n: ");
    scanf("%d", &rows);
    printf("Nh?p s? c?t c?a ma tr?n: ");
    scanf("%d", &cols);

    // Khai b�o m?ng tinh v?i k�ch thu?c l?n hon
    int matrix[rows][cols];

    // T?o ma tr?n
    createMatrix(rows, cols, matrix);

    // In ma tr?n
    printMatrix(rows, cols, matrix);

    return 0;
}
