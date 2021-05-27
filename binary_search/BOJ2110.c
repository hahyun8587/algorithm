#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 200000

typedef struct {
    int *ha;
    int n;
    int (*type)(int *, int, int);
} heap;

int ascn(int *arr, int i, int j);
heap* initHeap(int *arr, int n);
void swap(int *a, int *b);
void sink(heap *h);
void heapify(heap *h);
void delete(heap *h);
void heapSort(heap *h);
int check(int *arr, int n, int d, int c);
int maxDist(int *arr, int n, int s, int e, int c);

int main() {



    return 0;
}

int check(int *arr, int n, int d, int c) {
    int count = 1;    
    int ds = 0;

    
    


}