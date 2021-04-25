#include <stdio.h>

#define MAX_SIZE 9
#define NUM_AREA MAX_SIZE * 2

void val2vis(int (*src)[MAX_SIZE], int (*dst)[MAX_SIZE]);
int sudoku(int (*src)[MAX_SIZE], int (*visited)[MAX_SIZE], int (*dst)[MAX_SIZE], int x, int y, int val);
void aprintf(int (*arr)[MAX_SIZE]);

int main() {



    return 0;
}

void val2vis(int (*src)[MAX_SIZE], int (*dst)[MAX_SIZE]) {
    int val;

    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            if (val = src[i][j]) {
                dst[i][val - 1] = 1;                
                dst[i / 3 * 3 + MAX_SIZE + j / 3][val - 1] = 1;
            }
        }
    }
}

int sudoku(int (*src)[MAX_SIZE], int (*visited)[MAX_SIZE], int (*dst)[MAX_SIZE], int x, int y, int val) {
    int nx = -1, ny = -1;

    src[x][y] = val;
    
    for (int i = x; nx == -1 && i < MAX_SIZE; i++) {
        for (int j = i == x ? y + 1 : 0; j < MAX_SIZE; j++) {
            if (!src[i][j]) {
                nx = i;
                ny = j;

                break;      
            }                  
        }
    }

    if (nx == -1) 
        return 1;
    
    



}