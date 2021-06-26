#include <stdio.h>

#define MAX_CNUM 100
#define MAX_SIZE 2
#define MAX_TARGET 10000

int numCase(int *arr, int n, int k);

int main() {
    int arr[MAX_CNUM];
    int n, k;

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d\n", numCase(arr, n, k)); 
       
    return 0;
}

int numCase(int *arr, int n, int k) {
    int dp[MAX_SIZE][MAX_TARGET + 1];    

    dp[0][0] = 1;

    for (int i = 1; i <= k; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) 
            dp[i % 2][j] = dp[(i + 1) % 2][j] + (arr[i - 1] <= j ? dp[i % 2][j - arr[i - 1]] : 0);
    }
    return dp[n % 2][k];
}