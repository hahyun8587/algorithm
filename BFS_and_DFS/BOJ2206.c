#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 1000
#define NUM_STATE 2
#define NUM_DIRECTION 4

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
int BFS(int (*arr)[MAX_SIZE], int n, int m);

int main() {
    int arr[MAX_SIZE][MAX_SIZE];
    int N, M;

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) 
            scanf("%d", &arr[i][j]);
    }
    printf("%d\n", BFS(arr, N, M));

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

int BFS(int (*arr)[MAX_SIZE], int n, int m) {
    queue *q = initQueue(NUM_STATE * MAX_SIZE * MAX_SIZE + 1);
    int isPushed[NUM_STATE][MAX_SIZE * MAX_SIZE];
    int dist = -1;

    for (int i = 0; i < NUM_STATE; i++) {
        for (int j = 0; j < n * m; j++) 
            isPushed[i][j] = 0;
    } 
    push(q, 0);

    isPushed[0][0] = 1;

    while (!empty(q)) {
        int iter = size(q);

        for (int i = 0; i < iter; i++) {
            int cNode = pop(q);

            if (cNode % (n * m) == n * m - 1) {
                free(q->qa);
                free(q);

                return dist + 2;
            }
            int x = cNode % (n * m) / m;
            int y = cNode % (n * m) % m;

            for (int j = 0; j < NUM_DIRECTION; j++) {
                int cx = x + j % 2 * (j - 2);
                int cy = y + (j + 1) % 2 * (j - 1);
        
                if ((cx >= 0 && cx < n) && (cy >= 0 && cy < m)) {
                    if (cNode < n * m && !arr[cx][cy]) {
                        int nNode = m * cx + cy;

                        if (!isPushed[0][nNode]) {
                            push(q, nNode);

                            isPushed[1][nNode] = isPushed[0][nNode] = 1;
                        }   
                    }
                    else if ((cNode < n * m && arr[cx][cy]) || (cNode >= n * m && !arr[cx][cy])) {
                        int nNode = m * cx + cy + n * m;

                        if (!isPushed[1][nNode % (n * m)]) {
                            push(q, nNode);

                            isPushed[1][nNode % (n * m)] = 1;
                        }
                    }
                }
            }
        }
        dist++;
    }
    free(q->qa);
    free(q);

    return -1;
}