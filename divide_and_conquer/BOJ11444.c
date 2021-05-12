#include <stdio.h>

#define MODULOR 1000000007
#define ARR_SIZE 2

typedef long long ll;

void copy(ll (*src)[ARR_SIZE], int n, int m, ll (*dst)[ARR_SIZE]);
ll (*dot(ll (*src1)[ARR_SIZE], int n, int m, ll (*src2)[ARR_SIZE], int p, int o))[ARR_SIZE];
ll (*mpow(ll (*arr)[ARR_SIZE], int n, ll b))[ARR_SIZE];
int fibo(ll n);

int main() {
    ll n;

    scanf("%lld", &n);
    printf("%d\n", fibo(n));

    return 0;
}

void copy(ll (*src)[ARR_SIZE], int n, int m, ll (*dst)[ARR_SIZE]){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            dst[i][j] = src[i][j];
    }    
}

ll (*dot(ll (*src1)[ARR_SIZE], int n, int m, ll (*src2)[ARR_SIZE], int p, int o))[ARR_SIZE] {
    static ll product[ARR_SIZE][ARR_SIZE];
    ll oprnd1[ARR_SIZE][ARR_SIZE], oprnd2[ARR_SIZE][ARR_SIZE];
    ll sum;

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

ll (*mpow(ll (*arr)[ARR_SIZE], int n, ll b))[ARR_SIZE] {
    if (b == 1) 
        return arr;

    ll (*val)[ARR_SIZE];

    val = !(b % 2) ? mpow(arr, n, b / 2) : mpow(arr, n, (b - 1) / 2);     

    return !(b % 2) ? dot(val, n, n, val, n, n) : dot(dot(val, n, n, val, n, n), n, n, arr, n, n);
}

int fibo(ll n) {
    ll arr[ARR_SIZE][ARR_SIZE] = {{1LL, 1LL}, {1LL, 0LL}};
    ll (*product)[ARR_SIZE];

    product = mpow(arr, ARR_SIZE, n);
    
    return (int) product[0][1];
}