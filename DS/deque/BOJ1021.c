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
int front(deque *d);
int min(int a, int b);
void freeDeque(deque *d);
int minExe(int *arr, int n, int ds);

int main() {
    int N, M;
    int arr[MAX_SIZE];

    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) 
        scanf("%d", &arr[i]);

    printf("%d\n", minExe(arr, M, N));

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

int front(deque *d) {
    if (empty(d))
        return -1;

    return d->tail ? d->da[d->tail - 1] : d->da[d->n - 1];
}

int min(int a, int b) {
    return a < b ? a : b;
}

void freeDeque(deque *d){
    free(d->da);
    free(d);
}

int minExe(int *arr, int n, int ds) {
    deque *d;
    int count;
    int sum = 0;

    d = initDeque(ds + 1);

    for (int i = 1; i <= ds; i++) 
        push_front(d, -i + ds + 1);

    for (int i = 0; i < n; i++) {
        count = 0;

        while (front(d) != arr[i]) {
            push_back(d, pop_front(d));

            count++;
        }
        sum += min(count, size(d) - count);

        pop_front(d);
    }
    freeDeque(d);

    return sum;
}