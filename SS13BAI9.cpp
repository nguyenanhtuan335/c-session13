#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// H�m kiem tra so nguy�n to
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// H�m nh?p m?ng
void inputMatrix(int n, int m, int matrix[][m]) {
    printf("Nhap gi� tri c�c phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("matrix[%d][%d] = ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// H�m in mang theo dang ma tran
void printMatrix(int n, int m, int matrix[][m]) {
    printf("Ma tr?n:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

// H�m in c�c phan tu o g�c
void printCorners(int n, int m, int matrix[][m]) {
    int result[n][m];
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            result[i][j] = 0;

    result[0][0] = matrix[0][0];             
	  // G�c tr�n b�n tr�i
    result[0][m-1] = matrix[0][m-1];          
	 // G�c tr�n b�n ph?i
    result[n-1][0] = matrix[n-1][0];         
	  // G�c du?i b�n tr�i
    result[n-1][m-1] = matrix[n-1][m-1];     
	  // G�c du?i b�n ph?i

    printf("C�c phan tu  g�c cua ma tran:\n");
    printMatrix(n, m, result);
}

// H�m in c�c ph?n t? tr�n du?ng bi�n
void printBorder(int n, int m, int matrix[][m]) {
    int result[n][m];
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            result[i][j] = 0;

    for (int i = 0; i < n; i++) {
        result[i][0] = matrix[i][0];          
		 // Bi�n tr�i
        result[i][m-1] = matrix[i][m-1];     
		  // Bi�n phai
    }

    for (int j = 0; j < m; j++) {
        result[0][j] = matrix[0][j];          
		 // Bi�n tr�n
        result[n-1][j] = matrix[n-1][j];      
		  // Bi�n duoi
    }

    printf("C�c ph?n t? tr�n du?ng bi�n:\n");
    printMatrix(n, m, result);
}

// H�m in c�c ph?n t? tr�n du?ng ch�o ch�nh v� ph?
void printDiagonals(int n, int m, int matrix[][m]) {
    int result[n][m];
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            result[i][j] = 0;

    for (int i = 0; i < n && i < m; i++) {
        result[i][i] = matrix[i][i];           // �u?ng ch�o ch�nh
        result[i][m-i-1] = matrix[i][m-i-1];   // �u?ng ch�o ph?
    }

    printf("C�c ph?n t? tr�n du?ng ch�o ch�nh v� ph?:\n");
    printMatrix(n, m, result);
}

// H�m in c�c ph?n t? l� s? nguy�n t?
void printPrimes(int n, int m, int matrix[][m]) {
    int result[n][m];
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            result[i][j] = isPrime(matrix[i][j]) ? matrix[i][j] : 0;

    printf("C�c ph?n t? l� s? nguy�n t?:\n");
    printMatrix(n, m, result);
}

// H�m hi?n th? menu v� x? l� c�c ch?c nang
void menu(int n, int m, int matrix[][m]) {
    int choice;
    do {
        printf("\nMENU:\n");
        printf("1. Nh?p gi� tr? c�c ph?n t? c?a m?ng\n");
        printf("2. In gi� tr? c�c ph?n t? c?a m?ng theo ma tr?n\n");
        printf("3. In ra c�c ph?n t? ? g�c theo ma tr?n\n");
        printf("4. In ra c�c ph?n t? n?m tr�n du?ng bi�n theo ma tr?n\n");
        printf("5. In ra c�c ph?n t? n?m tr�n du?ng ch�o ch�nh v� ch�o ph? theo ma tr?n\n");
        printf("6. In ra c�c ph?n t? l� s? nguy�n t? theo ma tr?n\n");
        printf("7. Tho�t\n");
        printf("L?a ch?n c?a b?n: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputMatrix(n, m, matrix);
                break;
            case 2:
                printMatrix(n, m, matrix);
                break;
            case 3:
                printCorners(n, m, matrix);
                break;
            case 4:
                printBorder(n, m, matrix);
                break;
            case 5:
                printDiagonals(n, m, matrix);
                break;
            case 6:
                printPrimes(n, m, matrix);
                break;
            case 7:
                printf("Tho�t chuong tr�nh.\n");
                break;
            default:
                printf("L?a ch?n kh�ng h?p l?. Vui l�ng th? l?i.\n");
        }
    } while (choice != 7);
}

int main() {
    int n, m;
    printf("Nh?p s? h�ng: ");
    scanf("%d", &n);
    printf("Nh?p s? c?t: ");
    scanf("%d", &m);

    int matrix[n][m];
    menu(n, m, matrix);

    return 0;
}
