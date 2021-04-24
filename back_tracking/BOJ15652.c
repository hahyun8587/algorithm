#include <stdio.h>

#define MAX_SIZE 8

void aprintf(int *arr, int n);
int start(int a, int type);
void perm(int *visited, int n, int *dst, int m, int a, int count, int type, int dupl);

int main() {
    int N, M;
    int dst[MAX_SIZE];

    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) 
        perm(NULL, N, dst, M, i, 0, 1, 1);
    
    return 0;
}

void aprintf(int *arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    putchar('\n');
}

int start(int a, int type) {
    if (type == 0)
        return 0;
    else if (type == 1)
        return a - 1;
    else 
        return a;        
}

void perm(int *visited, int n, int *dst, int m, int a, int count, int type, int dupl) {
    dst[count] = a;
    
    if (visited)
        visited[a - 1] = 1;
    
    count++;    
    
    if (count == m) 
        aprintf(dst, m);
    else {
        for (int i = start(a, type); i < n; i++) {
            if (dupl || !visited[i])
                perm(visited, n, dst, m, i + 1, count, 1, 1);    
        }
    }

    if (visited)
        visited[a - 1] = 0;
}