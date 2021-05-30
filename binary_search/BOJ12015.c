#include <stdio.h>

#define MAX_SIZE 1000000

int _BS(int *arr, int s, int e, int x);
int BS(int *arr, int n, int x);
int LIS(int *arr, int n);

int main() {



    return 0;
}

int _BS(int *arr, int s, int e, int x) {
    if (s == e + 1)
        return MAX_SIZE;
    
    int mid = s + (e - s + 1) / 2;

    if (x == arr[mid])
        return mid;
    else if (x < arr[mid]) 
        return 
    else 
        return _BS(arr, mid + 1, e, x);    
}

