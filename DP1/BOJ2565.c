#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 100

int **mmalloc(int n, int m);
void swap(int **a, int **b);
void bubbleSort(int **arr, int n, int std);
int max(int a, int b);
int LIS(int **arr, int n, int std);
int minCord(int **arr, int n);
void mfree(int **arr, int n);

int main() {
    int **arr;
    int N;

    scanf("%d", &N);

    arr = mmalloc(N, 2);

    for (int i = 0; i < N; i++)
        scanf("%d %d", &arr[i][0], &arr[i][1]);

    printf("%d\n", minCord(arr, N));
    mfree(arr, N);

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

int max(int a, int b) {
    return a > b ? a : b;
}

int LIS(int **arr, int n, int std) {
    int dp[MAX_SIZE + 1];
    int ans = 0;

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 0; i <= n - 2; i++) {
        int val = 0;

        for (int j = 0; j <= i; j++) {
            if (arr[i + 1][std] > arr[j][std])
                val = max(dp[j + 1], val);    
        }
        dp[i + 2] = val + 1;
    }

    for (int i = 1; i <= n; i++)
        ans = max(dp[i], ans);   
    
    return ans;
}

int minCord(int **arr, int n) {
    bubbleSort(arr, n, 0); 
    
    return n - LIS(arr, n, 1);
}

void mfree(int **arr, int n) {
    for (int i = 0; i < n; i++)
        free(arr[i]);

    free(arr);    
}