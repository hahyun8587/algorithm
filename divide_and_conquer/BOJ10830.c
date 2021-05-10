#include <stdio.h>

#define MAX_SIZE 5
#define MODULOR 1000

typedef long long ll;

int product[MAX_SIZE][MAX_SIZE];

int (*dot(int (*arr1)[MAX_SIZE], int n, int m, int (*arr2)[MAX_SIZE], int p, int o))[MAX_SIZE];
int (*mmodulo(int (*arr)[MAX_SIZE], int n, int m, int c))[MAX_SIZE];
int (*mpow(int (*arr)[MAX_SIZE], int n, ll b))[MAX_SIZE];
void mprintf(int (*arr)[MAX_SIZE], int n, int m);

int main()
{
    int arr[MAX_SIZE][MAX_SIZE];
    int N;
    ll B;

    scanf("%d %lld", &N, &B);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) 
            scanf("%d", &arr[i][j]);
    }
    mprintf(mpow(arr, N, B), N, N);

    return 0;
}

int (*dot(int (*src1)[MAX_SIZE], int n, int m, int (*src2)[MAX_SIZE], int p, int o))[MAX_SIZE] {
    int sum;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < o; j++) {
            sum = 0;

            for (int k = 0; k < p; k++) 
               sum += src1[i - 1][k] * src2[k][j]; 

            product[i - 1][j] = sum;  
        }
    }
    return product;
}

int (*mmodulo(int (*arr)[MAX_SIZE], int n, int m, int c))[MAX_SIZE] {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            arr[i][j] %= c;
    }
    return arr;
}

int (*mpow(int (*arr)[MAX_SIZE], int n, ll b))[MAX_SIZE] {
    if (b == 1)
        return arr;

    int (*val)[MAX_SIZE];

    val = !(b % 2) ? mpow(arr, n, b / 2) : mpow(arr, n, (b - 1) / 2);     
   
    return !(b % 2) ? mmodulo(dot(val, n, n, val, n, n), n, n, MODULOR) : mmodulo(dot(mmodulo(dot(val, n, n, val, n, n), n, n, MODULOR), n, n, arr, n, n), n, n, MODULOR);
}

void mprintf(int (*arr)[MAX_SIZE], int n, int m) {
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < m; j++) 
            printf("%d ", arr[i][j]);

        putchar('\n');    
    }
}