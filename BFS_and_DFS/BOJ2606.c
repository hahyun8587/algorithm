#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 100

typedef struct {
    int *qa;
    int n;
    int head;
    int tail;
} queue;

queue *initQueue(int n);
int size(queue *q);
int push(queue *q, int x);
int empty(queue *q);
int pop(queue *q);
void freeQueue(queue *q);
int BFS(int (*a)[MAX_SIZE], int n);

int main() {
    int a[MAX_SIZE][MAX_SIZE];
    int V, E;

    scanf("%d", &V);
    scanf("%d", &E);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) 
            a[i][j] = 0;
    }

    for (int i = 1; i <= E; i++) {
        int s, e;

        scanf("%d %d", &s, &e);

        a[e - 1][s - 1] = a[s - 1][e - 1] = 1;
    }
    printf("%d\n", BFS(a, V));    

    return 0;
}

queue *initQueue(int n) {
    queue *q;

    q = (queue *) malloc(sizeof(queue));
    q->qa = (int *) malloc(sizeof(int) * (n + 1));
    q->n = n + 1;
    q->tail = q->head = 0;

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

int empty(queue *q) {
    return q->head == q->tail ? 1 : 0;
}

int pop(queue *q) {
    if (empty(q))
        return -1;

    int val;

    val = q->qa[q->tail++];
    q->tail %= q->n;    

    return val;
}

void freeQueue(queue *q) {
    free(q->qa);
    free(q);
}

int BFS(int (*a)[MAX_SIZE], int n) {
    queue *q;
    int visited[MAX_SIZE];
    int count = 0;

    q = initQueue(n - 1);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    push(q, 0);
    
    if (n > 1)
        visited[0] = 1;

    while (!empty(q)) {
        int node; 
        
        node = pop(q);

        for (int i = 0; i < n; i++) {
            if (a[node][i] && !visited[i]) {
                push(q, i);
                
                visited[i] = 1;
                count++;
            } 
        }
    }
    freeQueue(q);

    return count;
}