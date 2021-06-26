#include <stdio.h>

#define MAX_SIZE 2
#define MAX_TARGET 10000

int numCase(int *arr, int n, int t);

int main() {



    return 0;
}

int numCase(int *arr, int n, int t) {
    int dp[MAX_SIZE][MAX_TARGET + 1];    

    dp[0][0] = 1;

    for (int i = 1; i <= t; i++)
        dp[0][i] = 0;

    


}