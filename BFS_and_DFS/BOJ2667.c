#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 25

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
int BFS(int (*loc)[MAX_SIZE], int n, int *visited, int sx, int sy);
void swap(int *a, int *b);
void bubbleSort(int *arr, int n);
void numBlock(int (*src)[MAX_SIZE], int n, int *dst, int *m);

int main() {
    int loc[MAX_SIZE][MAX_SIZE];
    int blocks[MAX_SIZE * MAX_SIZE / 2];
    int N, M;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) 
            scanf("%1d", &loc[i][j]);
    }
    numBlock(loc, N, blocks, &M);
    printf("%d\n", M);

    for (int i = 0; i < M; i++)
        printf("%d\n", blocks[i]);
    
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

int BFS(int (*loc)[MAX_SIZE], int n , int *visited, int sx, int sy) {
    queue *q;
    int count = 0;

    q = initQueue(n * n - 1);

    if (loc[sx][sy]) {
        push(q, n * sx + sy);

        visited[n * sx + sy] = 1;
        count++;
    }

    while (!empty(q)) {
        int node;
        int x, y;

        node = pop(q);
        x = node / n;
        y = node % n; 

        for (int i = 0; i < 4; i++) {
            int j = i > 0 ? i + x - 2 : x;
            int k = i < 3 ? i + y - 1 : y;
            int l = node + (2 * (i / 2) - 1) * ((n - 1) * (i % 2) + 1);

            if (j >= 0 && j < n && k >= 0 && k < n) {
                if (loc[j][k] && !visited[l]) {
                    push(q, l);

                    visited[l] = 1;
                    count++;
                }
            }
        }
    }
    freeQueue(q);

    return count;
}

void swap(int *a, int *b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j <= -i + n - 2; j++) {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);         
        }
    }
}

void numBlock(int (*src)[MAX_SIZE], int n, int *dst, int *m) {
    int visited[MAX_SIZE * MAX_SIZE];
    int count = 0;

    for (int i = 0; i < n * n; i++)
        visited[i] = 0;        

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (src[i][j] && !visited[n * i + j]) 
                dst[count++] = BFS(src, n, visited, i, j);
        }
    }
    bubbleSort(dst, count);

    *m = count;
}

void freeQueue(queue *q) {
    free(q->qa);
    free(q);
}