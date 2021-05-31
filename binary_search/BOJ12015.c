#include <stdio.h>

#define MAX_SIZE 1000000

int min(int a, int b);
int _BS(int *arr, int s, int e, int x);
int BS(int *arr, int n, int x);
int LIS(int *arr, int n);

int main() {
    int arr[MAX_SIZE];
    int N;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    printf("%d\n", LIS(arr, N));    

    return 0;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int _BS(int *arr, int s, int e, int x) {
    if (s == e + 1)
        return MAX_SIZE;
    
    int mid = s + (e - s + 1) / 2;

    if (x == arr[mid])
        return mid;
    else if (x < arr[mid]) 
        return min(_BS(arr, s, mid - 1, x), mid);
    else 
        return _BS(arr, mid + 1, e, x);    
}

int BS(int *arr, int n, int x) {
    return _BS(arr, 0, n - 1, x);
}

int LIS(int *arr, int n) {
    int ia[MAX_SIZE];
    int size = 1;

    ia[0] = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > ia[size - 1])
            ia[size++] = arr[i];
        else
            ia[BS(ia, size, arr[i])] = arr[i];
    }
    return size;
}