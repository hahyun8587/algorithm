#include <stdio.h>
#include <malloc.h>

#define ARR_SIZE 2
#define STD1 1
#define STD2 0

typedef struct {
    int **ha;
    int n;
    int m;
} heap;

int** malloc2D(int n, int m);
heap* initHeap(int **arr, int n);
int argMax(int **arr, int i, int j);
void swap(int **a, int **b);
void sink(heap *h, int s);
void maxHeap(heap *h);
void _delete(heap *h);
void heapSort(heap *h);
int maxConf(int **arr, int n);
void free2D(int **arr, int n);

int main() {
    int **arr;
    int N;

    scanf("%d", &N);
    
    arr = malloc2D(N + 1, ARR_SIZE);

    for (int i = 1; i <= N; i++)
        scanf("%d %d", &arr[i][0], &arr[i][1]);

    printf("%d\n", maxConf(arr, N + 1)); 
    free2D(arr, N + 1);

    return 0;
}

int** malloc2D(int n, int m) {
    int **arr;

    arr = (int **) malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
        arr[i] = (int *) malloc(m * sizeof(int));

    return arr;
}

heap* initHeap(int **arr, int n) {
    heap *h;

    h = (heap *) malloc(sizeof(heap));        
    h->ha = arr;
    h->n = n;
    h->m = ARR_SIZE;

    return h;
}

int argMax(int **arr, int i, int j) {
    if (arr[i][STD1] > arr[j][STD1])
        return i;
    else if (arr[i][STD1] < arr[j][STD1])
        return j;
    else
        return arr[i][STD2] > arr[j][STD2] ? i : j;         
}

void swap(int **a, int **b) {
    int *temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void sink(heap *h, int s) {
    int curr = s;
    int std;

    while (2 * curr <= h->n) {
        if (2 * curr < h->n)
            std = argMax(h->ha, 2 * curr, 2 * curr + 1);
        else 
            std = 2 * curr;

        if (h->ha[curr][STD1] < h->ha[std][STD1])
            swap(&h->ha[curr], &h->ha[std]);
        else if (h->ha[curr][STD1] == h->ha[std][STD1]) {
            if (h->ha[curr][STD2] < h->ha[std][STD2]) 
                swap(&h->ha[curr], &h->ha[std]);
            else 
                break;
        }
        else
            break;

        curr = std;    
    }
}

void maxHeap(heap *h) {
    for (int i = h->n / 2; i > 0; i--)
        sink(h, i);
}

void _delete(heap *h) {
    swap(&h->ha[1], &h->ha[h->n]);

    h->n -= 1;

    sink(h, 1);
}

void heapSort(heap *h) {
    int numIt = h->n - 1;

    maxHeap(h);

    for (int i = 1; i <= numIt; i++)
        _delete(h);
}

int maxConf(int **arr, int n) {
    heap *h;
    int end;
    int count = 1;

    h = initHeap(arr, n - 1);

    heapSort(h);
    free(h);

    end = arr[1][1];

    for (int i = 2; i < n; i++) {
        if (arr[i][0] >= end) {
            end = arr[i][1];
            count++;
        }
    }
    return count;
}

void free2D(int **arr, int n) {
    for (int i = 0; i < n; i++)
        free(arr[i]);

    free(arr);    
}