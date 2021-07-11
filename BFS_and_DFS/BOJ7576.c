#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 1000
#define NUM_AXIS 2
#define NUM_COORD 1000000

typedef struct {
    int *qa;
    int n;
    int head;
    int tail;
} queue;

int BFS(int (*arr)[MAX_SIZE], int n, int m, int (*s)[NUM_AXIS], int p);
int minDate(int (*arr)[MAX_SIZE], int n, int m);

int main() {



    return 0;
}

int BFS(int (*arr)[MAX_SIZE], int n, int m, int (*s)[NUM_AXIS], int p) {
    queue *q;    

    q = initQueue(p == n * m ? n * m : n * m - 1);

    




}

