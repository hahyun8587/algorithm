#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 100001

typedef struct {
    int *ha;
    int n;
    int (*type)(int *, int, int);
} heap;

heap* initHeap(int *arr, int n);
int ascn(int *arr, int i, int j);
void swap(int *a, int *b);
void sink(heap *h, int s);
void heapify(heap *h);
void delete(heap *h);
void heapSort(heap *h);
int isCont(int *arr, int s, int e, int x);

int main() {
    heap *h;
    int arr[MAX_SIZE];
    int N, M;
    int val;
    
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);

    h = initHeap(arr, N + 1);

    heapSort(h);
    free(h);
    scanf("%d", &M);

    for (int i = 1; i <= M; i++) {
        scanf("%d", &val);
        printf("%d\n", isCont(arr, 1, N, val));
    }
    return 0;
}

heap* initHeap(int *arr, int n) {
    heap *h;

    h = (heap *) malloc(sizeof(heap));
    h->ha = arr;
    h->n = n;
    h->type = ascn;

    return h;
}

int ascn(int *arr, int i, int j) {
    return arr[i] > arr[j] ? 0 : 1;
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

int isCont(int *arr, int s, int e, int x) {
    if (s > e)
        return 0; 
    
    int mid = s + (e - s + 1) / 2;

    if (x == arr[mid])
        return 1;
    else if (x < arr[mid])
        return isCont(arr, s, mid - 1, x);
    else 
        return isCont(arr, mid + 1, e, x);    
}