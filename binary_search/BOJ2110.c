#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 200001

typedef struct {
    int *ha;
    int n;
    int (*type)(int *, int, int);
} heap;

int ascn(int *arr, int i, int j);
heap* initHeap(int *arr, int n);
void swap(int *a, int *b);
void sink(heap *h);
void heapify(heap *h);
void delete(heap *h);
void heapSort(heap *h);
int check(int *arr, int n, int d, int c);
int max(int a, int b);
int _maxDist(int *arr, int n, int s, int e, int c);
int maxDist(int *arr, int n, int c);

int main() {
    heap *h;
    int arr[MAX_SIZE];
    int N, C;

    scanf("%d %d", &N, &C);

    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);

    h = initHeap(arr, N + 1);

    heapSort(h);
    free(h);
    printf("%d\n", maxDist(arr, N + 1, C));

    return 0;
}

int check(int *arr, int n, int d, int c) {
    int count = 1;    
    int ds = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] - arr[ds] >= d) {
            ds = i;
            count++;
        }
    }   
    return count >= c ? 1 : 0;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int _maxDist(int *arr, int n, int s, int e, int c) {
    if (s == e + 1)
        return 0;
    
    int mid = s + (e - s + 1) / 2;

    if (check(arr, n, mid, c)) 
        return max(_maxDist(arr, n, mid + 1, e, c), mid);
    else 
        return _maxDist(arr, n, s, mid - 1, c);    
}

int maxDist(int *arr, int n, int c) {
    return _maxDist(arr, n, 1, arr[n - 1] - arr[0], c);
}