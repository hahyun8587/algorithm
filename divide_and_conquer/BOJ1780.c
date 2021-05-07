#include <stdio.h>

#define MAX_SIZE 2187
#define NUM_TYPE 3
#define NUM_DIVISION 9

void divide(int (*src)[MAX_SIZE], int *dst, int xs, int xe, int ys, int ye);

int main() {
    int arr[MAX_SIZE][MAX_SIZE];
    int num[] = {0, 0, 0};
    int N;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            scanf("%d", &arr[i][j]);
    } 
    divide(arr, num, 0, N - 1, 0, N - 1);

    for (int i = 0; i < NUM_TYPE; i++)
        printf("%d\n", num[i]);

    return 0;
}

void divide(int (*src)[MAX_SIZE], int *dst, int xs, int xe, int ys, int ye) {
    int val;
    int isSolid = 1;

    val = src[xs][ys];

    for (int i = xs; i <= xe; i++) {
        for (int j = ys; j <= ye; j++) {
            if (src[i][j] != val) {
                isSolid = 0;

                break;
            }
        }
    }

    if (isSolid) {
        dst[val + 1]++;

        return;
    }

    int n = xe - xs + 1;

    for (int i = 0; i < NUM_DIVISION; i++)
        divide(src, dst, xs + n / 3 * (i / 3), xs + (i / 3 + 1) * n / 3 - 1, ys + n / 3 * (i % 3), ys + (i % 3 + 1) * n / 3 - 1);
}