#include <stdio.h>

#define MAX_SIZE 10000
#define NUM_TYPE 3

int max(int a, int b);
int maxAmnt(int *amnt, int n);

int main()
{
    int n;
    int amnt[MAX_SIZE];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &amnt[i]);

    printf("%d\n", maxAmnt(amnt, n));    

    return 0;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int maxAmnt(int *amnt, int n)
{
    if (n == 1)
        return amnt[0];
    else if (n == 2)
        return amnt[0] + amnt[1];    

    int dp[MAX_SIZE - 2][NUM_TYPE];

    dp[0][0] = amnt[0] + amnt[1];
    dp[0][1] = amnt[0] + amnt[2];
    dp[0][2] = amnt[1] + amnt[2];

    for (int i = 1; i <= n - 3; i++) {
        for (int j = 0; j < NUM_TYPE; j++) 
            dp[i][j] = j ? dp[i - 1][j - 1] + amnt[i + 2] : max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]); 
    }
    return max(max(dp[n - 3][0], dp[n - 3][1]), dp[n - 3][2]);
}
