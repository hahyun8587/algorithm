#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20
#define INF 8910

int calc(int (*stats)[MAX_SIZE], int *teammate, int end);
int min(int a, int b);
void _MDS(int (*stats)[MAX_SIZE], int n, int *teammate, int m, int *diff, int num, int sum, int total);
int MDS(int (*arr)[MAX_SIZE], int n);

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

void _MDS(int (*stats)[MAX_SIZE], int n, int *teammate, int m, int *diff, int num, int sum, int total) {
    teammate[m++] = num;
    sum += calc(stats, teammate, m);                
   
    if (m == n / 2) 
        *diff = min(abs(total - 2 * sum), *diff);
    else {    
        for (int i = num + 1; i <= n; i++) 
            _MDS(stats, n, teammate, m, diff, i, sum, total);
    }
}

int MDS(int (*arr)[MAX_SIZE], int n) {
    int total = 0;
    int diff = INF;



}