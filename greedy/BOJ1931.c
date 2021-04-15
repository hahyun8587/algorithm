#include <stdio.h>

#define MAX_SIZE 100000

typedef struct {
    int *ha;
    int n;
} heap;

heap* initHeap(int n);
void sink(heap *h, int s);
void maxHeap(heap *h);
void delete(heap *h);
void heapSort(heap *h);
int maxConf(int (*arr)[]);