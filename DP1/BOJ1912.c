#include <stdio.h>

#define MAX_NUM 100000
#define MIN_VAL -1000

int max(int a, int b);
int maxCSum(int *arr, int n);

int main() {
    int arr[MAX_NUM];
    int N;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    printf("%d\n", maxCSum(arr, N));

    return 0;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int maxCSum(int *arr, int n) {
    int dp[MAX_NUM + 1];
    int ans = MIN_VAL;

    dp[0] = 0;

    for (int i = 1; i <= n; i++) 
        dp[i] = max(arr[i - 1], arr[i - 1] + dp[i - 1]);

    for(int i = 1; i <= n; i++)
        ans = max(dp[i], ans);

    return ans;    
}