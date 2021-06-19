#include <stdio.h>

#define MAX_SIZE 2000

void palin(int *arr, int n, int (*dp)[MAX_SIZE + 1]);

int main() {
    int dp[MAX_SIZE + 1][MAX_SIZE + 1];
    int arr[MAX_SIZE];
    int N;
    int M;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    palin(arr, N, dp);
    scanf("%d", &M);

    for (int i = 1; i <= M; i++) {
        int S, E;

        scanf("%d %d", &S, &E);
        printf("%d\n", dp[E - S + 1][S]);
    }
    return 0;
}

void palin(int *arr, int n, int (*dp)[MAX_SIZE + 1]) {
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= n; j++)
            dp[i][j] = 1;
    }

    for (int i = 2; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) 
            dp[i][j] = i + j - 1 <= n && dp[i - 2][j + 1] && arr[j - 1] == arr[i + j - 2] ? 1 : 0;
    }
}