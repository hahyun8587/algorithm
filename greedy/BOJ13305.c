#include <stdio.h>
#include <math.h>

#define MAX_SIZE 100000
#define MAX_DIGIT 19

typedef long long ll;

void minCost(ll *src1, int n, ll *src2, ll *dst, int spliter);
int digit(int a);
void lprintf(ll fwd, int bwd);

int main() {
    int N;
    ll dist[MAX_SIZE - 1];
    ll cost[MAX_SIZE];
    ll mCost[2] = {0, 0};
    int spliter;

    scanf("%d", &N);

    for (int i = 0; i <= N - 2; i++)
        scanf("%lld", &dist[i]);

    for (int i = 0; i < N; i++) 
        scanf("%lld", &cost[i]);

    spliter = (int) pow(10, MAX_DIGIT / 2);    

    minCost(dist, N - 1, cost, mCost, spliter);
    lprintf(mCost[0], mCost[1]);

    return 0;
}

void minCost(ll *src1, int n, ll *src2, ll *dst, int spliter) {
    ll cpc;
    int cpl;

    cpl = src2[0];

    for (int i = 0; i < n; i++) {
        cpc = cpl * src1[i];
        dst[0] += cpc / spliter;
        dst[1] += cpc % spliter;

        if (src2[i + 1] < cpl)
            cpl = src2[i + 1];         
    }
    dst[0] += dst[1] / spliter;
    dst[1] %= spliter;
}

int digit(int a) {
    int count = 0;

    do {
        a /= 10;
        count++;
    } while (a);

    return count;
}

void lprintf(ll fwd, int bwd) {
    if (fwd) {
        printf("%lld", fwd);

        for (int i = 1; i <= MAX_DIGIT / 2 - digit(bwd); i++)
            printf("0");

        printf("%d", bwd);    
    }
    else {
        if (bwd) 
            printf("%d", bwd);
        else 
            printf("0");        
    }
    putchar('\n');
}