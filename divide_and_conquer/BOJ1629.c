#include <stdio.h>

typedef long long ll;

int combine(int val, int a, int b, int c);
int divide(int a, int b, int c);

int main() {
    int A, B, C;

    scanf("%d %d %d", &A, &B, &C);
    printf("%lld\n", divide(A, B, C));

    return 0;
}

int combine(int val, int a, int b, int c) {
    return (int) ((ll) val * val % c * ((1 + (a - 1) * (b % 2)) % c) % c);
}

int divide(int a, int b, int c) {
    if (b == 1)
        return a % c;

    int val;
    
    val = !(b % 2) ? divide(a, b / 2, c) : divide(a, (b - 1) / 2, c);

    return combine(val, a, b, c);
}