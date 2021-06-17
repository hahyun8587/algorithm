#include <stdio.h>

#define MAX_SIZE 500

int _path(int (*arr)[MAX_SIZE], int n, int m, int (*dp)[MAX_SIZE], int x, int y);
int path(int (*arr)[MAX_SIZE], int n, int m);

int main() {
    int arr[MAX_SIZE][MAX_SIZE];
    int M, N;

    scanf("%d %d", &M, &N);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            scanf("%d", &arr[i][j]);
    }
    printf("%d\n", path(arr, M, N));

    return 0;
}

int _path(int (*arr)[MAX_SIZE], int n, int m, int (*dp)[MAX_SIZE], int x, int y) {
    if (dp[x][y] != -1)
        return dp[x][y];

    dp[x][y] = 0;

    for (int i = 0; i <= 3; i++) {
        int j = i ? i + x - 2 : x;
        int k = i < 3 ? i + y - 1 : y; 

        if (j >= 0 && j < n && k >= 0 && k < m) {
            if (arr[x][y] > arr[j][k])
                dp[x][y] += _path(arr, n, m, dp, j, k);
        }
    }
    return dp[x][y];
}

int path(int (*arr)[MAX_SIZE], int n, int m) {
    int dp[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            dp[i][j] = -1;
    }
    dp[n - 1][m - 1] = 1;

    return _path(arr, n, m, dp, 0, 0);
}