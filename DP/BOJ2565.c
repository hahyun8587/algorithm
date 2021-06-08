#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 100

int **mmalloc(int n, int m);
void swap(int **a, int **b);
void bubbleSort(int **arr, int n, int std);
void LIS(int **arr, int n, int std);
int minCord(int **arr, int n);

int main() {



    return 0;
}

int **mmalloc(int n, int m) {
    int **arr;

    arr = (int **) malloc(sizeof(int *) * n);

    for (int i = 0; i < n; i++)
        arr[i] = (int *) malloc(sizeof(int) * m);

    return arr;
}

void swap(int **a, int **b) {
    int *temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int **arr, int n, int std) {
    for (int i = 0; i <= n - 2; i++) {
        for (int j = 0; j <= n - i - 2; j++) {
            if (arr[j][std] > arr[j + 1][std])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}