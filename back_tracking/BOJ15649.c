#include <stdio.h>

#define MAX_SIZE 8

void aprintf(int *arr, int n);
void perm(int *visited, int n, int *dst, int m, int a, int count);

int main() {
    int N, M;
    int visited[MAX_SIZE];
    int dst[MAX_SIZE];

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) 
        visited[i] = 0;

    for (int i = 1; i <= N; i++) 
        perm(visited, N, dst, M, i, 0);
    
    return 0;
}

void aprintf(int *arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    putchar('\n');
}

void perm(int *visited, int n, int *dst, int m, int a, int count) {
    dst[count] = a;
    visited[a - 1] = 1;
    count++;    

    if (count == m) 
        aprintf(dst, m);
    else {
        for (int i = 0; i < n; i++) {
            if (!visited[i])
                perm(visited, n, dst, m, i + 1, count);    
        }
    }
    visited[a - 1] = 0;
}
