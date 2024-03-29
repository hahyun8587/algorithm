#include <stdio.h>
#include <stdlib.h>

#define MAX_PNUM 30
#define MAX_MWEI 40000
#define MAX_MNUM 7
#define MAX_PWEI 500

void valid(int *arr, int n, int (*dp)[MAX_MWEI + 1]);

int main() {
    int dp[MAX_PNUM + 1][MAX_MWEI + 1];
    int pw[MAX_PNUM], mw[MAX_MNUM];
    int N, M;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &pw[i]);

    valid(pw, N, dp);
    scanf("%d", &M);

    for (int i = 0; i < M; i++)
        scanf("%d", &mw[i]);

    for (int i = 0; i < M; i++) 
        dp[N][mw[i]] ? printf("Y ") : printf("N ");

    putchar('\n');

    return 0;
}

void valid(int *arr, int n, int (*dp)[MAX_MWEI + 1]) {
    dp[0][0] = 1;

    for (int i = 1; i <= MAX_MWEI; i++) 
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= MAX_MWEI; j++) {
            if (j > MAX_PNUM * MAX_PWEI)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][abs(j - arr[i - 1])] || dp[i - 1][j + arr[i - 1]] ? 1 : 0;
        }
    }
}