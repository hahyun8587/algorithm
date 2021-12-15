#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 20000
#define INF 199991
#define NUM_EDGE 300000

typedef struct Node{
    int num;
    int w;
    struct Node *next;
} node;

typedef struct {
    int **ha;
    int n;
    int cap;
    int cmp;
    int (*type)(int *, int *, int);
} heap;

node* initNode(int num, int w);
void addNode(node **a, node **last, int s, int e, int w);
int descn(int *a, int *b, int indx);
heap* initHeap(int cap, int (*type)(int *, int *, int));
void swap(int **a, int **b);
int* swim(heap *h, int *x);
int empty(heap *h);
void sink(heap *h, int s);
int* delete(heap *h);
int* initAtrb(int num, int dist);
int min(int a, int b);
void freeHeap(heap *h);
void dijk(node **a, int *dist, int n, int s);
void freeLL(node **a, int n);
void aprintf(int *dist, int n);

int main() {
    node *a[MAX_SIZE];
    node *last[MAX_SIZE];
    int dist[MAX_SIZE];
    int V, E;
    int K;

    scanf("%d %d", &V, &E);
    scanf("%d", &K);    

    for (int i = 0; i < V; i++) 
        a[i] = NULL;

    for (int i = 0; i < E; i++) {
        int u, v, w;

        scanf("%d %d %d", &u, &v, &w);
        addNode(a, last, u, v, w);
    }
    dijk(a, dist, V, K);
    freeLL(a, V);
    aprintf(dist, V);

    return 0;
}

node* initNode(int num, int w) {
    node *n = (node *) malloc(sizeof(node));
    
    n->num = num;
    n->w = w;
    n->next = NULL;

    return n;
}

void addNode(node **a, node **last, int s, int e, int w) {
    if (!a[s - 1])
        last[s - 1] = a[s - 1] = initNode(e, w);    
    else 
        last[s - 1] = last[s - 1]->next = initNode(e, w);
}

int descn(int *a, int *b, int indx) {
    return a[indx] <= b[indx] ? 1 : 0;
}

heap* initHeap(int cap, int (*type)(int *, int *, int)) {
    heap *h = (heap *) malloc(sizeof(heap));

    h->ha = (int **) malloc(sizeof(int *) * (cap + 1));
    h->n = 0;
    h->cap = cap;
    h->cmp = 1;
    h->type = type;

    return h;
}

void swap(int **a, int **b) {
    int *temp = *a;

    *a = *b;
    *b = temp;
}

int* swim(heap *h, int *x) {
    if (h->n == h->cap)
        return NULL;

    h->ha[++h->n] = x; 

    for (int i = h->n; i > 1; i /= 2) {
        if (h->type(h->ha[i], h->ha[i / 2], h->cmp))
            swap(&h->ha[i], &h->ha[i / 2]);
        else 
            break;           
    }
    return x;
}

int empty(heap *h) {
    return !h->n ? 1 : 0;  
}

void sink(heap *h, int s) {
    int cNode = s;

    while (2 * cNode <= h->n) {
        int sNode;

        if (2 * cNode < h->n) 
            sNode = 2 * cNode + 1 - h->type(h->ha[2 * cNode], h->ha[2 * cNode + 1], h->cmp);
        else
            sNode = 2 * cNode;    
    
        if (!h->type(h->ha[cNode], h->ha[sNode], h->cmp)) 
            swap(&h->ha[cNode], &h->ha[sNode]);
        else 
            break;            

        cNode = sNode;    
    }
}

int* delete(heap *h) {
    swap(&h->ha[1], &h->ha[h->n--]);
    sink(h, 1);
    
    return h->ha[h->n + 1];
}

int* initAtrb(int num, int dist) {
    int *atrb = (int *) malloc(sizeof(int) * 2);

    atrb[0] = num;
    atrb[1] = dist;

    return atrb;
}

int min(int a, int b) {
    return a < b ? a : b;
}

void freeHeap(heap *h) {
    free(h->ha);
    free(h);
}

void dijk(node **a, int *dist, int n, int s) {
    heap *h = initHeap(NUM_EDGE, descn);
 
    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[s - 1] = 0;
    
    swim(h, initAtrb(s, 0)); 

    while (!empty(h)) {
        int *atrb = delete(h);
        int cNode = atrb[0];
        node *curr = a[cNode - 1];

        free(atrb);

        while (curr) {
            if (dist[cNode - 1] + curr->w < dist[curr->num - 1]) 
                swim(h, initAtrb(curr->num, dist[curr->num - 1] = dist[cNode - 1] + curr->w));
            
            curr = curr->next;
        }
    }
    freeHeap(h);    
}

void freeLL(node **a, int n) {
    for (int i = 0; i < n; i++) {
        node *curr = a[i];

        while (curr) {
            node *next = curr->next;

            free(curr);

            curr = next;
        }
    }
}

void aprintf(int *dist, int n) {
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("INF\n");
        else 
            printf("%d\n", dist[i]);    
    }
}