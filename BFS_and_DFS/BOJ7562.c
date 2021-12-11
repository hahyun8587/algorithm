#include <stdio.h>
#include <malloc.h>

#define NUM_NODE 90000
#define NUM_DIRECTION 8

typedef struct {
    int *qa;
    int n;
    int head;
    int tail;
} queue;

typedef enum {
    false, true
} bool;

int BFS(int sx, int sy, int ex, int ey, int n);
void search(queue *q, int *isPushed, int cNode, int n, int m);

int main() {



    return 0;
}

void search(queue *q, int *isPushed, int cNode, int n, int m) {
    for (int i = 0; i < NUM_DIRECTION / 2; i++) {
        int nNode = cNode + (i < 2 ?  -1 : 1) * (m + 1) * n + (m - 2 - (2 * m - 4) * (i % 2));            

        if (!isPushed[nNode]) {
            push(q, nNode);

            isPushed[nNode] = 1;
        }
    }
} 

int BFS(int sx, int sy, int ex, int ey, int n) {
    queue *q = initQueue(NUM_NODE + 1); 
    int isPushed[NUM_NODE];
    int s = n * sx + sy;
    int dist = -1;

    for (int i = 0; i < NUM_NODE; i++)
        isPushed[i] = 0;

    push(q, s);

    isPushed[s] = 1;

    while (!empty(q)) {
        int iter = size(q);

        for (int i = 0; i < iter; i++) {
            int cNode = pop(q);

            for (int j = 0; j < 2; j++) 
                search(q, isPushed, cNode, n, j);
        }
        

    }
}