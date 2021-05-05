#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COMMAND_SIZE 100001
#define MAX_ARRAY_SIZE 400002
#define MAX_NON_SIZE 100000
#define MAX_NOD_SIZE 4
#define COMMA ','
#define ASCII_VAL_NINE 57
#define ASCII_VAL_ZERO 48
#define NUM_EXIT 2
#define ERROR "error"

typedef struct {
    int *da;
    int n;
    int head;
    int tail;
} deque;

deque* initDeque(int n);
int size(deque *d);
int empty(deque *d);
int pop_front(deque *d);
int pop_back(deque *d);
void parse(char *src, char (*dst)[MAX_NOD_SIZE]);
int strtoi(char *src);
void AC(deque *d, char *cmd, char *num);
void dprintf_(deque *d);
void freeDeque(deque *d);

int main() {




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

    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] == COMMA) {
            dst[j++][k] = '\0';
            k = 0;
        }
        else if (src[i] <= ASCII_VAL_NINE)
            dst[j][k++] = src[i];
    }
}

int strtoi(char *str) {
    int digit;
    int sum = 0;
    
    digit = pow(10, strlen(str) - 1);
    
    for (int i = 0; str[i] != '\0'; i++) {
        sum += (str[i] - ASCII_VAL_ZERO) * digit;
        digit /= 10;
    }
    return sum;
}

void AC(deque *d, char *cmd, char *num) {
    char num[MAX_NON_SIZE][MAX_NOD_SIZE];
    int (*fp[NUM_EXIT])(deque*, int) = {pop_front, pop_back};
  
    

    
    




}

void freeDeque(deque *d) {
    free(d->da);
    free(d);
}