#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 30
#define MAX_WEI 40000

void valid(int *arr, int n, int (*dp)[MAX_WEI + 1]);

int main() {
    int dp[MAX_NUM + 1][MAX_WEI + 1];
    int arr[MAX_NUM];
    int N, M;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    valid(arr, N, dp);
    scanf("%d", &M);

    for (int i = 1; i <= M; i++) {
        int W;

        scanf("%d", &W);

        dp[N][W] ? printf("Y ") : printf("N ");
    }
    putchar('\n');

    return 0;
}

void valid(int *arr, int n, int (*dp)[MAX_WEI + 1]) {
    dp[0][0] = 1;

    for (int i = 1; i <= MAX_WEI; i++) 
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= MAX_WEI; j++) 
            dp[i][j] = dp[i - 1][j] || dp[i - 1][abs(j - arr[i - 1])] ? 1 : 0;
    }
}