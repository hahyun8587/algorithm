#include <stdio.h>

#define MAX_SIZE 11
#define NUM_OP 4
#define NUM_RESULT 2
#define INF 1000000000

int calc(int oprnd1, int oprnd2, int oprtr);
int max(int a, int b);
int min(int a, int b);
void _embed(int *src, int n, int *numOp, int *dst, int count, int op, int result);
void embed(int *src, int n, int *numOp, int *dst);

int main() {
    int N;
    int oprnd[MAX_SIZE], numOprtr[NUM_OP];
    int ext[NUM_RESULT] = {-INF, INF};

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &oprnd[i]);

    for (int i = 0; i < NUM_OP; i++)
        scanf("%d", &numOprtr[i]);

    embed(oprnd, N, numOprtr, ext);    
    
    for (int i = 0; i < NUM_RESULT; i++)
        printf("%d\n", ext[i]);

    return 0;
}

int calc(int oprnd1, int oprnd2, int oprtr) {
    int result;

    switch (oprtr) {
        case 0: result = oprnd1 + oprnd2;    

                break;
        case 1: result = oprnd1 - oprnd2;

                break;
        case 2: result = oprnd1 * oprnd2;

                break;
        case 3: result = oprnd1 / oprnd2;

                break;                        
    }
    return result;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

void _embed(int *src, int n, int *numOp, int *dst, int count, int op, int result) {
    result = calc(result, src[count + 1], op);
    numOp[op]--;
    count++;

    if (count == n - 1) {
        dst[0] = max(result, dst[0]);
        dst[1] = min(result, dst[1]);
    }
    else {
        for (int i = 0; i < NUM_OP; i++) {
            if (numOp[i])
                _embed(src, n, numOp, dst, count, i, result);          
        }
    }
    numOp[op]++;
}

void embed(int *src, int n, int *numOp, int *dst) {
    for (int i = 0; i < NUM_OP; i++) {
        if (numOp[i]) 
            _embed(src, n, numOp, dst, 0, i, src[0]);
    }   
}