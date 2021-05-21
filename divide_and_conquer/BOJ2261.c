#include <stdio.h>
#include <malloc.h>

#define NUM_AXIS 2
#define NUM_TYPE 1
#define INF 200000000

typedef struct {
    int **ha;
    int n;
    int (**type)(int **, int, int, int);
} heap;

int** mmalloc(int n, int m);
int vascn(int **arr, int i, int j, int std);
int cascn(int **arr, int i, int j, int std);
heap* initHeap(int **arr, int n, int nt);
void swap(int **a, int **b);
void sink(heap *h, int s, int dim, int std);
void heapify(heap *h, int dim, int std);
void delete(heap *h, int dim, int std);
void heapSort(heap *h, int dim, int std);
void freeHeap(heap *h);
int dist(int **arr, int i, int j);
int min(int a, int b);
int minBound(int **arr, int s, int mid, int e, int d);
int _minDist(int **arr, int s, int e);
int minDist(int **arr, int n);
void mfree(int **arr, int n);

int main() {
    int **arr;
    int n;

    scanf("%d", &n);

    arr = mmalloc(n + 1, NUM_AXIS);

    for (int i = 1; i <= n; i++)
        scanf("%d %d", &arr[i][0], &arr[i][1]);

    printf("%d\n", minDist(arr, n + 1));
    mfree(arr, n + 1);

    return 0;
}

int** mmalloc(int n, int m) {
    int **arr;

    arr = (int **) malloc(sizeof(int *) * n);

    for (int i = 0; i < n; i++)
        arr[i] = (int *) malloc(sizeof(int) * m);

    return arr;    
}

int vascn(int **arr, int i, int j, int std) {
    if (arr[i][std] > arr[j][std])
        return 0;    
    else 
        return 1;
}

int cascn(int **arr, int i, int j, int std) {
    if (arr[i][std] > arr[j][std])
        return 0; 
    else if (arr[i][std] == arr[j][std]) 
        return arr[i][-std + 1] > arr[j][-std + 1] ? 0 : 1;
    else 
        return 1;
}   

heap* initHeap(int **arr, int n, int nt) {
    heap *h;
    int (*fp[]) (int **, int, int, int) = { vascn, cascn };
    
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

void sink(heap *h, int s, int dim, int std) {
    int curr;
    int cmp;

    curr = s;

    while (curr * 2 <= h->n - 1) {
        if (curr * 2 == h->n - 1)
            cmp = curr * 2;
        else
            cmp = !h->type[dim](h->ha, curr * 2, curr * 2 + 1, std) ? curr * 2 : curr * 2 + 1;
        
        if (h->type[dim](h->ha, curr, cmp, std)) {
            swap(&h->ha[curr], &h->ha[cmp]);

            curr = cmp;    
        }
        else
            break;
    }
}

void heapify(heap *h, int dim, int std) {
    for (int i = (h->n - 1) / 2; i >= 1; i--)
        sink(h, i, dim, std);
}

void delete(heap *h, int dim, int std) {
    swap(&h->ha[1], &h->ha[h->n-- - 1]);
    sink(h, 1, dim, std);
}

void heapSort(heap *h, int dim, int std) {
    int n = h->n;

    heapify(h, dim, std);

    for (int i = 1; i < n; i++) 
        delete(h, dim, std);  

    h->n = n; 
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

    h = initHeap(&arr[mid], be - mid + 1, NUM_TYPE);

    heapSort(h, 0, 1);

    for (int i = bs; i < be; i++) {
        for (int j = i + 1; j <= be; j++) {
            if (arr[j][1] - arr[i][1] < d) 
                d = min(dist(arr, i, j), d);
            else 
                break;
        }
    }
    heapSort(h, 0, 0);
    freeHeap(h);

    return d;
}

int _minDist(int **arr, int s, int e) {
    if (e - s + 1 == 2)
        return dist(arr, s, e);

    int mid = s + (e - s + 1) / 2;
    int d;

    d = min(_minDist(arr, s, mid), _minDist(arr, mid, e));

    return min(minBound(arr, s, mid, e, d), d);        
}

int minDist(int **arr, int n) {
    heap *h;

    h = initHeap(arr, n, NUM_TYPE);

    heapSort(h, 1, 0);
    freeHeap(h);

    for (int i = 2; i < n; i++) {
        if (arr[i - 1][0] == arr[i][0] && arr[i - 1][1] == arr[i][1])
            return 0;
    }
    return _minDist(arr, 1, n - 1);
}

void mfree(int **arr, int n) {
    for (int i = 0; i < n; i++)
        free(arr[i]);

    free(arr);    
}