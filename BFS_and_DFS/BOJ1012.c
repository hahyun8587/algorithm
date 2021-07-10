#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 50

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
void BFS(int (*loc)[MAX_SIZE], int n, int m, int *visited, int sx, int sy);
int minWorm(int (*arr)[MAX_SIZE], int n, int m);

int main() {
    int arr[MAX_SIZE][MAX_SIZE];
    int T;
    int N, M, K;

    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        scanf("%d %d %d", &M, &N, &K);

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) 
                arr[j][k] = 0;
        }

        for (int j = 0; j < K; j++) {
            int x, y;

            scanf("%d %d", &x, &y);
            
            arr[y][x] = 1;
        }
        printf("%d\n", minWorm(arr, N, M));
    }
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

void BFS(int (*loc)[MAX_SIZE], int n, int m, int *visited, int sx, int sy) {
    queue *q;

    q = initQueue(n * m);

    if (loc[sx][sy]) {
        push(q, m * sx + sy);

        visited[m * sx + sy] = 1;
    }

    while (!empty(q)) {
        int node;
        int x, y;

        node = pop(q);
        x = node / m;
        y = node % m; 

        for (int i = 0; i < 4; i++) {
            int j = i > 0 ? i + x - 2 : x;
            int k = i < 3 ? i + y - 1 : y;
            int l = m * j + k;

            if (j >= 0 && j < n && k >= 0 && k < m) {
                if (loc[j][k] && !visited[l]) {
                    push(q, l);

                    visited[l] = 1;
                }
            }
        }
    }
    freeQueue(q);
}

int minWorm(int (*arr)[MAX_SIZE], int n, int m) {
    int visited[MAX_SIZE * MAX_SIZE];
    int count = 0;

    for (int i = 0; i < n * m; i++)
        visited[i] = 0;        

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] && !visited[m * i + j]) {
                BFS(arr, n, m, visited, i, j);

                count++;
            }
        }
    }
    return count;
}

void freeQueue(queue *q) {
    free(q->qa);
    free(q);
}