#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 100000

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
int sum(int *arr, int n);

int main() {
    int arr[MAX_SIZE];
    int K;

    scanf("%d", &K);
    


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

int sum(int *arr, int n) {
    stack *s;
    int result = 0;

    s = initStack(n);

    for (int i = 0; i < n; i++) {
        if (arr[i])
            push(s, arr[i]);
        else
            pop(s);
    }

    for (int i = 0; i < size(s); i++) 
        result += s->sa[i];
    
    free(s->sa);
    free(s);

    return result;
}