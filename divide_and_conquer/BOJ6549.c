#include <stdio.h>

#define MAX_SIZE 100000

typedef long long ll;

int min(int a, int b);
ll max(ll a, ll b);
ll maxBound(int *arr, int s, int mid, int e);
ll _maxArea(int *arr, int n, int s, int e);
ll maxArea(int *arr, int n);

int main() {



    return 0;
}

int min(int a, int b) {
    return a < b ? a : b;
}

ll max(ll a, ll b) {
    return a > b ? a : b;
}

ll maxBound(int *arr, int s, int mid, int e) {
    int minHei;
    int left = mid + 1;
    int right = mid + 2;
    ll maxArea;

    minHei = min(arr[mid], arr[mid + 1]);
    maxArea = (ll) (right - (left + 1)) * minHei; 

    while ()




}


ll _maxArea(int *arr, int n, int s, int e) {




}