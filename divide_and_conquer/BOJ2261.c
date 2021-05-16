#include <stdio.h>

#define MAX_SIZE 100000
#define NUM_AXIS 2
#define INF 200000000

typedef struct {
    int (*ha)[NUM_AXIS];
    int n;
} heap;

heap* initHeap(int (*arr)[NUM_AXIS], int n);
void sink(heap *h);
void heapify(heap *h);
void delete(heap *h);
void heapSort(heap *h);
int min(int a, int b);
int minLine(int (*arr)[NUM_AXIS], int l);
int minBound(int (*arr)[NUM_AXIS], int mid, int d);
int _minDist(int (*arr)[NUM_AXIS], int s, int e);
int minDist(int (*arr)[NUM_AXIS], int n);

int main() {



    return 0;
}

