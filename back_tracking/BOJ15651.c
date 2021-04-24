#include <stdio.h>

#define MAX_SIZE 7

void aprintf(int *arr, int n);
void perm(int *visited, int n, int *dst, int m, int a, int count, int ascn, int dupl);

int main() {
    int N, M;
    int dst[MAX_SIZE];

    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) 
        perm(NULL, N, dst, M, i, 0, 0, 1);
    
    return 0;
}

void aprintf(int *arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    putchar('\n');
}

void perm(int *visited, int n, int *dst, int m, int a, int count, int ascn, int dupl) {
    dst[count] = a;
    
    if (visited)
        visited[a - 1] = 1;
    
    count++;    
    
    if (count == m) 
        aprintf(dst, m);
    else {
        for (int i = a * ascn; i < n; i++) {
            if (dupl || !visited[i])
                perm(visited, n, dst, m, i + 1, count, 0, 1);    
        }
    }

    if (visited)
        visited[a - 1] = 0;
}