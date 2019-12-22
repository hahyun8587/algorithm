#include <stdio.h>

#define MAX_SIZE 500

int max(int a, int b);
int aMax(int *arr, int n);
int maxSum(int (*tri)[MAX_SIZE], int n);

int main()
{
    int tri[MAX_SIZE][MAX_SIZE];
    int n; 

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) 
            scanf("%d", &tri[i][j]);
    }
    printf("%d\n", maxSum(tri, n));

    return 0;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int aMax(int *arr, int n)
{
    int max_ = 0;

    for (int i = 0; i < n; i++) 
        max_ = max(arr[i], max_);

    return max_;
}

int maxSum(int (*tri)[MAX_SIZE], int n)
{
    int dp[MAX_SIZE][MAX_SIZE];

    dp[0][0] = tri[0][0];

    for (int i = 1; i < MAX_SIZE; i++) {
        for (int j = 0; j <= i; j++) 
            dp[i][j] = 0;
    }

    for (int i = 1; i < MAX_SIZE; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = j; k <= j + 1; k++) {
                dp[i][k] = max(dp[i - 1][j] + tri[i][k], dp[i][k]);
            }
        }
    }
    return aMax(dp[n - 1], n);
}