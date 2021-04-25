#include <stdio.h>

#define MAX_SIZE 14

void initArr(int (*arr)[MAX_SIZE], int n);
void denote(int (*visited)[MAX_SIZE], int n, int x, int y, int val);
int nQueen(int (*visited)[MAX_SIZE], int n, int x, int y);

int main() {
    int N;
    int visited[MAX_SIZE][MAX_SIZE];
    int count = 0;

    scanf("%d", &N);
    initArr(visited, N);

    for (int i = 0; i < N; i++) 
        count += nQueen(visited, N, 0, i);

    printf("%d\n", count);    

    return 0;
}

void initArr(int (*arr)[MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            arr[i][j] = 0;
    }
}

void denote(int (*visited)[MAX_SIZE], int n, int x, int y, int val) {
    for (int i = x + 1; i < n; i++) {
        if (-i + x + y >= 0)
            visited[i][-i + x + y] += val;
        
        visited[i][y] += val;
        
        if (i - x + y < n)
            visited[i][i - x + y] += val;
    }   
}

int nQueen(int (*visited)[MAX_SIZE], int n, int x, int y) {
    if (x == n - 1) 
        return 1;

    int count = 0;

    denote(visited, n, x, y, 1);

    for (int i = 0; i < n; i++) {
        if (!visited[x + 1][i])
            count += nQueen(visited, n, x + 1, i);            
    }
    denote(visited, n, x, y, -1);

    return count;
}