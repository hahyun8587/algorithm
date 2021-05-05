#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

#define MAX_COMMAND_SIZE 100001
#define MAX_ARRAY_SIZE 400002
#define MAX_NON_SIZE 100000
#define MAX_NOD_SIZE 4
#define NUM_EXIT 2
#define ASCII_VAL_NINE 57
#define ASCII_VAL_ZERO 48
#define REVERSE 'R'
#define ERROR "error"

typedef struct {
    int *da;
    int n;
    int head;
    int tail;
} deque;

deque* initDeque(int n)
int size(deque *d);
int push_back(deque *d, int x);
int empty(deque *d);
int pop_front(deque *d);
int pop_back(deque *d);
void parse(char *src, char (*dst)[MAX_NOD_SIZE]);
int strtoi(char *src);
int AC(int (**fp)(deque*), deque *d, char *cmd, char *arr, int non);
void dprintf_(int (**fp)(deque*), deque *d, int type);
void freeDeque(deque *d);

int main() {
    deque *d;
    int (*fp[NUM_EXIT])(deque*) = {pop_front, pop_back};
    char cmd[MAX_COMMAND_SIZE], arr[MAX_ARRAY_SIZE];
    int T;
    int n;

    d = initDeque(MAX_NON_SIZE + 1);

    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        scanf("%s", cmd);
        scanf("%d", &n);
        scanf("%s", arr);
        dprintf_(fp, d, AC(fp, d, cmd, arr, n));
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

void parse(char *src, char (*dst)[MAX_NOD_SIZE]) {
    int j = 0, k = 0;

    for (int i = 1; src[i] != '\0'; i++) {
        if (src[i] >= ASCII_VAL_ZERO && src[i] <= ASCII_VAL_NINE)
            dst[j][k++] = src[i];
        else {
            dst[j++][k] = '\0';
            k = 0;
        }
    }
}

int strtoi(char *str) {
    int digit;
    int sum = 0;
    
    digit = (int) pow(10, strlen(str) - 1);
    
    for (int i = 0; str[i] != '\0'; i++) {
        sum += (str[i] - ASCII_VAL_ZERO) * digit;
        digit /= 10;
    }
    return sum;
}

int AC(int (**fp)(deque*), deque *d, char *cmd, char *arr, int non) {
    char num[MAX_NON_SIZE][MAX_NOD_SIZE];
    int j = 0;
    int dir = 1;

    if (non) {
        parse(arr, num);

        for (int i = 0; i < non; i++)
            push_back(d, strtoi(num[i]));
    }

    for (int i = 0; cmd[i] != '\0'; i++) {
        if (cmd[i] == REVERSE) {
            j += dir;
            dir *= -1;
        }
        else {
            if (fp[j](d) == -1)
                return -1;
        }            
    }
    return j;
}

void dprintf_(int (**fp)(deque*), deque *d, int type) {
    if (type == -1) 
        printf(ERROR);
    else {
        if (empty(d)) 
            printf("[]");
        else {
            printf("[%d", fp[type](d));

            while (!empty(d)) {
                printf(",%d", fp[type](d));
            }
            putchar(']');
        }
    }
    putchar('\n');
}

void freeDeque(deque *d) {
    free(d->da);
    free(d);
}