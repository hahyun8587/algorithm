#include <stdio.h>
#include <malloc.h>

#define NUM_NODE 90000
#define NUM_DIRECTION 8

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
int BFS(int sx, int sy, int ex, int ey, int n);
void search(queue *q, int *isPushed, int cx, int cy, int n, int m);

int main() {
    int T;
    
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int l;
        int sx, sy;
        int ex, ey;

        scanf("%d", &l);
        scanf("%d %d", &sx, &sy);
        scanf("%d %d", &ex, &ey);
        printf("%d\n", BFS(sx, sy, ex, ey, l));
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

void search(queue *q, int *isPushed, int cx, int cy, int n, int m) {
    for (int i = 0; i < NUM_DIRECTION / 2; i++) {
        int nx = cx + (i < 2 ? m - 2 : -m + 2);
        int ny = cy + (2 * m + 2) * (i % 2) - m - 1;
        
        if ((nx >= 0 && nx < n) && (ny >= 0 && ny < n)) {
            int nNode = n * nx + ny;

            if (!isPushed[nNode]) {
                push(q, nNode);

                isPushed[nNode] = 1;
            }
        }
    }
} 

int BFS(int sx, int sy, int ex, int ey, int n) {
    queue *q = initQueue(NUM_NODE + 1); 
    int isPushed[NUM_NODE];
    int s = n * sx + sy;
    int e = n * ex + ey;
    int dist = -1;

    for (int i = 0; i < NUM_NODE; i++)
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

            int cx = cNode / n;
            int cy = cNode % n;    

            for (int j = 0; j < 2; j++) 
                search(q, isPushed, cx, cy, n, j);
        }
        dist++;

        if (cNode == e)
            break;
    }
    free(q->qa);
    free(q);

    return dist;   
}