#include <stdio.h>

#define MAX_SIZE 5
#define MODULOR 1000

typedef long long ll;

int (*dot(int (*arr1)[MAX_SIZE], int n, int m, int (*arr2)[MAX_SIZE], int p, int o))[MAX_SIZE];
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
    static int product[MAX_SIZE][MAX_SIZE];
    int sum;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < o; j++) {
            sum = 0;

            for (int k = 0; k < p; k++) {
                sum += src1[i - 1][k] * src2[k][j]; 
                printf("%d\n", sum); 
            }
            product[i - 1][j] = sum; 
        }
    }
    return product;
}

int (*mpow(int (*arr)[MAX_SIZE], int n, ll b))[MAX_SIZE] {
    if (b == 1)
        return arr;

    int (*val)[MAX_SIZE];

    val = !(b % 2) ? mpow(arr, n, b / 2) : mpow(arr, n, (b - 1) / 2);     

    //mprintf(val, n, n);

    return !(b % 2) ? dot(val, n, n, val, n, n) : dot(dot(val, n, n, val, n, n), n, n, arr, n, n);
}

void mprintf(int (*arr)[MAX_SIZE], int n, int m) {
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < m; j++) 
            printf("%d ", arr[i][j]);

        putchar('\n');    
    }
}