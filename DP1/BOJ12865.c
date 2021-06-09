#include <stdio.h>

#define MAX_NUM 100
#define MAX_WEIGHT 100000

int max(int a, int b);
int maxVal(int (*arr)[2], int n, int k);

int main() {
    int arr[MAX_NUM][2];
    int N, K;

    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++)
        scanf("%d %d", &arr[i][0], &arr[i][1]);

    printf("%d\n", maxVal(arr, N, K));

    return 0;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int maxVal(int (*arr)[2], int n, int k) {
    int dp[MAX_NUM + 1][MAX_WEIGHT + 1];

    for (int i = 0; i <= k; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
        dp[i][0] = 0;    

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) 
            dp[i][j] = arr[i - 1][0] <= j ? max(arr[i - 1][1] + dp[i - 1][j - arr[i - 1][0]], dp[i - 1][j]) : dp[i - 1][j]; 
    }
    return dp[n][k];
}