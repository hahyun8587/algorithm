#include <stdio.h>

#define MAX_SIZE 1000000
#define DIVISOR 15746

int dp[MAX_SIZE];

int tile(int n);

int main()
{
    int N;
    
    scanf("%d", &N);
    printf("%d\n", tile(N));

    return 0;
}

int tile(int n)
{  
    dp[0] = 1;
    dp[1] = 2;

    for (int i = 2; i < MAX_SIZE; i++) 
        dp[i] = (dp[i - 2] + dp[i - 1]) % DIVISOR;

    return dp[n - 1]; 
}

