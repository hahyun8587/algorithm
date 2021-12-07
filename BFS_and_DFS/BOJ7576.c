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
int BFS(queue *q, int (*arr)[MAX_SIZE], int N, int M);
int minDate(int (*arr)[MAX_SIZE], int N, int M);

int main() {
    int arr[MAX_SIZE][MAX_SIZE];
    int M, N;

    scanf("%d %d", &M, &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) 
            scanf("%d", &arr[i][j]);
    }
    printf("%d\n", minDate(arr, N, M));

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

int BFS(queue *q, int (*arr)[MAX_SIZE], int N, int M) {
    int date = -1;

    while (!empty(q)) {
        int iter = size(q);
        
        for (int i = 0; i < iter; i++) {
            int node = pop(q);
            int x = node / M;
            int y = node % M;

            if (y - 1 >= 0 && !arr[x][y - 1]) {
                push(q, x * M + y - 1);

                arr[x][y - 1] = 1;
            }    

            if (x - 1 >= 0 && !arr[x - 1][y]) {
                push(q, (x - 1) * M + y);

                arr[x - 1][y] = 1;
            }
            if (y + 1 < M && !arr[x][y + 1]) {
                push(q, x * M + y + 1);

                arr[x][y + 1] = 1;
            }

            if (x + 1 < N && !arr[x + 1][y]) {
                push(q, (x + 1) * M + y);     

                arr[x + 1][y] = 1;
            }            
        }
        date++;
    }
    return date;
}

int minDate(int (*arr)[MAX_SIZE], int N, int M) {
    queue *q = initQueue(MAX_SIZE * MAX_SIZE + 1);
    int date;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 1)
                push(q, i * M + j);           
        }
    }        
    date = BFS(q, arr, N, M);
    
    free(q->qa);
    free(q);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!arr[i][j])
                return -1;
        }
    }
    return date;
}