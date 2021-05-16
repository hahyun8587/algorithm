#include <stdio.h>
#include <malloc.h>

#define NUM_AXIS 2
#define INF 200000000

typedef struct {
    int **ha;
    int n;
} heap;

heap* initHeap(int **arr, int n);
int maxHeap(int **arr, int i, int j);
void swap(int **a, int **b);
void sink(heap *h, int s, int (*type)(int **, int, int));
void heapify(heap *h);
void delete(heap *h);
void heapSort(heap *h);
int minLine(int (*arr)[NUM_AXIS], int l);
int min(int a, int b);
int minBound(int (*arr)[NUM_AXIS], int mid, int d);
int _minDist(int (*arr)[NUM_AXIS], int s, int e);
int minDist(int (*arr)[NUM_AXIS], int n);

int main() {



    return 0;
}

heap* initHeap(int **arr, int n) {
    heap *h;

    h = (heap *) malloc(sizeof(heap));
    h->ha = arr;
    h->n = n;
    
    return h;
}

int maxHeap(int **arr, int i, int j) {
    if (arr[i][0] > arr[j][0])
        return 0;
    else if (arr[i][0] == arr[j][0]) 
        return arr[i][1] >= arr[j][1] ? 0 : 1;    
    else 
        return 1;
}

void swap(int **a, int **b) {
    int *temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void sink(heap *h, int s, int (*type)(int **, int, int)) {
    int curr;
    int cmp;

    curr = s;

    while (curr / 2 <= h->n - 1) {
        cmp = !type(h->ha, curr / 2, curr / 2 + 1) ? curr / 2 : curr / 2 + 1;
        
        if (type(h->ha, curr, cmp)) {
            swap(&h->ha[curr], &h->ha[cmp]);

            curr = cmp;    
        }
    }
}

