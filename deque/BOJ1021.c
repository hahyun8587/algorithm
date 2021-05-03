#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 50

typedef struct {
    int *da;
    int n;
    int head;
    int tail;
} deque;

deque* initDeque(int n);
int size(deque *d);
int push_front(deque *d, int x);
int push_back(deque *d, int x);
int empty(deque *d);
int pop_front(deque *d);
int pop_back(deque *d);
int front(deque *d);
int back(deque *d);
void rotate(deque *d, int (*fp1)(deque *, int x), int (*fp2)(deque *), int t);
int min(int a, int b);
int minExe(int *arr, int n, int size);

int main() {
    




    return 0;
}

deque* initDeque(int n) {
    deque *d;

    d = (deque *) malloc(sizeof(deque));
    d->da = (int *) malloc(sizeof(int) * n);
    d->n = n;
    d->head = d->n - 1;
    d->tail = 0;

    return d;
}

int size(deque *d) {
    return d->head >= d->tail ? d->n - (d->head + 1 - d->tail) : d->tail - (d->head + 1);     
}

int push_front(deque *d, int x) {
    if (size(d) == d->n - 1)    
        return -1;

    d->da[d->tail++] = x;
    d->tail %= d->n;

    return x;
}

int push_back(deque *d, int x) {
    if (size(d) == d->n - 1)
        return -1;

    d->da[d->head--] = x;

    if (d->head < 0)
        d->head = d->n - 1;
    
    return x;
}

int empty(deque *d) {
    return size(d) ? 0 : 1;
}

int pop_front(deque *d) {
    if (empty(d))
        return -1;

    d->tail--;

    if (d->tail < 0)
        d->tail = d->n - 1;

    return d->da[d->tail];    
}

int pop_back(deque *d) {
    if (empty(d))
        return -1;

    d->head = (d->head + 1) % d->n;    

    return d->da[d->head];
}

int front(deque *d) {
    if (empty(d))
        return -1;

    return d->tail ? d->da[d->tail - 1] : d->da[d->n - 1];
}

int back(deque *d) {
    if (empty(d))
        return -1;

    return d->da[(d->head + 1) % d->n];
}

int min(int a, int b) {
    return a < b ? a : b;
}

int minExe(int *arr, int n, int size) {
    deque *d;
    



}