#include <stdio.h>

#define MAX_SIZE 100

typedef long long ll;

ll padovan(int n);

int main()
{
    int T;

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N;

        scanf("%d", &N);
        printf("%lld\n", padovan(N));
    }
    return 0;
}

ll padovan(int n)
{
    ll dp[MAX_SIZE];

    dp[0] = dp[1] = dp[2] = 1;
    dp[3] = dp[4] = 2;

    for (int i = 5; i < MAX_SIZE; i++)
        dp[i] = dp[i - 5] + dp[i - 1];

    return dp[n - 1];   
}