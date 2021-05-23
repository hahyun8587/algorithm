#include <stdio.h>

#define MAX_SIZE 500001

typedef struct {
    int *ha;
    int n;
    int (*type)(int *, int, int);
} heap;

int ascn(int *arr, int i, int j);
heap* initHeap(int *arr, int n);
void sink(heap *h, int s);
void heapify(heap *h);
void delete(heap *h);
void heapSort(heap *h);
int number(int *arr, int s, int mid, int e);
int numCont(int *arr, int s, int e, int x);

int main() {



    return 0;
}

int number(int *arr, int s, int mid, int e) {
    int val = arr[mid];
    int count = 1;

    for (int i = mid - 1; i >= s; i--) {
        if (val == arr[i])
            count++;
        else 
            break;    
    }

    for (int i = mid + 1; i <= e; i++) {
        if (val == arr[i])
            count++;
        else 
            break;
    }
    return count;
}

int numCont(int *arr, int s, int e, int x) {
    int mid = 



}