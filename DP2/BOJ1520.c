#include <stdio.h>

#define MAX_SIZE 500

int _path(int (*arr)[MAX_SIZE], int n, int m, int (*dp)[MAX_SIZE], int x, int y);
int path(int (*arr)[MAX_SIZE], int n, int m);

int main() {



    return 0;
}

int _path(int (*arr)[MAX_SIZE], int n, int m, int (*dp)[MAX_SIZE], int x, int y) {
    if (dp[x][y] != -1)
        return dp[x][y];

    dp[x][y] = 0;

    for (int i = 0; i <= 3; i++) {
        int j = i ? i + x : x;
        int k = i < 3 ? i + y - 1 : y; 

        if (j >= 0 && j < n && k >= 0 && k < m) {
            if (arr[x][y] > arr[j][k])
                dp[x][y] += _path(arr, n, m, dp, j, k);
        }
    }
    return dp[x][y];
}

int path(int (*arr)[MAX_SIZE], int n, int m) {
    



}