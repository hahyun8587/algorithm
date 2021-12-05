#include <stdio.h>

#define MAX_SIZE 91

typedef long long ll;

ll pinary(int n);

int main() {
    int N;

    scanf("%d", &N);
    printf("%lld\n", pinary(N));

    return 0;
}

ll pinary(int n) {
    ll dp[MAX_SIZE];

    dp[0] = 0LL;
    dp[2] = dp[1] = 1LL;

    for (int i = 3; i <= n; i++) {
        ll sum = 0LL;

        for (int j = i - 2; j >= 1; j--) 
            sum += dp[j];

        dp[i] = sum + 1LL;        
    }
    return dp[n];
}