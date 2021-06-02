#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define NUM_TYPE 3
#define ORDER 0

typedef struct {
    int *ha;
    int n;
    int (*type)(int *, int, int);
} heap;

int ascn(int *arr, int i, int j);
int descn(int *arr, int i, int j);
int adescn(int *arr, int i, int j);
heap *initHeap(int n);
void swim(heap *h, int x);
void sink(heap *h, int s);
int delete(heap *h);

int main() {



    return 0;
}

int ascn(int *arr, int i, int j) {
    return arr[i] > arr[j] ? 1 : 0; 
}

int descn(int *arr, int i, int j) {
    return arr[i] < arr[j] ? 1 : 0;
}

int adescn(int *arr, int i, int j) {
    return abs(arr[i]) < abs(arr[j]) ? 1 : 0;
}

heap *initHeap(int n) {
    heap *h;
    int (*type[NUM_TYPE])(int *, int, int) = {ascn, descn, adescn};

    h = (heap *) malloc(sizeof(heap));
    h->ha = (int *) malloc(sizeof(int) * n);
    h->n = n;
    h->type = type[ORDER];

    return h;
}
