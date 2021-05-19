#include <stdio.h>
#include <malloc.h>

#define NUM_TYPE 2
#define INF 200000000

typedef struct {
    int **ha;
    int n;
    int (**type)(int **, int, int, int);
} heap;

int** mmalloc(int n, int m);
int ascn(int **arr, int i, int j, int std);
int descn(int **arr, int i, int j, int std);
heap* initHeap(int **arr, int n, int nt);
void swap(int **a, int **b);
void sink(heap *h, int s, int order, int std);
void heapify(heap *h, int order, int std);
void delete(heap *h, int order, int std);
void heapSort(heap *h, int order, int std);
int dist(int **arr, int i, int j);
int min(int a, int b);
void freeHeap(heap *h);
int minBound(int **arr, int s, int mid, int e, int d);
int _minDist(int **arr, int s, int e);
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

int ascn(int **arr, int i, int j, int std) {
    if (arr[i][std] > arr[j][std])
        return 0;    
    else 
        return 1;
}

int descn(int **arr, int i, int j, int std) {
    if (arr[i][std] < arr[j][std])
        return 0;  
    else 
        return 1;
}   

heap* initHeap(int **arr, int n, int nt) {
    heap *h;
    int (*fp[]) (int **, int, int, int) = { ascn, descn };
    
    h = (heap *) malloc(sizeof(heap));
    h->ha = arr;
    h->n = n;
    h->type = (int (**)(int **, int, int, int)) malloc(sizeof(int (*)(int **, int, int, int)) * nt);
    
    for (int i = 0; i < nt; i++)
        h->type[i] = fp[i];

    return h;
}

void swap(int **a, int **b) {
    int *temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void sink(heap *h, int s, int order, int std) {
    int curr;
    int cmp;

    curr = s;

    while (curr * 2 <= h->n - 1) {
        if (curr * 2 == h->n - 1)
            cmp = curr * 2;
        else
            cmp = !h->type[order](h->ha, curr * 2, curr * 2 + 1, std) ? curr * 2 : curr * 2 + 1;
        
        if (h->type[order](h->ha, curr, cmp, std)) {
            swap(&h->ha[curr], &h->ha[cmp]);

            curr = cmp;    
        }
        else
            break;
    }
}

void heapify(heap *h, int order, int std) {
    for (int i = (h->n - 1) / 2; i >= 1; i--)
        sink(h, i, order, std);
}

void delete(heap *h, int order, int std) {
    swap(&h->ha[1], &h->ha[h->n-- - 1]);
    sink(h, 1, order, std);
}

void heapSort(heap *h, int order, int std) {
    heapify(h, order, std);

    for (int i = 1; i < h->n; i++) 
        delete(h, order, std);   
}

int dist(int **arr, int i, int j) {
    int a = arr[i][0] - arr[j][0];
    int b = arr[i][1] - arr[j][1];

    return a * a + b * b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

void freeHeap(heap *h) {
    free(h->type);
    free(h);
}

int minBound(int **arr, int s, int mid, int e, int d) {
    int mx = arr[mid][0];
    int bs = -1, be = -1;

    for (int i = s; i < mid; i++) {
        if (mx - arr[i][0] < d) {
            bs = i;    
            
            break;
        }
    }

    if (bs == -1)
        return INF;

    for (int i = e; i > mid; i--) {
        if (arr[i][0] - mx < d) {
            be = i;

            break;
        }
    }

    if (be == -1)
        return INF;

    heap *h;

    h = initHeap(&arr[bs - 1], be - bs + 2, NUM_TYPE);

    heapSort(h, 0, 1);

    for (int i = bs; i < be; i++) {
        for (int j = i + 1; j <= be; j++) {
            if (arr[j][1] - arr[i][1] < d)
                d = min(dist(arr, i, j), d);
            else 
                break;    
        }
    }
    freeHeap(h);

    return d;
}