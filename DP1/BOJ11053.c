#include <stdio.h>

#define MAX_SIZE 1000

int max(int a, int b);
int maxSub(int *arr, int *dp, int n);
int LIS(int *arr, int n);

int main()
{
    int arr[MAX_SIZE];
    int N;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    printf("%d\n", LIS(arr, N));

    return 0;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int maxSub(int *arr, int *dp, int n)
{
    int max_ = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < arr[n])
            max_ = max(dp[i], max_);
    }
    return max_;
}

int LIS(int *arr, int n)
{
    int dp[MAX_SIZE];
    int ans = 0;

    dp[0] = 1;        

    for (int i = 1; i < n; i++) 
        dp[i] = maxSub(arr, dp, i) + 1;

    for (int i = 0; i < n; i++) 
        ans = max(dp[i], ans);

    return ans;
}