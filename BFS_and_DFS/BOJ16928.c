#include <stdio.h>
#include <malloc.h>

#define NUM_NODE 100
#define TARGET_NODE 100
#define MAX_MOVE 30
#define QUEUE_SIZE 593

typedef struct {
    int *qa;
    int n;
    int head;
    int tail;
} Queue;

void init_a(int (*a)[NUM_NODE]);
void update_a(int (*a)[NUM_NODE], int (*move)[2], int n);
Queue *initQueue(int size);
int empty(Queue *q);
int push(Queue *q, int x);
int pop(Queue *q);
void freeQueue(Queue *q);
int BFS(int (*a)[NUM_NODE], int *path, int t);
int min_dist(int (*a)[NUM_NODE], int *path, int n, int t);
int snake_ladder(int (*move)[2], int n);

int main() {
    int N, M;
    int move[MAX_MOVE][2];
    
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N + M; i++) {
        scanf("%d %d", &move[i][0], &move[i][1]);
    }

    printf("%d\n", snake_ladder(move, N + M));

    return 0;
}

void init_a(int (*a)[NUM_NODE]) {
    for (int i = 0; i < NUM_NODE; i++) {
        for (int j = 0; j < NUM_NODE; j++) {
           a[i][j] = j >= i + 1 && j <= i + 6 ? 1 : 0;     
        }
    }
}

void update_a(int (*a)[NUM_NODE], int (*move)[2], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = move[i][0] - 7; j <= move[i][0] - 2; j++) {
            if (j >= 0) {
                a[j][move[i][0] - 1] = 0;
                a[j][move[i][1] - 1] = 1;
            }
        }

        for (int j = 0; j < NUM_NODE; j++) {
            a[move[i][0] - 1][j] = 0;
        }
    }
}

Queue *initQueue(int size) {
    Queue *q;

    q = (Queue *) malloc(sizeof(Queue));
    q->qa = (int *) malloc(sizeof(int) * (size + 1));
    q->n = size + 1;
    q->head = 0;
    q->tail = 0;

    return q;
}

int empty(Queue *q) {
    return q->head == q->tail ? 1 : 0;
}

int push(Queue *q, int x) {
    if ((q->tail + 1) % q->n == q->head) {
        return -1;
    }

    q->qa[q->tail++] = x;
    q->tail %= q->n;

    return x;
}

int pop(Queue *q) {
    if (empty(q)) {
        return -1;
    }

    int ret = q->qa[q->head++];

    q->head %= q->n;

    return ret;
}

void freeQueue(Queue *q) {
    free(q->qa);
    free(q);
}

int BFS(int (*a)[NUM_NODE], int *path, int t) {
    Queue *q;
    int visited[NUM_NODE];
    int p = 0;

    q = initQueue(QUEUE_SIZE);

    for (int i = 0; i < NUM_NODE; i++) {
        visited[i] = 0;
    }

    path[p++] = 1;
    visited[0] = 1;

    push(q, 1);
    
    while (!empty(q)) {
        int node;

        node = pop(q);

        for (int i = 0; i < NUM_NODE; i++) {
            if (a[node - 1][i] && !visited[i]) {
                path[p++] = i + 1;
                visited[i] = 1;

                if (i + 1 == t) {
                    freeQueue(q);

                    return p;
                }

                push(q, i + 1);
            }
        }
    }

    freeQueue(q);

    return 0;
}

int min_dist(int (*a)[NUM_NODE], int *path, int n, int t) {
    int dist = 0;

    while (t != 1) {
        int i;

        for (i = 0; i < n; i++) {
            if (a[path[i] - 1][t - 1]) {
                dist++;
                t = path[i];
              
                break;
            } 
        }

        if (i == n) {
            return -1;
        }
    }
    return dist;
}

int snake_ladder(int (*move)[2], int n) {
    int a[NUM_NODE][NUM_NODE];
    int path[NUM_NODE];

    init_a(a);
    update_a(a, move, n);

    return min_dist(a, path, BFS(a, path, TARGET_NODE), TARGET_NODE);
}