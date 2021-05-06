#include <stdio.h>

#define MAX_SIZE 65
#define ASCII_VAL_ZERO 48

void divide(char (*arr)[MAX_SIZE], int xs, int xe, int ys, int ye);

int main() {
    char arr[MAX_SIZE - 1][MAX_SIZE];
    int N;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%s", arr[i]);

    divide(arr, 0, N - 1, 0, N - 1); 
    putchar('\n');   

    return 0;
}

void divide(char (*arr)[MAX_SIZE], int xs, int xe, int ys, int ye) {
    int val;
    int isSolid = 1;

    val = arr[xs][ys];

    for (int i = xs; i <= xe; i++) {
        for (int j = ys; j <= ye; j++) {
            if (arr[i][j] != val) {
                isSolid = 0;

                break;
            }
        }
    }

    if (isSolid) {
        printf("%d", val - ASCII_VAL_ZERO);

        return;
    }

    int xh = xs + (xe - xs + 1) / 2 - 1;
    int yh = ys + (ye - ys + 1) / 2 - 1;

    putchar('(');
    divide(arr, xs, xh, ys, yh);
    divide(arr, xs, xh, yh + 1, ye);
    divide(arr, xh + 1, xe, ys, yh);
    divide(arr, xh + 1, xe, yh + 1, ye);
    putchar(')');
}