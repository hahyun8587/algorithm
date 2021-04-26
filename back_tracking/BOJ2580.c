#include <stdio.h>

#define MAX_SIZE 9
#define NUM_AREA MAX_SIZE * 2
#define MAX_NUM_COOR MAX_SIZE * MAX_SIZE
#define NDIM 2

void initArr(int (*arr)[MAX_SIZE]);
int val2coor(int (*src)[MAX_SIZE], int (*dst)[NDIM]);
void val2vis(int (*src)[MAX_SIZE], int (*dst)[MAX_SIZE]);
int _sudoku(int (*src)[MAX_SIZE], int (*coor)[NDIM], int n, int (*visited)[MAX_SIZE], int (*dst)[MAX_SIZE], int count, int val);
void sudoku(int (*src)[MAX_SIZE], int (*coor)[NDIM], int n, int (*visited)[MAX_SIZE], int (*dst)[MAX_SIZE]);
void aprintf(int (*arr)[MAX_SIZE]);

int main() {
    int src[MAX_SIZE][MAX_SIZE], dst[MAX_SIZE][MAX_SIZE];
    int visited[NUM_AREA][MAX_SIZE];
    int coor[MAX_NUM_COOR][NDIM];
    int numCoor;

    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) { 
            scanf("%d", &src[i][j]);

            dst[i][j] = src[i][j];
        }
    }
    initArr(visited);

    numCoor = val2coor(src, coor);

    val2vis(src, visited);
    sudoku(src, coor, numCoor, visited, dst);
    aprintf(dst);

    return 0;
}

void initArr(int (*arr)[MAX_SIZE]) {
    for (int i = 0; i < NUM_AREA; i++) {
        for (int j = 0; j < MAX_SIZE; j++) 
            arr[i][j] = 0;
    }
}

int val2coor(int (*src)[MAX_SIZE], int (*dst)[NDIM]) {
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

int _sudoku(int (*src)[MAX_SIZE], int (*coor)[NDIM], int n, int (*visited)[MAX_SIZE], int (*dst)[MAX_SIZE], int count, int val) {
    int x = coor[count][0], y = coor[count][1];
    int nx = coor[count + 1][0], ny = coor[count + 1][1];

    dst[x][y] = val;
    visited[x][val - 1] = 1;
    visited[x / 3 * 3 + MAX_SIZE + y / 3][val - 1] = 1;
    count++;

    if (count == n) 
        return 1;

    for (int i = 0; i < MAX_SIZE; i++) {
        if (!visited[nx][i] && !visited[nx / 3 * 3 + MAX_SIZE + ny / 3][i]) {
            if (_sudoku(src, coor, n, visited, dst, count, i + 1))
                return 1;
        }
    }
    visited[x][val - 1] = 0;
    visited[x / 3 * 3 + MAX_SIZE + y / 3][val - 1] = 0;

    return 0;
}

void sudoku(int (*src)[MAX_SIZE], int (*coor)[NDIM], int n, int (*visited)[MAX_SIZE], int (*dst)[MAX_SIZE]) {
    int sx = coor[0][0], sy = coor[0][1];

    for (int i = 0; i < MAX_SIZE; i++) {
        if (!visited[sx][i] && !visited[sx / 3 * 3 + MAX_SIZE + sy / 3][i]) {
            if (_sudoku(src, coor, n, visited, dst, 0, i + 1))
                return;
        }
    }
}

void aprintf(int (*arr)[MAX_SIZE]) {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) 
            printf("%d ", arr[i][j]);    
    
        putchar('\n');
    }  
}