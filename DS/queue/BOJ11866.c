#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 1000

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
void jose(int *dst, int n, int k);
void aprintf(int *arr, int n);

int main() {
    int N, K;
    int perm[MAX_SIZE];

    scanf("%d %d", &N, &K); 
    jose(perm, N, K);
    aprintf(perm, N);

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

void jose(int *dst, int n, int k) {
    queue *q;
    int count = 0;

    q = initQueue(n + 1);

    for (int i = 1; i <= n; i++)
        push(q, i);

    while (!empty(q)) {
        for (int i = 1; i < k; i++) 
            push(q, pop(q));

        dst[count++] = pop(q);      
    }
    free(q->qa);
    free(q);
}

void aprintf(int *arr, int n) {
    printf("<");

    for (int i = 0; i <= n - 2; i++) 
        printf("%d, ", arr[i]);

    printf("%d>\n", arr[n - 1]);    
}