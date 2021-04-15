#include <stdio.h>

#define MAX_SIZE 10

int minCoin(int *arr, int n, int k);

int main() {
    int A[MAX_SIZE];
    int N, K;

    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    printf("%d\n", minCoin(A, N, K));

    return 0;
}

int minCoin(int *arr, int n, int k) {
    int ans = 0;

    for (int i = n - 1; k; i--) {
        ans += k / arr[i];
        k %= arr[i];
    }
    return ans;
}