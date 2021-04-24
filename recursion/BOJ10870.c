#include <stdio.h>

#define MAX_SIZE 21

int fibo(int *mem, int n);

int main() {
    int n;
    int mem[MAX_SIZE];

    scanf("%d", &n);

    for (int i = 0; i <= n; i++)
        mem[i] = -1;

    printf("%d\n", fibo(mem, n));

    return 0;
}

int fibo(int *mem, int n) {
    if (mem[n] != -1)
        return mem[n];
    
    if (n == 0) 
        return mem[n] = 0;
    else if (n == 1) 
        return mem[n] = 1;
    
    return mem[n] = fibo(mem, n - 2) + fibo(mem, n - 1);
}