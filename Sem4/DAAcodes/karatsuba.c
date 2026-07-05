#include <stdio.h>
#include <math.h>

long karatsuba(long x, long y) {
    if (x < 10 || y < 10)
        return x * y;

    int n = 0;
    long temp = x > y ? x : y;
    while (temp > 0) {
        temp /= 10;
        n++;
    }
    int n2 = n / 2;

    long a = x / (long)pow(10, n2);
    long b = x % (long)pow(10, n2);
    long c = y / (long)pow(10, n2);
    long d = y % (long)pow(10, n2);

    long c2 = karatsuba(a, c);
    long c1 = karatsuba(a + b, c + d);
    long c0 = karatsuba(b, d);

    return (long)pow(10, 2 * n2) * c2 + (long)pow(10, n2) * (c1 - c2 - c0) + c0;
}

int main() {
    long x, y;
    printf("Enter two numbers: ");
    scanf("%ld %ld", &x, &y);
    printf("Result of multiplication: %ld\n", karatsuba(x, y));
    return 0;
}