#include <stdio.h>

#define MAX_SIZE 100

void getArr2D(int (*arr)[MAX_SIZE], int n, int m);
void dot(int (*src1)[MAX_SIZE], int n, int m, int (*src2)[MAX_SIZE], int p, int o, int (*dst)[MAX_SIZE]);

int main() {
    int arr1[MAX_SIZE][MAX_SIZE], arr2[MAX_SIZE][MAX_SIZE];
    int N, M, K;

    

    return 0;
}

void getArr2D(int (*arr)[MAX_SIZE], int n, int m) {
    



}

void dot(int (*src1)[MAX_SIZE], int n, int m, int (*src2)[MAX_SIZE], int p, int o, int (*dst)[MAX_SIZE]) {
    int sum;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < o; j++) {
            sum = 0;

            for (int k = 0; k < p; k++) 
               sum += src1[i - 1][k] * src2[k][j]; 

            dst[(i - 1) / o][(i - 1) % o] = sum;   
        }
    }
}
