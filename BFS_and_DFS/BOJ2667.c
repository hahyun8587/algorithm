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
void bubbleSort(int *arr, int n);
void numBlock(int (*src)[MAX_SIZE], int n, int *dst, int *m);


int main() {



    return 0;
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
            
        }
    }

}