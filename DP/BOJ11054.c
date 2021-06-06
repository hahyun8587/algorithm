#include <stdio.h>

int forward(int a, int b);
int backward(int a, int b);
int max(int a, int b);
int amax(int *arr, int n);
void LIS(int *arr, int n, int *dp, int reverse);
int LBS(int *arr, int n);

int main() {



    return 0;
}

int forward(int a, int b) {
    return a <= b ? 1 : 0;
}

int backward(int a, int b) {
    return a >= b ? 1 : 0;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int amax(int *arr, int n) {
    int val = 0;

    for (int i = 0; i < n; i++) 
        val = max(arr[i], val); 

    return val;
}

void LIS(int *arr, int n, int *dp, int reverse) {
    int (*fp[])(int, int) = { forward, backward };

    dp[(n - 1) * reverse + 1] += 1;

    for (int i = (n - 3) * reverse + 2; fp[reverse](i, n - (n - 1) * reverse); i += -2 * reverse + 1) {
        int val = 0;

        for (int j = (n - 1) * reverse; fp[reverse](j, i - 2 + 2 * reverse); i += 2 * reverse - 1) {
                    
        }
    }        



}