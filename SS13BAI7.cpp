#include <stdio.h>

// Hàm tao ma tran 2 chieu
void createMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Nh?p các giá tr? cho ma tr?n (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Nh?p ph?n t? [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Hàm in ma tr?n ra màn hình
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

    // Yêu c?u ngu?i dùng nh?p s? hàng và s? c?t
    printf("Nh?p s? hàng c?a ma tr?n: ");
    scanf("%d", &rows);
    printf("Nh?p s? c?t c?a ma tr?n: ");
    scanf("%d", &cols);

    // Khai báo m?ng tinh v?i kích thu?c l?n hon
    int matrix[rows][cols];

    // T?o ma tr?n
    createMatrix(rows, cols, matrix);

    // In ma tr?n
    printMatrix(rows, cols, matrix);

    return 0;
}
