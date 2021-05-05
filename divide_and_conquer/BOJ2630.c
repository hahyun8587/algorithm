#include <stdio.h>

#define MAX_SIZE 128

void divide(int (*src)[MAX_SIZE], int *dst, int xs, int xe, int ys, int ye);

int main() {



    return 0;
}

void divide(int (*src)[MAX_SIZE], int *dst, int xs, int xe, int ys, int ye) {
    int val;
    int isSolid = 1;

    val = src[xs][ys];

    for (int i = xs; i <= xe; i++) {
        for (int j = ys; j <= ye; j++)
            
    }


}
