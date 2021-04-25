#include <stdio.h>

#define MAX_SIZE 9
#define NUM_AREA MAX_SIZE * 2
#define MAX_NUM_COOR MAX_SIZE * MAX_SIZE

int val2coor(int (*src)[MAX_SIZE], int (*dst)[2]);
void val2vis(int (*src)[MAX_SIZE], int (*dst)[MAX_SIZE]);
int sudoku(int (*src)[MAX_SIZE], int (*coor)[2], int (*visited)[MAX_SIZE], int (*dst)[MAX_SIZE], int x, int y, int val);
void aprintf(int (*arr)[MAX_SIZE]);

int main() {



    return 0;
}

int val2coor(int (*src)[MAX_SIZE], int (*dst)[2]) {
    int count = 0;
    
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            if (!src[i][j]) {
                dst[count][0] = i;
                dst[count][1] = j;
                count++;
            }   
        }
    }
    return count;
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

int sudoku(int (*src)[MAX_SIZE], int (*coor)[2], int (*visited)[MAX_SIZE], int (*dst)[MAX_SIZE], int x, int y, int val) {
    src[x][y] = val;
    visited[x][val - 1] = 1;
    visited[x / 3 * 3 + MAX_SIZE + y / 3][val - 1] = 1;

    if (nx == -1) 
        return 1;

    for (int i = 0; i < MAX_SIZE; i++) {
        if (!visited[nx][i] && !visited[nx / 3 * 3 + MAX_SIZE + ny / 3][i]) {
            if (sudoku(src, visited, dst, nx, ny, i + 1))
                return 1;
        }
    }
    




}