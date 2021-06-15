#include <stdio.h>

#define MAX_SIZE 500
#define DIM 2
#define INF 2147483647

int min(int a, int b);
int minOp(int (*arr)[DIM], int n);

int main() {
    int arr[MAX_SIZE][DIM];
    int N;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d %d", &arr[i][0], &arr[i][1]);

    printf("%d\n", minOp(arr, N));        

    return 0;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int minOp(int (*arr)[DIM], int n) {
    int dp[MAX_SIZE + 1][MAX_SIZE + 1];

    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= n; j++) 
            dp[i][j] = 0;
    }

    for (int i = 2; i <= n; i++)   
        dp[i][0] = 0;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i + j - 2 > n - 1)
                dp[i][j] = 0;
            else {
                int val = INF;

                for (int k = 0; k <= i - 2; k++) 
                    val = min(dp[k + 1][j] + dp[i - k - 1][j + k + 1] + arr[j - 1][0] * arr[j + k][0] * arr[i + j - 2][1], val);

                dp[i][j] = val;
            }
        }
    }
    return dp[n][1];
}