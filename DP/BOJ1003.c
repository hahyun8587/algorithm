#include <stdio.h>

#define MAX_SIZE 40

void numPrint(int n, int *zero, int *one);

int main()
{
    int T;

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int n;
        int zero, one;

        scanf("%d", &n);
        numPrint(n, &zero, &one);
        printf("%d %d\n", zero, one);
    }
    return 0;
}

void numPrint(int n, int *zero, int *one)
{
    int dpZero[MAX_SIZE + 1];
    int dpOne[MAX_SIZE + 1];

    dpZero[0] = 1;
    dpZero[1] = 0;
    dpOne[0] = 0;
    dpOne[1] = 1;

    for (int i = 2; i <= MAX_SIZE; i++) {
        dpZero[i] = dpZero[i - 1] + dpZero[i - 2];
        dpOne[i] = dpOne[i - 1] + dpOne[i - 2];
    }
    *zero = dpZero[n];
    *one = dpOne[n];
}