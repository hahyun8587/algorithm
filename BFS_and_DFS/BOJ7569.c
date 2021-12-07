#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 100
#define NUM_DIM 3

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
int BFS(queue *q, int (*arr)[MAX_SIZE][MAX_SIZE], int H, int N, int M);
int minDate(int (*arr)[MAX_SIZE][MAX_SIZE], int H, int N, int M);

int main() {
    int arr[MAX_SIZE][MAX_SIZE][MAX_SIZE];
    int M, N, H;

    scanf("%d %d %d", &M, &N, &H);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) 
                scanf("%d", &arr[i][j][k]);
        }
    }
    printf("%d\n", minDate(arr, H, N, M));

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

int BFS(queue *q, int (*arr)[MAX_SIZE][MAX_SIZE], int H, int N, int M) {
    int date = -1;

    while (!empty(q)) {
        int iter = size(q);
        
        for (int i = 0; i < iter; i++) {
            int node = pop(q);
            int x = node / (H * N * M);
            int y = node % (H * N * M) / M; 
            int z = node % M;
            int coor[NUM_DIM] = {x, y, z};
            int axis[NUM_DIM] = {H, N, M};
            
            for (int j = 0; j < 3; j++) {
                int cx = x - !j;
                int cy = y - j % 2;
                int cz = z - !(j - 2);

                if (coor[j] - 1 >= 0) {
                    if (!arr[cx][cy][cz]) {
                        push(q, cx * H * N * M + cy * M + cz);

                        arr[cx][cy][cz] = 1;
                    }    
                }
            }

            for (int j = 0; j < 3; j++) {
                int cx = x + !j;
                int cy = y + j % 2;
                int cz = z + !(j - 2);

                if (coor[j] + 1 < axis[j]) {
                    if (!arr[cx][cy][cz]) {
                        push(q, cx * H * N * M + cy * M + cz);

                        arr[cx][cy][cz] = 1;
                    }    
                }
            }
        }
        date++;      
    }
    return date;
}

int minDate(int (*arr)[MAX_SIZE][MAX_SIZE], int H, int N, int M) {
    queue *q = initQueue(MAX_SIZE * MAX_SIZE * MAX_SIZE + 1);
    int date;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (arr[i][j][k] == 1)
                    push(q, i * H * N * M + j * M + k);
            }           
        }
    }        
    date = BFS(q, arr, H, N, M);
    
    free(q->qa);
    free(q);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (!arr[i][j][k])
                    return -1;
            }
        }
    }
    return date;
}