#include <stdio.h>
#include <malloc.h>

#define ARR_SIZE 2
#define MAX_SIZE 100000
#define STD1 1
#define STD2 0

typedef struct {
    int **ha;
    int n;
} heap;

heap* initHeap(int (*arr)[ARR_SIZE], int n);
int argMax(int (*arr)[ARR_SIZE], int i, int j);
void swap(int *a, int *b);
void sink(heap *h, int s);
void maxHeap(heap *h);
void delete(heap *h);
void heapSort(heap *h);
int maxConf(int (*arr)[ARR_SIZE]);

int main() {



    return 0;
}

heap* initHeap(int (*arr)[ARR_SIZE], int n) {
    heap *h;

    h = (heap *) malloc(sizeof(heap));        
    h->ha = arr;
    h->n = n;

    return h;
}

int argMax(int (*arr)[ARR_SIZE], int i, int j) {
    if (arr[i][STD1] > arr[j][STD1])
        return i;
    else if (arr[i][STD1] < arr[j][STD1])
        return j;
    else
        return arr[i][STD2] > arr[j][STD2] ? i : j;         
}

void swap(int *a, int *b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void sink(heap *h, int s) {
    int curr = s;

    while(2 * curr <= h->n - 1) {
            
    }



}