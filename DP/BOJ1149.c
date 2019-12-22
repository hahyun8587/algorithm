#include <stdio.h>

#define MAX_SIZE 1001
#define INF 1000000

int min(int a, int b);
int minCost(int (*cost)[3], int n);

int main()
{
    int cost[MAX_SIZE - 1][3];
    int N;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) 
            scanf("%d", &cost[i][j]);
    }
    printf("%d\n", minCost(cost, N));

    return 0;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int minCost(int (*cost)[3], int n)
{
    int dp[MAX_SIZE][3];

    for (int i = 0; i < 3; i++) 
        dp[0][i] = 0;

    for (int i = 1; i < MAX_SIZE; i++) {
        for (int j = 0; j < 3; j++) 
            dp[i][j] = INF;
    }            

    for (int i = 1; i < MAX_SIZE; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j != k) 
                    dp[i][k] = min(dp[i - 1][j] + cost[i - 1][k], dp[i][k]);
            }
        }
    }
    return min(min(dp[n][0], dp[n][1]), dp[n][2]);
}