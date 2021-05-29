#include <stdio.h>

#define MAX_NUM 1000000000

typedef long long ll;

int min(ll a, int b);
int check(int n, int x, int k);
int _access(int n, int s, int e, int k);
int access(int n, int k);


int main() {
    int N, k;

    scanf("%d", &N);
    scanf("%d", &k);
    printf("%d\n", access(N, k));

    return 0;
}

int min(ll a, int b) {
    return a < b ? (int) a : b;
}

int check(int n, int x, int k) {
    int ns = 0, nx = 0;

    for (int i = 1; i <= n; i++) {
        int q = x / i;
        int r = x % i;

        if (i < q || i == q && r) 
            ns += 2 * i - 1;
        else if (i == q && !r) {
            ns += 2 * (i - 1);
            nx++;
        }
        else if (i > q && !r) {
            ns += 2 * (q - 1);
            nx += 2;
        }    
        else 
            ns += 2 * q;

        if (ns >= k)
            return 0;    
    }          
    return ns + nx < k ? 1 : 2;
}

int _access(int n, int s, int e, int k) {
    int mid = s + (e - s + 1) / 2;
    int occ = check(n, mid, k);

    if (occ == 0)
        return _access(n, s, mid - 1, k);
    else if (occ == 1)
        return _access(n, mid + 1, e, k);
    else 
        return mid;   
}

int access(int n, int k) {
    return _access(n, 1, min((ll) n * n, MAX_NUM), k);
}