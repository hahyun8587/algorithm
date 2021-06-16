#include <stdio.h>

#define MAX_SIZE 500
#define NUM_WAY 4

int _path(int (*arr)[MAX_SIZE], int n, int m, int (*dp)[MAX_SIZE], int x, int y);
int path(int (*arr)[MAX_SIZE], int n, int m);

int main() {



    return 0;
}

int _path(int (*arr)[MAX_SIZE], int n, int m, int (*dp)[MAX_SIZE], int x, int y) {
    if (dp[x][y] != -1)
        return dp[x][y];

    dp[x][y] = 0;

    for (int i = 0; i < NUM_WAY; i++) {
        if ()

    }





}