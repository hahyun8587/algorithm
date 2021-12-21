#include <stdio.h>

#define MAX_SIZE 800
#define WEIGHT_INF 1001
#define DIST_INF 799001
#define MAX_DIST 2397000
#define NUM_LAYOVER 2

int min(int a, int b);
void dijk(int (*a)[MAX_SIZE], int *dist, int n, int s);
int path(int (*dist)[MAX_SIZE], int *node, int n);
int minDist(int (*a)[MAX_SIZE], int n, int s, int v1, int v2, int e);

int main() {
    int adj[MAX_SIZE][MAX_SIZE];
    int N, E;
    int v1, v2;

    scanf("%d %d", &N, &E);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) 
            adj[i][j] = WEIGHT_INF;
    }

    for (int i = 0; i < E; i++) {
        int a, b, c;

        scanf("%d %d %d", &a, &b, &c);

        adj[a - 1][b - 1] = min(adj[a - 1][b - 1], c);
        adj[b - 1][a - 1] = min(adj[b - 1][a - 1], c);        
    }
    scanf("%d %d", &v1, &v2);
    printf("%d\n", minDist(adj, N, 1, v1, v2, N));

    return 0;
}

int min(int a, int b) {
    return a < b ? a : b;
}

void dijk(int (*a)[MAX_SIZE], int *dist, int n, int s) {
    int visited[MAX_SIZE];
    
    for (int i = 0; i < n; i++) {
        dist[i] = DIST_INF;
        visited[i] = 0;
    }
    dist[s - 1] = 0;
    
    for (int i = 0; i < n; i++) {
        int minIndx;
        
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                minIndx = j;

                break;
            }
        }        

        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < dist[minIndx])
                minIndx = j;
        }

        if (dist[minIndx] == DIST_INF)
            break;

        visited[minIndx] = 1;

        for (int j = 0; j < n; j++) {
            if (a[minIndx][j] != WEIGHT_INF)
                dist[j] = min(dist[minIndx] + a[minIndx][j], dist[j]);
        }
    }        
}

int path(int (*dist)[MAX_SIZE], int *node, int n) {
    int a = dist[0][node[n + 1] - 1];
    int b = dist[-n + 2][node[3] - 1];
    int c = dist[n + 1][node[-n + 2] - 1];

    return a != DIST_INF && b != DIST_INF && c != DIST_INF ? a + b + c : MAX_DIST + 1; 
}

int minDist(int (*a)[MAX_SIZE], int n, int s, int v1, int v2, int e) {
    int dist[NUM_LAYOVER + 1][MAX_SIZE];
    int node[] = {s, v1, v2, e}; 
    int ans;

    for (int i = 0; i < NUM_LAYOVER + 1; i++) 
        dijk(a, dist[i], n, node[i]);
  
    ans = min(path(dist, node, 0), path(dist, node, 1));

    return ans < MAX_DIST + 1 ? ans : -1;
}