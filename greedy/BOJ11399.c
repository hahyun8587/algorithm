#include <stdio.h>

#define MAX_SIZE 1000

void swap(int *a, int *b);
void bubbleSort(int *arr, int n);
int minSum(int *arr, int n);

int main() {
    int arr[MAX_SIZE];
    int N;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    printf("%d\n", minSum(arr, N));    

    return 0;
}

void swap(int *a, int *b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *arr, int n) {
    for (int i = 0; i <= n - 2; i++) {
        for (int j = 0; j <= n - 2 - i; j++) {
            if (arr[j] >= arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

int minSum(int *arr, int n) {
    int pSum = 0;
    int cSum = 0;

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++) {
        pSum += arr[i];
        cSum += pSum;
    }
    return cSum;
}