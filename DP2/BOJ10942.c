#include <stdio.h>

#define MAX_SIZE 2000

void palin(int *arr, int n, int (*dp)[MAX_SIZE + 1]);

int main() {



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
        for (int j = 1; j <= n; j++) {
            if (i + j - 1 > n)
                dp[i][j] = 0;           
            else { 
                if (dp[i - 2][j + 1] && arr[j - 1] == arr[i + j - 2])
                    dp[i][j] = 1;
            }
        }
    }
}