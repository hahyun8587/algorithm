#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 100001
#define ERROR "error"

typedef struct {
    int *da;
    int n;
    int head;
    int tail;
} deque;

deque* initDeque(int n);
int size(deque *d);
int empty(deque *d);
int pop_front(deque *d);
int pop_back(deque *d);
void AC(deque *d, char *cmd, char *num);
void dprintf_(deque *d);
void freeDeque(deque *d);


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



void freeDeque(deque *d) {
    free(d->da);
    free(d);
}