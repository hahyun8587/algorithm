#include <stdio.h>
#include <malloc.h>

typedef struct {
    int *ha;
    int n;
} heap;

heap* initHeap(int n);
void swap(int *a, int *b);
void sink(heap *h, int s);
void heapify(heap *h);
void delete(heap *h);
void heapSort(heap *h);
void freeHeap(heap *h);