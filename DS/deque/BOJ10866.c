#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAX_SIZE 11
#define FUNC_NUM 8
#define COMMAND_PUSH_FRONT "push_front"
#define COMMAND_PUSH_BACK "push_back"
#define COMMAND_POP_FRONT "pop_front"
#define COMMAND_POP_BACK "pop_back"
#define COMMAND_SIZE "size"
#define COMMAND_EMPTY "empty"
#define COMMAND_FRONT "front"
#define COMMAND_BACK "back"

typedef struct {
    int *da;
    int n;
    int head;
    int tail;
} deque;

deque* initDeque(int n);
int size(deque *d);
int push_front(deque *d, int x);
int push_back(deque *d, int x);
int empty(deque *d);
int pop_front(deque *d);
int pop_back(deque *d);
int front(deque *d);
int back(deque *d);
void dprintf_(deque *d, char *str);
void freeDeque(deque *d);

int main() {
    deque *d;
    char str[MAX_SIZE];
    int N;

    scanf("%d", &N);

    d = initDeque(N + 1);

    for (int i = 1; i <= N; i++) {
        scanf("%s", str);
        dprintf_(d, str);
    }
    freeDeque(d);

    return 0;
}

deque* initDeque(int n) {
    deque *d;

    d = (deque *) malloc(sizeof(deque));
    d->da = (int *) malloc(sizeof(int) * n);
    d->n = n;
    d->head = d->n - 1;
    d->tail = 0;

    return d;
}

int size(deque *d) {
    return d->head >= d->tail ? d->n - (d->head + 1 - d->tail) : d->tail - (d->head + 1);     
}

int push_front(deque *d, int x) {
    if (size(d) == d->n - 1)    
        return -1;

    d->da[d->tail++] = x;
    d->tail %= d->n;

    return x;
}

int push_back(deque *d, int x) {
    if (size(d) == d->n - 1)
        return -1;

    d->da[d->head--] = x;

    if (d->head < 0)
        d->head = d->n - 1;
    
    return x;
}

int empty(deque *d) {
    return size(d) ? 0 : 1;
}

int pop_front(deque *d) {
    if (empty(d))
        return -1;

    d->tail--;

    if (d->tail < 0)
        d->tail = d->n - 1;

    return d->da[d->tail];    
}

int pop_back(deque *d) {
    if (empty(d))
        return -1;

    d->head = (d->head + 1) % d->n;    

    return d->da[d->head];
}

int front(deque *d) {
    if (empty(d))
        return -1;

    return d->tail ? d->da[d->tail - 1] : d->da[d->n - 1];
}

int back(deque *d) {
    if (empty(d))
        return -1;

    return d->da[(d->head + 1) % d->n];
}

void dprintf_(deque *d, char *str) {
    int (*fp1[])(deque*, int) = {push_front, push_back};
    int (*fp2[])(deque*) = {pop_front, pop_back, size, empty, front, back};
    char *fn[] = {COMMAND_PUSH_FRONT, COMMAND_PUSH_BACK, COMMAND_POP_FRONT, COMMAND_POP_BACK, COMMAND_SIZE, COMMAND_EMPTY, COMMAND_FRONT, COMMAND_BACK};

    for (int i = 0; i < FUNC_NUM; i++) {
        if (!strcmp(fn[i], str)) {
            if (i < 2) {
                int val;

                scanf("%d", &val);
                fp1[i](d, val);
            }
            else 
                printf("%d\n", fp2[i - 2](d));

            break;    
        }
    }
}

void freeDeque(deque *d) {
    free(d->da);
    free(d);
}