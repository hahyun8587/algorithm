#include <stdio.h>
#include <malloc.h>

#define ARR_SIZE 2
#define MAX_SIZE 100000
#define STD1 1
#define STD2 0

typedef struct {
    int **ha;
    int n;
    int m;
} heap;

heap* initHeap(int (*arr)[ARR_SIZE], int n);
int argMax(int (*arr)[ARR_SIZE], int i, int j);
void swap(int **a, int **b);
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
    h->m = ARR_SIZE;

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

void swap(int **a, int **b) {
    int *temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void sink(heap *h, int s) {
    int curr = s;
    int std;

    while(2 * curr <= h->n - 1) {
        if (2 * curr < h->n - 1)
            std = argMax(h->ha, 2 * curr, 2 * curr + 1);
        else 
            std = 2 * curr;

        if (h->ha[curr][STD1] < h->ha[std][STD1])
            swap(&h->ha[curr], &h->ha[std]);
        else if (h->ha[curr][STD1] == h->ha[std][STD1]) {
            if (h->ha[curr][STD2] < h->ha[std][STD2]) 
                swap(h->ha[curr], h->ha[std]);
            else 
                break;
        }
        else
            break;

        curr = std;    
    }
}

void maxHeap(heap *h) {
    for(int i = (h->n - 1) / 2; i > 0; i--)
        sink(h, i);
}

void delete(heap *h) {
    


    
}