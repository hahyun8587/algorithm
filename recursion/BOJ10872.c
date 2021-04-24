#include <stdio.h>

int fact(int n);

int main() {
    int N;

    scanf("%d", &N);
    printf("%d\n", fact(N));

    return 0;
}

int fact(int n) {
    if (!n)
        return 1;

    return fact(n - 1) * n;    
}