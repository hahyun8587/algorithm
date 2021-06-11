#include <stdio.h>

#define MAX_SIZE 500
#define INF 1252490000

int min(int a, int b);
int minCost(int *arr, int n);

int main() {



    return 0;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int minCost(int *arr, int n) {
    int dp[MAX_SIZE + 1][MAX_SIZE + 1];

    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= n; j++) 
            dp[i][j] = 0;
    }

    for (int i = 2; i <= n; i++) 
        dp[i][0] = 0;

    
    



}