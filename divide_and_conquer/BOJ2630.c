#include <stdio.h>

#define MAX_SIZE 128
#define NUM_COLOR 2

void divide(int (*src)[MAX_SIZE], int *dst, int xs, int xe, int ys, int ye);

int main() {
    int N;
    int arr[MAX_SIZE][MAX_SIZE];
    int num[] = {0, 0};

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            scanf("%d", &arr[i][j]);
    }
    divide(arr, num, 0, N - 1, 0, N - 1);
    
    for (int i = 0; i < NUM_COLOR; i++)
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
        dst[val]++;

        return;
    }

    int xh = xs + (xe - xs + 1) / 2 - 1;
    int yh = ys + (ye - ys + 1) / 2 - 1;

    divide(src, dst, xs, xh, ys, yh);
    divide(src, dst, xs, xh, yh + 1, ye);
    divide(src, dst, xh + 1, xe, ys, yh);
    divide(src, dst, xh + 1, xe, yh + 1, ye);
}