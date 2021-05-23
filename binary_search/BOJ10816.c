#include <stdio.h>
#include <malloc.h>

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
int numCont(int *arr, int *mem, int s, int e, int x);

int main() {
    heap *h;
    int arr[MAX_SIZE];
    int mem[MAX_SIZE - 1];
    int N, M;
    int val;

    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);

        mem[i - 1] = 0;
    }

    h = initHeap(arr, N + 1);

    heapSort(h);
    free(h);
    scanf("%d", &M);

    for (int i = 1; i <= M; i++) {
        scanf("%d", &val);
        printf("%d ", numCont(arr, mem, 1, N, val));
    }    
    putchar('\n');

    return 0;
}

int ascn(int *arr, int i, int j) {
    return arr[i] > arr[j] ? 0 : 1;
}

heap* initHeap(int *arr, int n) {
    heap *h;

    h = (heap *) malloc(sizeof(heap));
    h->ha = arr;
    h->n = n;
    h->type = ascn;

    return h;
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

int numCont(int *arr, int *mem, int s, int e, int x) {
    if (s > e)
        return 0;
    
    int mid = s + (e - s + 1) / 2;

    if (x == arr[mid]) 
        return mem[mid - 1] ? mem[mid - 1] : (mem[mid - 1] = number(arr, s, mid, e));
    else if (x < arr[mid])
        return numCont(arr, mem, s, mid - 1, x);
    else 
        return numCont(arr, mem, mid + 1, e, x);    
}