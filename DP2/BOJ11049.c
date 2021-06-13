#include <stdio.h>

#define MAX_SIZE 500
#define DIM 2
#define INF 2147483647

int min(int a, int b);
int minOp(int (*arr)[DIM], int n);

int main() {



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

                
            }
        }
    }




}