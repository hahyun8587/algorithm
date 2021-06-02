#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define NUM_TYPE 3
#define ORDER 2
#define EMPTY_VAL 0

typedef struct {
    int *ha;
    int n;
    int (*type)(int *, int, int);
} heap;

int ascn(int *arr, int i, int j);
int descn(int *arr, int i, int j);
int adescn(int *arr, int i, int j);
heap *initHeap(int n);
int empty(heap *h);
void swap(int *a, int *b);
void swim(heap *h, int x);
void sink(heap *h, int s);
int delete(heap *h);
void freeHeap(heap *h);

int main() {
    heap *h;
    int N;

    scanf("%d", &N);

    h = initHeap(N);

    for (int i = 1; i <= N; i++) {
        int x;

        scanf("%d", &x);
        
        if (x)
            swim(h, x);
        else
            empty(h) ? printf("%d\n", EMPTY_VAL) : printf("%d\n", delete(h));  
    }
    freeHeap(h);
    
    return 0;
}

int ascn(int *arr, int i, int j) {
    return arr[i] > arr[j] ? 1 : 0; 
}

int descn(int *arr, int i, int j) {
    return arr[i] < arr[j] ? 1 : 0;
}

int adescn(int *arr, int i, int j) {
    if (abs(arr[i]) < abs(arr[j]))
        return 1;
    else if (abs(arr[i]) > abs(arr[j]))
        return 0;     
    else 
        return descn(arr, i, j);
}

heap *initHeap(int n) {
    heap *h;
    int (*type[NUM_TYPE])(int *, int, int) = {ascn, descn, adescn};

    h = (heap *) malloc(sizeof(heap));
    h->ha = (int *) malloc(sizeof(int) * (n + 1));
    h->n = 1;
    h->type = type[ORDER];

    return h;
}

int empty(heap *h) {
    return h->n == 1 ? 1 : 0;
}

void swap(int *a, int *b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void swim(heap *h, int x) {
    h->ha[h->n++] = x;

    for (int i = h->n - 1; i > 1 ; i /= 2) {
        if (h->type(h->ha, i, i / 2))
            swap(&h->ha[i], &h->ha[i / 2]);
        else 
            break;    
    }
}

void sink(heap *h, int s) {
    if (s * 2 > h->n - 1)
        return;

    int curr = s;
    int cmp;

    do {
        if (curr * 2 == h->n - 1)
            cmp = curr * 2;
        else
            cmp = h->type(h->ha, curr * 2, curr * 2 + 1) ? curr * 2 : curr * 2 + 1;

        if (h->type(h->ha, cmp, curr))
            swap(&h->ha[curr], &h->ha[cmp]);
        else 
            break;

        curr = cmp;
    } while (curr * 2 <= h->n - 1); 
}

int delete(heap *h) {
    swap(&h->ha[1], &h->ha[h->n-- - 1]);
    sink(h, 1);

    return h->ha[h->n];
}

void freeHeap(heap *h) {
    free(h->ha);
    free(h);
}