#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Hàm kiem tra so nguyên to
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Hàm nh?p m?ng
void inputMatrix(int n, int m, int matrix[][m]) {
    printf("Nhap giá tri các phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("matrix[%d][%d] = ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Hàm in mang theo dang ma tran
void printMatrix(int n, int m, int matrix[][m]) {
    printf("Ma tr?n:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

// Hàm in các phan tu o góc
void printCorners(int n, int m, int matrix[][m]) {
    int result[n][m];
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            result[i][j] = 0;

    result[0][0] = matrix[0][0];             
	  // Góc trên bên trái
    result[0][m-1] = matrix[0][m-1];          
	 // Góc trên bên ph?i
    result[n-1][0] = matrix[n-1][0];         
	  // Góc du?i bên trái
    result[n-1][m-1] = matrix[n-1][m-1];     
	  // Góc du?i bên ph?i

    printf("Các phan tu  góc cua ma tran:\n");
    printMatrix(n, m, result);
}

// Hàm in các ph?n t? trên du?ng biên
void printBorder(int n, int m, int matrix[][m]) {
    int result[n][m];
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            result[i][j] = 0;

    for (int i = 0; i < n; i++) {
        result[i][0] = matrix[i][0];          
		 // Biên trái
        result[i][m-1] = matrix[i][m-1];     
		  // Biên phai
    }

    for (int j = 0; j < m; j++) {
        result[0][j] = matrix[0][j];          
		 // Biên trên
        result[n-1][j] = matrix[n-1][j];      
		  // Biên duoi
    }

    printf("Các ph?n t? trên du?ng biên:\n");
    printMatrix(n, m, result);
}

// Hàm in các ph?n t? trên du?ng chéo chính và ph?
void printDiagonals(int n, int m, int matrix[][m]) {
    int result[n][m];
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            result[i][j] = 0;

    for (int i = 0; i < n && i < m; i++) {
        result[i][i] = matrix[i][i];           // Ðu?ng chéo chính
        result[i][m-i-1] = matrix[i][m-i-1];   // Ðu?ng chéo ph?
    }

    printf("Các ph?n t? trên du?ng chéo chính và ph?:\n");
    printMatrix(n, m, result);
}

// Hàm in các ph?n t? là s? nguyên t?
void printPrimes(int n, int m, int matrix[][m]) {
    int result[n][m];
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            result[i][j] = isPrime(matrix[i][j]) ? matrix[i][j] : 0;

    printf("Các ph?n t? là s? nguyên t?:\n");
    printMatrix(n, m, result);
}

// Hàm hi?n th? menu và x? lý các ch?c nang
void menu(int n, int m, int matrix[][m]) {
    int choice;
    do {
        printf("\nMENU:\n");
        printf("1. Nh?p giá tr? các ph?n t? c?a m?ng\n");
        printf("2. In giá tr? các ph?n t? c?a m?ng theo ma tr?n\n");
        printf("3. In ra các ph?n t? ? góc theo ma tr?n\n");
        printf("4. In ra các ph?n t? n?m trên du?ng biên theo ma tr?n\n");
        printf("5. In ra các ph?n t? n?m trên du?ng chéo chính và chéo ph? theo ma tr?n\n");
        printf("6. In ra các ph?n t? là s? nguyên t? theo ma tr?n\n");
        printf("7. Thoát\n");
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
                printf("Thoát chuong trình.\n");
                break;
            default:
                printf("L?a ch?n không h?p l?. Vui lòng th? l?i.\n");
        }
    } while (choice != 7);
}

int main() {
    int n, m;
    printf("Nh?p s? hàng: ");
    scanf("%d", &n);
    printf("Nh?p s? c?t: ");
    scanf("%d", &m);

    int matrix[n][m];
    menu(n, m, matrix);

    return 0;
}
