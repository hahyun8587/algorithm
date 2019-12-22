#include <stdio.h>

#define MAX_SIZE 1000000
#define INF 1000000

int dp[MAX_SIZE];

int min(int a, int b);
int minCalc(int n);

int main()
{
    int N;

    scanf("%d", &N);
    printf("%d\n", minCalc(N));

    return 0;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int minCalc(int n)
{
    for (int i = 1; i < MAX_SIZE; i++) 
        dp[i] = min(min((i + 1) % 2 ? INF : dp[(i + 1) / 2 - 1] + 1, (i + 1) % 3 ? INF : dp[(i + 1) / 3 - 1] + 1), dp[i - 1] + 1);

    return dp[n - 1];
}