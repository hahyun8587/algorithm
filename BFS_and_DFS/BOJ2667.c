#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 25

typedef struct {
    int *qa;
    int n;
    int head;
    int tail;
} queue;

int BFS(int (*loc)[MAX_SIZE], int n, int *visited);
void numBlock(int (*src)[MAX_SIZE], int n, int *dst, int *m);

int main() {



    return 0;
}