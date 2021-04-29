#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20
#define INF 8910

int calc(int (*stats)[MAX_SIZE], int *teammate, int end);
int opSum(int (*stats)[MAX_SIZE], int *visited, int n);
int min(int a, int b);
void _MDS(int (*stats)[MAX_SIZE], int n, int *teammate, int m, int *visited, int *diff, int num, int sum);
int MDS(int (*arr)[MAX_SIZE], int n);

int main() {
    int N;
    int arr[MAX_SIZE][MAX_SIZE];

    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) 
            scanf("%d", &arr[i][j]);
    }
    printf("%d\n", MDS(arr, N));

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

void _MDS(int (*stats)[MAX_SIZE], int n, int *teammate, int m, int *visited, int *diff, int num, int sum) {
    teammate[m++] = num;
    visited[num - 1] = 1;
    sum += calc(stats, teammate, m);                

    if (m == n / 2) {
        *diff = min(abs(total - 2 * sum), *diff);
    }
    else {    
        for (int i = num + 1; i <= n; i++) 
            _MDS(stats, n, teammate, m, visited, diff, i, sum);
    }
    
}

int MDS(int (*arr)[MAX_SIZE], int n) {
    int teammate[MAX_SIZE / 2];
    int visited[MAX_SIZE];
    int diff = INF;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 1; i <= n / 2 + 1; i++) 
        _MDS(arr, n, teammate, 0, visited, &diff, i, 0);

    return diff;
}