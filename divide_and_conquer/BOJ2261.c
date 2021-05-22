#include <stdio.h>
#include <malloc.h>

#define NUM_AXIS 2
#define INF 200000000
#define MAX_SIZE 100001

typedef struct {
    int **ha;
    int n;
    int (*type)(int **, int, int, int);
} heap;

int** mmalloc(int n, int m);
int ascn(int **arr, int i, int j, int std);
heap* initHeap(int **arr, int n);
void swap(int **a, int **b);
void sink(heap *h, int s, int std);
void heapify(heap *h, int std);
void delete(heap *h, int std);
void heapSort(heap *h, int std);
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

int ascn(int **arr, int i, int j, int std) {
    return arr[i][std] > arr[j][std] ? 0 : 1;
}

heap* initHeap(int **arr, int n) {
    heap *h;
        
    h = (heap *) malloc(sizeof(heap));
    h->ha = arr;
    h->n = n;
    h->type = ascn;

    return h;
}

void swap(int **a, int **b) {
    int *temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void sink(heap *h, int s, int std) {
    int curr;
    int cmp;

    curr = s;

    while (curr * 2 <= h->n - 1) {
        if (curr * 2 == h->n - 1)
            cmp = curr * 2;
        else
            cmp = !h->type(h->ha, curr * 2, curr * 2 + 1, std) ? curr * 2 : curr * 2 + 1;
        
        if (h->type(h->ha, curr, cmp, std)) {
            swap(&h->ha[curr], &h->ha[cmp]);

            curr = cmp;    
        }
        else
            break;
    }
}

void heapify(heap *h, int std) {
    for (int i = (h->n - 1) / 2; i >= 1; i--)
        sink(h, i, std);
}

void delete(heap *h, int std) {
    swap(&h->ha[1], &h->ha[h->n-- - 1]);
    sink(h, 1, std);
}

void heapSort(heap *h, int std) {
    int n = h->n;

    heapify(h, std);

    for (int i = 1; i < n; i++) 
        delete(h, std);  

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

int minBound(int **arr, int s, int mid, int e, int d) {
    int mx = arr[mid][0];
    int bs = -1, be = -1;

    for (int i = s; i < mid; i++) {
        int xd = mx - arr[i][0];

        if (xd * xd < d) {
            bs = i;    
            
            break;
        }
    }

    if (bs == -1)
        return INF;

    for (int i = e; i > mid; i--) {
        int xd = arr[i][0] - mx;

        if (xd * xd < d) {
            be = i;

            break;
        }
    }

    if (be == -1)
        return INF;

    heap *h;
    int *temp[MAX_SIZE];

    for (int i = bs; i <= be; i++) 
        temp[i - bs + 1] = arr[i];

    h = initHeap(temp, be - bs + 2);

    heapSort(h, 1);

    for (int i = 1; i <= be - bs; i++) {
        for (int j = i + 1; j <= be - bs + 1; j++) {
            int yd = temp[j][1] - temp[i][1];

            if (yd * yd < d) 
                d = min(dist(temp, i, j), d);
            else 
                break;
        }
    }
    free(h);

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
    
    h = initHeap(arr, n);
    
    heapSort(h, 0);
    free(h);

    return _minDist(arr, 1, n - 1);
}

void mfree(int **arr, int n) {
    for (int i = 0; i < n; i++)
        free(arr[i]);

    free(arr);    
}