#include <stdio.h>

int divide(int a, int b, int c);
int combine(int val, int a, int b, int c);

int main() {
    


    return 0;
}

int combine(int val, int a, int b, int c) {
    return val * val * (1 + (c - 1) * (b % 2)) % c;
}

int divide(int a, int b, int c) {
    if (b == 1)
        return a % c;

    int val;
    
    val = !(b % 2) ? divide(a, b / 2, c) : divide(a, (b - 1) / 2, c);

    return combine(val, a, b, c);
}