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
    int dp[MAX_SIZE + 1][LIMIT];
    
    dp[0][0] = 0;
    dp[0][1] = -1;
    dp[1][0] = score[0];
    dp[1][1] = -1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < LIMIT; j++) 
            dp[i][j] = !j ? max(dp[i - 2][j], dp[i - 2][j + 1]) + score[i - 1] : dp[i - 1][0] + score[i - 1];
    }
    return max(dp[n][0], dp[n][1]);
}