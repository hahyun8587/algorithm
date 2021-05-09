#include <stdio.h>

#define MAX_SIZE 100

void getArr2D(int (*arr)[MAX_SIZE], int *n, int *m);
void dot(int (*src1)[MAX_SIZE], int n, int m, int (*src2)[MAX_SIZE], int p, int o, int (*dst)[MAX_SIZE]);
void aprintf(int (*arr)[MAX_SIZE], int n, int m);

int main() {
    int arr1[MAX_SIZE][MAX_SIZE], arr2[MAX_SIZE][MAX_SIZE];
    int product[MAX_SIZE][MAX_SIZE];
    int N, M, K;

    getArr2D(arr1, &N, &M);
    getArr2D(arr2, &M, &K);
    dot(arr1, N, M, arr2, M, K, product);
    aprintf(product, N, K);

    return 0;
}

void getArr2D(int (*arr)[MAX_SIZE], int *n, int *m) {
    scanf("%d %d", n, m);

    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) 
            scanf("%d", &arr[i][j]);
    }   
}

void dot(int (*src1)[MAX_SIZE], int n, int m, int (*src2)[MAX_SIZE], int p, int o, int (*dst)[MAX_SIZE]) {
    int sum;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < o; j++) {
            sum = 0;

            for (int k = 0; k < p; k++) 
               sum += src1[i - 1][k] * src2[k][j]; 

            dst[i - 1][j] = sum;  
        }
    }
}

void aprintf(int (*arr)[MAX_SIZE], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            printf("%d ", arr[i][j]);

        putchar('\n');    
    }
}