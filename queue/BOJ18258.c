#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAX_SIZE 6
#define COMMAND_PUSH "push"
#define COMMAND_POP "pop"
#define COMMAND_SIZE "size"
#define COMMAND_EMPTY "empty"
#define COMMAND_FRONT "front"
#define COMMAND_BACK "back"

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
int front(queue *q);
int back(queue *q);
void qprintf(queue *q, char *arr);

int main() {
    queue *q;
    char arr[MAX_SIZE];
    int N;
    
    scanf("%d", &N);

    q = initQueue(N);

    for (int i = 1; i <= N; i++) {
        scanf("%s", arr);
        qprintf(q, arr);
    }
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

int front(queue *q) {
    if (empty(q))
        return -1;

    return q->qa[q->tail];    
}

int back(queue *q) {
    if (empty(q))
        return -1;

    return q->head > 0 ? q->qa[q->head - 1] : q->qa[q->n - 1];
}

void qprintf(queue *q, char *arr) {
    if (!strcmp(arr, COMMAND_PUSH)) {
        int val;

        scanf("%d", &val);
        push(q, val);
    }
    else {
        if (!strcmp(arr, COMMAND_POP)) 
            printf("%d", pop(q));
        else if (!strcmp(arr, COMMAND_SIZE))
            printf("%d", size(q));
        else if (!strcmp(arr, COMMAND_EMPTY))
            printf("%d", empty(q));
        else if (!strcmp(arr, COMMAND_FRONT))
            printf("%d", front(q));
        else if (!strcmp(arr, COMMAND_BACK))
            printf("%d", back(q));

        putchar('\n');  
    }                  
}