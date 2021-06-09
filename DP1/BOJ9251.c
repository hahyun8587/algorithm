#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1001

int max(int a, int b);
int LCS(char *arr1, int n, char *arr2, int m);

int main() {
    char arr1[MAX_SIZE], arr2[MAX_SIZE];

    scanf("%s", arr1);
    scanf("%s", arr2);
    printf("%d\n", LCS(arr1, strlen(arr1), arr2, strlen(arr2)));

    return 0;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int LCS(char *arr1, int n, char *arr2, int m) {
    int dp[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
        dp[i][0] = 0;            

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            dp[i + 1][j + 1] = arr1[i] == arr2[j] ? dp[i][j] + 1 : max(dp[i][j + 1], dp[i + 1][j]);
    }
    return dp[n][m];
}