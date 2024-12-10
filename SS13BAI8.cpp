#include <stdio.h>

// Hàm tìm uoc chung lon nhat (GCD)
int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;

    // Nh?p hai s? nguyên t? ngu?i dùng
    printf("Nhap so nguyên thu nhat: ");
    scanf("%d", &num1);
    printf("Nh?p s? nguyên th? hai: ");
    scanf("%d", &num2);

    // G?i hàm d? tìm u?c chung l?n nh?t
    int gcd = findGCD(num1, num2);

    // In k?t qu?
    printf("U?c chung l?n nh?t c?a %d và %d là: %d\n", num1, num2, gcd);

    return 0;
}
