#include <stdio.h>
#include <malloc.h>

#define MAX_NODE 2000
#define MAX_CAND 100
#define MAX_DIST 1000
#define INF (MAX_NODE - 1) * MAX_DIST + 1

typedef struct NODE {
    int e;
    int w;
    struct NODE *next;
} Node;

typedef struct {
    int **ha;
    int n;
    int cap;
    int (*type)(int *, int *, int);
} Heap;

Node* initNode(int e, int w);
void addNode(Node **a, Node **last, int s, int e, int w);
int descen(int *a, int *b, int std);
int* initArr(int node, int dist);
void aswap(int **a, int **b);
Heap* initHeap(int cap, int (*type)(int *, int *, int));
int empty(Heap *h);
int* swim(Heap *h, int *x);
void sink(Heap *h, int s);
int* delete(Heap *h);
void freeHeap(Heap *h);
void dijkstra(Node **a, int *dist, int n, int s, int e);
void match(int *dist1, int n, int *dist2, int cd, int *cand, int m, int *matched);
void swap(int *a, int *b);
void bubbleSort(int *arr, int n);
int findDst(Node **a, int *cand, int m, int *dst, int *n, int v, int e);
void aprintf(int *arr, int n);

int main() {
    int T;

    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        Node *adj[MAX_NODE], *last[MAX_NODE];
        int cand[MAX_CAND];
        int dst[MAX_CAND];
        int n, m, t;
        int s, g, h;
        int l;

        for (int j = 0; j < n; j++)
            adj[j] = NULL;

        scanf("%d %d %d", &n, &m, &t);
        scanf("%d %d %d", &s, &g, &h);

        int v[] = {s, g, h};

        for (int j = 1; j <= m; j++) {
            int a, b, d;

            scanf("%d %d %d", &a, &b, &d);
            addNode(adj, last, a, b, d);
            addNode(adj, last, b, a, d);
        }

        for (int j = 0; j < t; j++)
            scanf("%d", &cand[j]);

        l = findDst(adj, cand, t, dst, v, n, m);
        bubbleSort(dst, l);
        aprintf(dst, l);    
    }
    return 0;
}

Node* initNode(int e, int w) {
    Node *n;

    n = (Node *) malloc(sizeof(Node));    
    n->e = e;
    n->w = w;
    n->next = NULL;

    return n;
}

void addNode(Node **a, Node **last, int s, int e, int w) {
    if (!a[s - 1])
        last[s - 1] = a[s - 1] = initNode(e, w);
    else 
        last[s - 1] = last[s - 1]->next = initNode(e, w);
}

int descen(int *a, int *b, int std) {
    return a[std] < b[std] ? 1 : 0;
}

int* initArr(int node, int dist) {
    int *arr;

    arr = (int *) malloc(sizeof(int) * 2);
    arr[0] = node;
    arr[1] = dist;

    return arr;
}

void aswap(int **a, int **b) {
    int *temp = *a;
    
    *a = *b;    
    *b = temp;
}

Heap* initHeap(int cap, int (*type)(int *, int *, int)) {
    Heap *h;

    h = (Heap *) malloc(sizeof(Heap));
    h->ha = (int **) malloc(sizeof(int *) * (cap + 1));
    h->n = 0;
    h->cap = cap;
    h->type = type;

    return h;
}

int empty(Heap *h) {
    return !h->n ? 1 : 0;
}

int* swim(Heap *h, int *x) {
    if (h->n == h->cap)
        return NULL;

    h->ha[++h->n] = x;

    for (int i = h->n; i >= 2; i /= 2) {
        if (h->type(h->ha[i], h->ha[i / 2], 1))
            aswap(&h->ha[i], &h->ha[i / 2]);
        else 
            break;
    }
    return x;
}

void sink(Heap *h, int s) {
    int curr = s;

    while (curr * 2 <= h->n) {
        int cmp;

        if (curr * 2 == h->n)
            cmp = curr * 2;
        else if (h->type(h->ha[curr * 2], h->ha[curr * 2 + 1], 1))
            cmp = curr * 2;
        else    
            cmp = curr * 2 + 1;

        if (!h->type(h->ha[curr], h->ha[cmp], 1))
            aswap(&h->ha[curr], &h->ha[cmp]);
        else 
            break;    

        curr = cmp;
    }
}

int* delete(Heap *h) {
    if (empty(h))
        return NULL;

    aswap(&h->ha[1], &h->ha[h->n--]);
    sink(h, 1);

    return h->ha[h->n + 1];
}

void freeHeap(Heap *h) {
    free(h->ha);
    free(h);
}

void dijkstra(Node **a, int *dist, int n, int s, int e) {
    Heap *h;
    int *arr;
    int visited[MAX_NODE];
    
    h = initHeap(e * 2, descen);

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[s - 1] = 0;
    
    swim(h, initArr(s, 0));

    while (!empty(h)) {
        int *arr;
        int cNode, cDist;
        
        arr = delete(h);
        cNode = arr[0];
        cDist = arr[1];

        if (!visited[cNode - 1]) {
            Node *curr;
            
            visited[cNode - 1] = 1;
            curr = a[cNode - 1];

            while (1) {
                int nDist = cDist + curr->w;

                if (nDist < dist[curr->e - 1]) 
                    swim(h, initArr(curr->e, dist[curr->e - 1] = nDist));    
                
                if (!curr->next)
                    break;

                curr = curr->next;    
            }        
        }    
    }    
    freeHeap(h);
}

void match(int *dist1, int n, int *dist2, int cd, int *cand, int m, int *matched) {
    for (int i = 0; i < m; i++) {
        if (cd + dist2[cand[i] - 1] == dist1[cand[i] - 1])
            matched[i] = 1;
    }
}

void swap(int *a, int *b) {
    int temp = *a;

    *a = *b;
    *b= temp;     
}

void bubbleSort(int *arr, int n) {
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);    
        }
    }    
}

int findDst(Node **a, int *cand, int m, int *dst, int *n, int v, int e) {
    Node *curr = a[n[1] - 1];
    int matched[MAX_CAND];
    int dist[3][MAX_NODE];
    int indx = 0;
    
    for (int i = 0; i <= 2; i++) 
        dijkstra(a, dist[i], v, n[i], e);

    for (int i = 0; i < m; i++)
        matched[i] = 0;

    while (curr->e != n[2]) 
        curr = curr->next;

    for (int i = 1; i <= 2; i++) 
        match(dist[0], v, dist[-i + 3], dist[0][n[i] - 1] + curr->w, cand, m, matched);
    
    for (int i = 0; i < m; i++) {
        if (matched[i])
            dst[indx++] = cand[i];
    }
    bubbleSort(dst, indx);  

    return indx;
}

void aprintf(int *arr, int n) {
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);

    putchar('\n');
}