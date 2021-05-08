#include <stdio.h>

#define MODULOR 1000000007

typedef long long ll;

int fact(int n, int c);
int combine(int val, int a, int b, int c);
int divide(int a, int b, int c);

int main() {
    int N, K;

    scanf("%d %d", &N, &K);
    printf("%d\n", (int) ((ll) fact(N, MODULOR) * divide((int) ((ll) fact(K, MODULOR) * fact(N - K, MODULOR) % MODULOR), MODULOR - 2, MODULOR) % MODULOR));    

    return 0;
}

int fact(int n, int c) {
    int val = 1;

    for (int i = 1; i <= n; i++) 
        val = (int) ((ll) i % c * val % c);

    return val % c;
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