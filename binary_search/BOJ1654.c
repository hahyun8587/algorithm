#include <stdio.h>

#define MAX_SIZE 10000

typedef long long ll;

int check(int *arr, int n, int mid, int t);
int max(int a, int b);
int _maxLen(int *arr, int n, ll s, int e, int t);
int maxLen(int *arr, int n, int t);

int main() {
    int arr[MAX_SIZE];
    int K, N;

    scanf("%d %d", &K, &N);

    for (int i = 0; i < K; i++)
        scanf("%d", &arr[i]);

    printf("%d\n", maxLen(arr, K, N));    

    return 0;
}

int check(int *arr, int n, int mid, int t) {
    ll sum = 0;

    for (int i = 0; i < n; i++) 
        sum += (ll) arr[i] / mid;

    return sum >= t ? 1 : 0;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int _maxLen(int *arr, int n, ll s, int e, int t) {
    if (s > e)
        return 0;
    
    int mid = s + (e - s + 1) / 2;

    if (check(arr, n, mid, t))
        return max(_maxLen(arr, n, (ll) mid + 1, e, t), mid);
    else 
        return _maxLen(arr, n, (ll) s, mid - 1, t);
}

int maxLen(int *arr, int n, int t) {
    int lim = arr[0];

    for (int i = 1; i < n; i++) 
        lim = max(arr[i], lim);

    return _maxLen(arr, n, 1, lim, t);
}