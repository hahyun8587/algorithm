#include <stdio.h>

#define MAX_SIZE 5
#define MODULOR 1000

typedef long long ll;

int (*mmodulo(int (*arr)[MAX_SIZE], int n, int m, int c))[MAX_SIZE];
void copy(int (*src)[MAX_SIZE], int n, int m, int (*dst)[MAX_SIZE]);
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

int (*mmodulo(int (*arr)[MAX_SIZE], int n, int m, int c))[MAX_SIZE] {
    static int result[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            result[i][j] = arr[i][j] % c; 
    }
    return result;
}

void copy(int (*src)[MAX_SIZE], int n, int m, int (*dst)[MAX_SIZE]){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            dst[i][j] = src[i][j];
    }    
}

int (*dot(int (*src1)[MAX_SIZE], int n, int m, int (*src2)[MAX_SIZE], int p, int o))[MAX_SIZE] {
    static int product[MAX_SIZE][MAX_SIZE];
    int oprnd1[MAX_SIZE][MAX_SIZE], oprnd2[MAX_SIZE][MAX_SIZE];
    int sum;

    copy(src1, n, m, oprnd1);
    copy(src2, p, o, oprnd2);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < o; j++) {
            sum = 0;

            for (int k = 0; k < p; k++) 
                sum += oprnd1[i - 1][k] * oprnd2[k][j]; 
            
            product[i - 1][j] = sum % MODULOR; 
        }
    }
    return product;
}

int (*mpow(int (*arr)[MAX_SIZE], int n, ll b))[MAX_SIZE] {
    if (b == 1) 
        return mmodulo(arr, n, n, MODULOR);

    int (*val)[MAX_SIZE];

    val = !(b % 2) ? mpow(arr, n, b / 2) : mpow(arr, n, (b - 1) / 2);     

    return !(b % 2) ? dot(val, n, n, val, n, n) : dot(dot(val, n, n, val, n, n), n, n, arr, n, n);
}

void mprintf(int (*arr)[MAX_SIZE], int n, int m) {
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < m; j++) 
            printf("%d ", arr[i][j]);

        putchar('\n');    
    }
}