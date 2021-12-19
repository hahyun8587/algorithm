#include <stdio.h>

#define MAX_SIZE 800
#define INF 799001
#define NUM_LAYOVER 2

int min(int a, int b);
void dijk(int (*a)[MAX_SIZE], int *dist, int n, int s);
int minDist(int (*a)[MAX_SIZE], int n, int s, int v1, int v2, int e);

int main() {
    int a[MAX_SIZE][MAX_SIZE];
    int N, E;
    int v1, v2;

    


    return 0;
}

int min(int a, int b) {
    return a < b ? a : b;
}

void dijk(int (*a)[MAX_SIZE], int *dist, int n, int s) {
    int visited[MAX_SIZE];
    
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[s - 1] = 0;
    
    for (int i = 0; i < n; i++) {
        int minIndx;
        int isInit = 0, isRem = 0;

        for (int j = 0; j < n; j++) {
            if (isInit && isRem)
                break;
            
            if (!isInit && !visited[j]) {
                minIndx = j;
                isInit = 1;
            }

            if (!isRem && (!visited[j] && dist[j] != INF))
                isRem = 1;    
        }

        if (!isRem)
            break;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < dist[minIndx])
                minIndx = j;
        }
        visited[minIndx] = 1;

        for (int j = 0; j < n; j++) {
            if (a[minIndx][j])
                dist[j] = min(dist[minIndx] + a[minIndx][j], dist[j]);
        }
    }        
}

int minDist(int (*a)[MAX_SIZE], int n, int s, int v1, int v2, int e) {
    int dist[NUM_LAYOVER + 1][MAX_SIZE];
    int sNode[] = {s, v1, v2}; 
    int ans;

    for (int i = 0; i < NUM_LAYOVER + 1; i++) 
        dijk(a, dist[i], n, sNode[i]);

    ans = min(dist[0][v1 - 1] + dist[1][e - 1], dist[0][v2 - 1] + dist[2][e - 1]);

    return ans < INF ? ans : -1; 
}