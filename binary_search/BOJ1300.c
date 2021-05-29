#include <stdio.h>

int check(int n, int x, int k);
int _access(int n, int s, int e, int k);
int access(int n, int k);

int main() {



    return 0;
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



    
}