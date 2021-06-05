#include <stdio.h>
#include <malloc.h>

#define NUM_TYPE 2
#define MAX_SIZE 50001

typedef struct {
    int *ha;
    int n;
    int (*type)(int *, int, int);
} heap;

int ascn(int *arr, int i, int j);
int descn(int *arr, int i, int j);
heap *initHeap(int n, int order);
void swap(int *a, int *b);
void swim(heap *h, int x);
int top(heap *h);
int size(heap *h);
void sink(heap *h, int s);
int delete(heap *h);
void freeHeap(heap *h);
void mid(int *src, int n, int *dst);
void aprintf(int *arr, int n);

int main() {
    



    return 0;
}

int ascn(int *arr, int i, int j) {
    return arr[i] > arr[j] ? 1 : 0; 
}

int descn(int *arr, int i, int j) {
    return arr[i] < arr[j] ? 1 : 0;
}

heap *initHeap(int n, int order) {
    heap *h;
    int (*type[NUM_TYPE])(int *, int, int) = { ascn, descn };

    h = (heap *) malloc(sizeof(heap));
    h->ha = (int *) malloc(sizeof(int) * (n + 1));
    h->n = 1;
    h->type = type[order];

    return h;
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

int top(heap *h) {
    return h->ha[1];
}

int size(heap *h) {
    return h->n - 1;
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

void mid(int *src, int n, int *dst) {
    heap *h1, *h2;

    h1 = initHeap(MAX_SIZE, 0);
    h2 = initHeap(MAX_SIZE, 1);

    swim(h1, dst[0] = src[0]);

    for (int i = 1; i < n; i++) {
        if (top(h1) <= src[i])
            swim(h1, src[i]);
        else 
            swim(h2, src[i]);

        int sh1, sh2;

        sh1 = size(h1);
        sh2 = size(h2);
    
        if (sh1 - sh2 == -1)
            dst[i] = top(h2);
        else { 
            if (sh1 - sh2 == -2) 
                swim(h1, delete(h2));
            else if (sh1 - sh2 == 2)
                swim(h2, delete(h1));

            dst[i] = top(h1);        
        }    
    }
}