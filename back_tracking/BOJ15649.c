#include <stdio.h>

#define MAX_SIZE 8

void aprintf(int *arr, int n);
void perm(int *visited, int n, int *dst, int m, int a, int count);

int main() {
    


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
