#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 100001
#define MIN_COOR 0
#define MAX_COOR 100000

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
int BFS(int s, int e);

int main() {
    int N, K;

    scanf("%d %d", &N, &K);
    printf("%d\n", BFS(N ,K));

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

int BFS(int s, int e) {
    queue *q = initQueue(MAX_SIZE + 1);
    int isPushed[MAX_SIZE];
    int dist = -1;

    for (int i = 0; i < MAX_SIZE; i++) 
        isPushed[i] = 0;

    push(q, s);

    isPushed[s] = 1;

    while (!empty(q)) {
        int iter = size(q);
        int cNode;

        for (int i = 0; i < iter; i++) {
            cNode = pop(q);

            if (cNode == e)
                break;

            for (int j = 0; j < 3; j++) {
                int nNode = (!(j - 1) + 1) * cNode + j - 1; 

                if (nNode >= MIN_COOR && nNode <= MAX_COOR) {
                    if (!isPushed[nNode]) {
                        push(q, nNode);

                        isPushed[nNode] = 1;
                    }
                }
            }
        }    
        dist++;

        if (cNode == e)
            break;
    }
    free(q->qa);
    free(q);

    return dist;
}