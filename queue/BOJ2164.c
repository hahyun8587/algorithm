#include <stdio.h>
#include <malloc.h>

typedef struct {
    int *qa;
    int n;
    int head;
    int tail;
} queue;

typedef enum {
    false, true
} bool;

queue* initQueue(int n);
int size(queue *q);
int push(queue *q, int x);
bool empty(queue *q);
int pop(queue *q);
int last(int n);

int main() {
    int N;

    scanf("%d", &N);
    printf("%d\n", last(N));

    return 0;
}

queue* initQueue(int n) {
    queue *q;

    q = (queue *) malloc(sizeof(queue));
    q->qa = (int *) malloc(sizeof(int) * n);
    q->n = n;
    q->head = q->tail = 0;

    return q;
}

int size(queue *q) {
    return q->head >= q->tail ? q->head - q->tail : q->n + q->head - q->tail;
}

int push(queue *q, int x) {
    if (size(q) == q->n - 1)
        return -1;

    q->qa[q->head++] = x;
    q->head %= q->n;        

    return x;
}

bool empty(queue *q) {
    return q->head == q->tail ? true : false;
}

int pop(queue *q) {
    if (empty(q))
        return -1;

    int val;

    val = q->qa[q->tail++];
    q->tail %= q->n;    

    return val;
}

int last(int n) {
    queue *q;
    int val;

    q = initQueue(n + 1);

    for (int i = 1; i <= n; i++) 
        push(q, i);

    while (size(q) != 1) {
        pop(q);
        push(q, pop(q));
    }    
    val = pop(q);

    free(q->qa);
    free(q);

    return val;    
}