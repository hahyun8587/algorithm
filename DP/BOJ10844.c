#include <stdio.h>

#define MAX_SIZE 100
#define DIVISOR 1000000000

typedef long long ll;

ll arrSum(int *arr, int n);
int stair(int n);

int main()
{
    int N;

    scanf("%d", &N);
    printf("%d\n", stair(N));

    return 0;
}

ll arrSum(int *arr, int n)
{
    ll sum = 0;

    for (int i = 0; i < n; i++)
        sum += arr[i];

    return sum;    
}

int stair(int n)
{
    int dp[MAX_SIZE][10];

    for (int i = 0; i < 10; i++)
        dp[0][i] = 1;

    for (int i = 1; i < MAX_SIZE; i++) {
        for (int j = 0; j < 10; j++) 
            dp[i][j] = ((j - 1 >= 0 ? dp[i - 1][j - 1] : 0) + (j + 1 <= 9 ? dp[i - 1][j + 1] : 0)) % DIVISOR; 
    }
    return arrSum(&dp[n - 1][1], 9) % DIVISOR;
}