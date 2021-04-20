#include <stdio.h>

#define MAX_SIZE 300
#define LIMIT 2

int max(int a, int b);
int maxScore(int (*dp)[LIMIT][MAX_SIZE + 1], int n, int *score);

int main() {




    return 0;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int maxScore(int (*dp)[LIMIT][MAX_SIZE + 1], int n, int *score) {
    int ans;

    dp[0][0][0] = 0;

    for (int i = 0; i < LIMIT; i++) {
        for (int j = -i + 1; j < n; j++)
            dp[0][i][j] = -1;
    }

    for (int i = 1; i <= n - 2; i++) {
        for (int j = 0; j < LIMIT; j++) {
            for (int k = 0; k <= -j + 1; k++) 
                dp[i][j][k] = -1;
        }
    }

    for (int i = 1; i <= n - 2; i++) {
        for (int j = 0; j < LIMIT; j++) {
            for (int k = -j + 2; k < n; k++) {
                if (!j) {
                    if (dp[i - 1][j][k - 2] != -1 && dp[i - 1][j + 1][k - 2] != -1)
                        dp[i][j][k] = max(dp[i - 1][j][k - 2], dp[i - 1][j + 1][k - 2]) + score[k - 1];
                        
                }
            }
        }
    }
    






}