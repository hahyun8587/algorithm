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
            int j = i > 0 ? i + x - 2 : x;
            int k = i < 3 ? i + y - 1 : y;
            int l = node + (2 * (i / 2) - 1) * ((n - 1) * (i % 2) + 1);

            if (loc[j][k] && !visited[l]) {
                push(q, l);

                visited[l] = 1;
                count++;
            }
        }
    }
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
        for (int j = 0; j < -i + n; j++) {
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
            if (src[i][j] && !visited[n * i + j]) {
                int len;

                if (len = BFS(src, n, visited, i, j) > 1)
                    visited[count++] = len;
            }
        }
    }
    

}


