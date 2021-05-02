#include <stdio.h>
#include <malloc.h>

#define COMMAND_PUSH_FRONT "push_front"
#define COMMAND_PUSH_BACK "push_back"
#define COMMAND_POP_FRONT "pop_front"
#define COMMAND_POP_BACK "pop_back"
#define COMMAND_SIZE "size"
#define COMMAND_EMPTY "empty"
#define COMMAND_FRONT "front"
#define COMMAND_BACK "back"

typedef struct {
    int *da;
    int n;
    int head;
    int tail;
} deque;

typedef enum {
    false, true
} bool;

deque* initDeque(int n);
int size(deque *d);
int push_front(deque *d, int x);
int push_back(deque *d, int x);
bool empty(deque *d);
int pop_front(deque *d);
int pop_back(deque *d);
int front(deque *d);
int back(deque *d);
void dprintf(deque *d, char *arr);

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
    



}