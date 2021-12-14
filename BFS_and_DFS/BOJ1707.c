#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 20000

typedef struct Node {
    int num;
    struct Node *next;
} node;

node* initNode(int e);
void addNode(node **a, node **last, int s, int e);
int _bipart(node **a, int *color, int node, int c);
int bipart(node **a, int *color, int n);
void aprintf(int isBip);
void freeAdj(node **a, int n);

int main() {
    int T;

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        node *a[MAX_SIZE];
        node *last[MAX_SIZE];
        int color[MAX_SIZE];
        int V, E;
        int s, e;
        
        scanf("%d %d", &V, &E);

        for (int j = 0; j < V; j++) {
            a[j] = NULL;
            color[j] = 0;
        }

        for (int j = 0; j < E; j++) {
            scanf("%d %d", &s, &e);
            addNode(a, last, s, e);
            addNode(a, last, e, s);
        }
        aprintf(bipart(a, color, V));
        freeAdj(a, V);
    }
    return 0;
}

node* initNode(int e) {
    node *n = (node *) malloc(sizeof(node));
    n->num = e;
    n->next = NULL;

    return n;
}

void addNode(node **a, node **last, int s, int e) {
    if (!a[s - 1]) 
        last[s - 1] = a[s - 1] = initNode(e);
    else  
        last[s - 1] = last[s - 1]->next = initNode(e);
}

int _bipart(node **a, int *color, int cNode, int c) {
    node *curr = a[cNode - 1];

    color[cNode - 1] = c;
    
    while (curr) {
        if (!color[curr->num - 1]) {
            if (!_bipart(a, color, curr->num, -c))
                return 0;
        }
        else if (color[curr->num - 1] == c)
            return 0;      

        curr = curr->next;      
    }
    return 1;
}

int bipart(node **a, int *color, int n) {
    for (int i = 0; i < n; i++) {
        if (!color[i]) {
            if(!_bipart(a, color, i + 1, -1))
                return 0;
        }
    }
    return 1;
}

void aprintf(int isBip) {
    isBip ? printf("YES\n") : printf("NO\n");
}

void freeAdj(node **a, int n) {
    for (int i = 0; i < n; i++) {
        node *curr, *next;

        curr = a[i];

        while (curr) {
            next = curr->next;
            
            free(curr);

            curr = next;
        }
    }    
}