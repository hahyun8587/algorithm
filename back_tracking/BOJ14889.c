#include <stdio.h>

#define MAX_SIZE 20

int calc(int (*stats)[MAX_SIZE], int *teammate, int end);
int min(int a, int b);
void _MDS(int (*stats)[MAX_SIZE], int *visited, int n, int *teammate, int m, int *diff, int num, int sum, int total);
void MDS(int (*src)[MAX_SIZE], int *dst);

int main() {



    return 0;
}

int calc(int (*stats)[MAX_SIZE], int *teammate, int n) {
    int sum = 0;

    for (int i = 0; i <= n - 2; i++) 
        sum += stats[teammate[i] - 1][teammate[n - 1] - 1] + stats[teammate[n - 1] - 1][teammate[i] - 1];

    return sum;
}

int min(int a, int b) {
    return a < b ? a : b;
}

void _MDS(int (*stats)[MAX_SIZE], int *visited, int n, int *teammate, int m, int *diff, int num, int sum, int total) {
    teammate[++m - 1] = num;
    sum += calc(stats, teammate, m);                

    



}
