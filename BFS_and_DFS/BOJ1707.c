#include <stdio.h>

#define MAX_SIZE 20000

int bipart(int (*a)[MAX_SIZE], int *color, int n, int node, int c);

int main() {
    int a[MAX_SIZE][MAX_SIZE];
    int T;

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int V, E;

        scanf("%d %d", &V, &E);

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) 
                a[i][j] = 0;
        }

        for (int i = 0; i < E; i++) {
            int s, e;

            scanf("%d %d", &s, &e);

            a[s - 1][e - 1] = 1;
        }


    }


    return 0;
}

int bipart(int (*a)[MAX_SIZE], int *color, int n, int node, int c) {
    color[node] = c;

    for (int i = 0; i < n; i++) {
        if (a[node][i]) {
            if (!color[i]) {
                if (!bipart(a, color, n, i, -c))
                    return 0;
            }
            else {
                if (c == color[i])
                    return 0;
            }
        }
    }
    return 1;
}