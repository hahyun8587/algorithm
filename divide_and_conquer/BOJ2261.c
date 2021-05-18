#include <stdio.h>
#include <malloc.h>

#define INF 200000000

typedef struct {
    int **ha;
    int n;
    int (*type)(int **, int, int);
} heap;

int ascn(int **arr, int i, int j);
heap* initHeap(int **arr, int n, int (*type)(int **, int, int));
void swap(int **a, int **b);
void sink(heap *h, int s);
void heapify(heap *h);
void delete(heap *h);
void heapSort(heap *h);
int minLane(int **arr, int l);
int min(int a, int b);
int minBound(int **arr, int mid, int d);
int _minDist(int **arr, int s, int e);
int minDist(int **arr, int n);

int main() {



    return 0;
}

int ascn(int **arr, int i, int j) {
    if (arr[i][0] > arr[j][0])
        return 0;
    else if (arr[i][0] == arr[j][0]) 
        return arr[i][1] >= arr[j][1] ? 0 : 1;    
    else 
        return 1;
}

heap* initHeap(int **arr, int n, int (*type)(int **, int, int)) {
    heap *h;
    
    h = (heap *) malloc(sizeof(heap));
    h->ha = arr;
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

int minLane(int **arr, int l) {




}