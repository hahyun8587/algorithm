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
int BFS(int (*a)[MAX_SIZE], int n);

int main() {



    return 0;
}

int BFS(int (*a)[MAX_SIZE], int n) {
    queue *q;
    int visited[MAX_SIZE];

    q = initQueue(n - 1);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    push(q, 0);
    
    visited[0] = 1;    

    while (!empty(q)) {
        
    }

}