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
void sink(heap *h, int s);
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
    printf("%d\n", maxDist(&arr[1], N, C));

    return 0;
}

int ascn(int *arr, int i, int j) {
    return arr[i] > arr[j] ? 0 : 1;
}

heap* initHeap(int *arr, int n) {
    heap *h;

    h = (heap *) malloc(sizeof(heap));
    h->ha = arr;
    h->n = n;
    h->type = ascn;

    return h;
}

void swap(int *a, int *b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void sink(heap *h, int s) {
    int curr;
    int cmp;

    curr = s;

    while (curr * 2 <= h->n - 1) {
        if (curr * 2 == h->n - 1)
            cmp = curr * 2;
        else
            cmp = !h->type(h->ha, curr * 2, curr * 2 + 1) ? curr * 2 : curr * 2 + 1;
        
        if (h->type(h->ha, curr, cmp)) {
            swap(&h->ha[curr], &h->ha[cmp]);

            curr = cmp;    
        }
        else
            break;
    }
}

void heapify(heap *h) {
    for (int i = (h->n - 1) / 2; i >= 1; i--)
        sink(h, i);
}

void delete(heap *h) {
    swap(&h->ha[1], &h->ha[h->n-- - 1]);
    sink(h, 1);
}

void heapSort(heap *h) {
    int n = h->n;

    heapify(h);

    for (int i = 1; i < n; i++) 
        delete(h);  

    h->n = n; 
}

int check(int *arr, int n, int d, int c) {
    int ds = 0;
    int count = 1;    

    for (int i = 1; i < n; i++) {
        if (arr[i] - arr[ds] >= d) {
            ds = i;
            count++;
        }

        if (count == c)
            return 1;
    }   
    return 0;
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