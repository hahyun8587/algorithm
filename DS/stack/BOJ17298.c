#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 1000000

typedef struct {
    int *sa;
    int n;
    int p;
} stack;

typedef enum {
    false, true
} bool;

stack* initStack(int n);
int size(stack *s);
int push(stack *s, int x);
bool empty(stack *s);
int pop(stack *s);
int top(stack *s);
void NGE(int *src, int n, int *dst);

int main() {
    int arr[MAX_SIZE], dst[MAX_SIZE];
    int N;

    scanf("%d" ,&N);

    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    
    NGE(arr, N, dst);

    for (int i = 0; i < N; i++) 
        printf("%d ", dst[i]);

    putchar('\n');

    return 0;
}

stack* initStack(int n) {
    stack *s;

    s = (stack*) malloc(sizeof(stack));
    s->sa = (int*) malloc(sizeof(int) * n);
    s->n = n;
    s->p = 0;

    return s;
}

int size(stack *s) {
    return s->p;
}

int push(stack *s, int x) {
    if (size(s) == s->n)
        return -1;

    return s->sa[s->p++] = x;    
}

bool empty(stack *s) {
    return !s->p ? true : false;
}

int pop(stack *s) {
    if (empty(s))
        return -1;

    return s->sa[--s->p];
}

int top(stack *s) {
    if (empty(s))
        return -1;

    return  s->sa[s->p - 1]; 
}

void NGE(int *arr, int n, int *dst) {
    stack *v, *i;
    int count = 0;

    v = initStack(n);
    i = initStack(n);

    while (count != n) {
        if (empty(v) || arr[count] <= top(v)) {
            push(v, arr[count]);
            push(i, count++);
        }
        else {
            pop(v);

            dst[pop(i)] = arr[count];
        }
    }

    while (!empty(v)) {
        pop(v);

        dst[pop(i)] = -1;
    }
}