#include <stdio.h>

#define MAX_SIZE 1000

int forward(int a, int b);
int backward(int a, int b);
int max(int a, int b);
void LIS(int *arr, int n, int *dp, int reverse);
int LBS(int *arr, int n);

int main() {
    int arr[MAX_SIZE];
    int N;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    printf("%d\n", LBS(arr, N));

    return 0;
}

int forward(int a, int b) {
    return a <= b ? 1 : 0;
}

int backward(int a, int b) {
    return a >= b ? 1 : 0;
}

int max(int a, int b) {
    return a > b ? a : b;
}

void LIS(int *arr, int n, int *dp, int reverse) {
    int (*fp[])(int, int) = { forward, backward };

    dp[0] = 0;
    dp[(n - 1) * reverse + 1] = 1;

    for (int i = (n - 3) * reverse + 2; fp[reverse](i, n - (n - 1) * reverse); i += -2 * reverse + 1) {
        int val = 0;

        for (int j = (n - 1) * reverse; fp[reverse](j, i - 2 + 2 * reverse); j += -2 * reverse + 1) {
            if (arr[i - 1] > arr[j])
                val = max(dp[j + 1], val);               
        }
        dp[i] = val + 1;
    }        
}

int LBS(int *arr, int n) {
    int dp1[MAX_SIZE + 1], dp2[MAX_SIZE + 1];
    int ans = 0;

    LIS(arr, n, dp1, 0);
    LIS(arr, n, dp2, 1);

    for (int i = 1; i <= n; i++)
        ans = max(dp1[i] + dp2[i] - 1, ans);

    return ans;
}