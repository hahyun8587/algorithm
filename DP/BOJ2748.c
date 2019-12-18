#include <stdio.h>

#define MAX_SIZE 91

typedef long long ll;

ll fibo(int n);

int main() {
    int n;
    
    scanf("%d", &n);
    printf("%lld\n", fibo(n));

    return 0;
}

ll fibo(int n)
{
    ll dp[MAX_SIZE];

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i < MAX_SIZE; i++) 
        dp[i] = dp[i - 1] + dp[i - 2];
    
    return dp[n];
}