#include <stdio.h>

#define MAX_ANUM 100 
#define MAX_SIZE 2
#define MAX_MEM 10000000
#define INF 10000

int min(int a, int b);
int minCost(int *byte, int n, int *cost, int m);

int main() {
    int byte[MAX_ANUM], cost[MAX_ANUM];
    int N, M;

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
        scanf("%d", &byte[i]);

    for (int i = 0; i < N; i++)
        scanf("%d", &cost[i]);

    printf("%d\n", minCost(byte, N, cost, M));    

    return 0;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int minCost(int *byte, int n, int *cost, int m) {
    int dp[MAX_SIZE][MAX_MEM + 1];

    dp[0][0] = 0;

    for (int i = 1; i <= m; i++)
        dp[0][i] = INF;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++)
            dp[i % 2][j] = min(dp[(i + 1) % 2][j], cost[i - 1] + (byte[i - 1] < j ? dp[(i + 1) % 2][j - byte[i - 1]] : 0));
    }
    return dp[n % 2][m];
}