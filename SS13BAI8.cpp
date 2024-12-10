#include <stdio.h>

// H�m t�m uoc chung lon nhat (GCD)
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

    // Nh?p hai s? nguy�n t? ngu?i d�ng
    printf("Nhap so nguy�n thu nhat: ");
    scanf("%d", &num1);
    printf("Nh?p s? nguy�n th? hai: ");
    scanf("%d", &num2);

    // G?i h�m d? t�m u?c chung l?n nh?t
    int gcd = findGCD(num1, num2);

    // In k?t qu?
    printf("U?c chung l?n nh?t c?a %d v� %d l�: %d\n", num1, num2, gcd);

    return 0;
}
