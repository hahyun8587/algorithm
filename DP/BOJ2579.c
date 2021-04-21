#include <stdio.h>

#define MAX_SIZE 300
#define LIMIT 2

int max(int a, int b);
int maxScore(int *score, int n);

int main() {
    int N;
    int score[MAX_SIZE];

    scanf("%d", &N);

    for (int i = 0; i < N; i++) 
        scanf("%d", &score[i]);

    printf("%d\n", maxScore(score, N));    

    return 0;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int maxScore(int *score, int n) {
    int dp[MAX_SIZE + 1][LIMIT][MAX_SIZE + 1];
    int ans = 0;

    dp[0][0][0] = 0;

    for (int i = 0; i < LIMIT; i++) {
        for (int j = -i + 1; j <= n; j++)
            dp[0][i][j] = -1;
    }

    for (int i = 0; i < LIMIT; i++) {
        for (int j = 0; j <= n; j++) 
            dp[1][i][j] = !i && (j == 1 || j == 2) ? score[j - 1] : -1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < LIMIT; j++) {
            for (int k = 0; k <= -j + 1; k++) 
                dp[i][j][k] = -1;
        }
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < LIMIT; j++) {
            for (int k = -j + 2; k <= n; k++) {
                if (!j) {
                    if (dp[i - 1][j][k - 2] != -1 && dp[i - 1][j + 1][k - 2] != -1)
                        dp[i][j][k] = max(dp[i - 1][j][k - 2], dp[i - 1][j + 1][k - 2]) + score[k - 1];
                    else if (dp[i - 1][j][k - 2] == -1 && dp[i - 1][j + 1][k - 2] != -1)
                        dp[i][j][k] = dp[i - 1][j + 1][k - 2] + score[k - 1];
                    else if (dp[i - 1][j][k - 2] != -1 && dp[i - 1][j + 1][k - 2] == -1)
                        dp[i][j][k] = dp[i - 1][j][k - 2] + score[k - 1];
                    else 
                        dp[i][j][k] = -1;        
                }
                else 
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] != -1 ? dp[i - 1][j - 1][k - 1] + score[k - 1] : -1;
            }
        }
    }

    for (int i = n / 2; i <= n; i++) {
        for (int j = 0; j < LIMIT; j++) 
            ans = max(dp[i][j][n], ans);
    }
    return ans;
}