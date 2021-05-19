#include <stdio.h>
#include <malloc.h>

#define INF 200000000

typedef struct {
    int **ha;
    int n;
    int (*type)(int **, int, int);
} heap;

int** mmalloc(int n, int m);
int ascn(int **arr, int i, int j);
heap* initHeap(int n, int m, int (*type)(int **, int, int));
void swap(int **a, int **b);
void sink(heap *h, int s);
void heapify(heap *h);
void delete(heap *h);
void heapSort(heap *h);
int dist(int **arr, int i, int j);
int min(int a, int b);
int minLane(int **arr, int s, int mid, int e);
int minBound(int **arr, int s, int mid, int e, int d);
int _minDist(int **arr, int *border, int s, int e);
int minDist(int **arr, int n);

int main() {



    return 0;
}

int** mmalloc(int n, int m) {
    int **arr;

    arr = (int **) malloc(sizeof(int *) * n);

    for (int i = 0; i < n; i++)
        arr[i] = (int *) malloc(sizeof(int) * m);

    return arr;    
}

int ascn(int **arr, int i, int j) {
    if (arr[i][0] > arr[j][0])
        return 0;
    else if (arr[i][0] == arr[j][0]) 
        return arr[i][1] >= arr[j][1] ? 0 : 1;    
    else 
        return 1;
}

heap* initHeap(int n, int m, int (*type)(int **, int, int)) {
    heap *h;
    
    h = (heap *) malloc(sizeof(heap));
    h->ha = mmalloc(n, m);
    h->n = n;
    h->type = type;
    
    return h;
}

void swap(int **a, int **b) {
    int *temp;

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
        
        if (type(h->ha, curr, cmp)) {
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
    heapify(h);

    for (int i = 1; i < h->n; i++) 
        delete(h);   
}

int dist(int **arr, int i, int j) {
    int a = arr[i][0] - arr[j][0];
    int b = arr[i][1] - arr[j][1];

    return a * a + b * b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int minLane(int **arr, int s, int mid, int e) {
    int curr;
    int left, right;
    int val = arr[s][0];
    int min = INF;

    








}