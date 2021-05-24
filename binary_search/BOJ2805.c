#include <stdio.h>

#define MAX_SIZE 1000000

typedef long long ll;

int max(int a, int b);
int check(int *arr, int n, int mid, int t);
int _maxHei(int *arr, int n, int s, int e, int t);
int maxHei(int *arr, int n, int t);

int main() {
    int arr[MAX_SIZE];
    int N, M;

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) 
        scanf("%d", &arr[i]);

    printf("%d\n", maxHei(arr, N, M));

    return 0;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int check(int *arr, int n, int mid, int t) {   
    ll sum = 0;

    for (int i = 0; i < n; i++)
        sum += (ll) (arr[i] >= mid ? arr[i] - mid : 0);

    if (sum < t)
        return 0;
    else if (sum > t)
        return 1;
    else 
        return 2;        
}

int _maxHei(int *arr, int n, int s, int e, int t) {
    if (s > e)
        return -1;

    int mid = s + (e - s + 1) / 2;
    int occ;
    
    occ = check(arr, n, mid, t);
    
    switch (occ) {
        case 0 : return _maxHei(arr, n, s, mid - 1, t);
        case 1 : return max(_maxHei(arr, n, mid + 1, e, t), mid);
        case 2 : return mid;
    }
}

int maxHei(int *arr, int n , int t) {
    int val = arr[0];

    for (int i = 1; i < n; i++) 
        val = max(arr[i], val);

    return _maxHei(arr, n, 0, val - 1, t);    
}