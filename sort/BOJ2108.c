#include <stdio.h>
#include <math.h>

#define MAX_SIZE 500000

int arithMean(int *arr, int n);
int median(int *arr, int n);
int mode(int *arr, int n);
int range(int *arr, int n);
void swap(int *a, int *b);
void merge(int *arr1, int n, int *arr2, int m);
void mergeSort(int *arr, int s, int e);

int main() {
    int arr[MAX_SIZE];
    int N;

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, N - 1);
    printf("%d\n%d\n%d\n%d\n", arithMean(arr, N), median(arr, N), mode(arr, N), range(arr, N));    

    return 0;
}

int arithMean(int *arr, int n) {
    int sum = 0;

    for(int i = 0; i < n; i++) 
        sum += arr[i];

    return lround((double)sum / n);      
}

int median(int *arr, int n) {
    return arr[(n - 1) / 2];
}

int mode(int *arr, int n) {
    int val;
    int vCount = 0, cCount = 1;
    int flag = 0;     

    for(int i = 0; i < n; i++) {
        if(i == n - 1 || arr[i] != arr[i + 1]) {
            if(cCount == vCount) {
                if(!flag) {
                    val = arr[i];
                    flag = 1;
                }
            }
            else if(cCount > vCount) {
                val = arr[i];
                vCount = cCount;
                flag = 0;
            }
            cCount = 1;
        }        
        else
            cCount++;
    }
    return val;
}

int range(int *arr, int n) {
    return arr[n - 1] - arr[0];
}

void swap(int *a, int *b) {
    int temp = *a;

    *a = *b;
    *b = temp;
}

void merge(int *arr1, int n, int *arr2, int m) {
    int tmp[MAX_SIZE];
    int j = 0, k = 0;
    
    for(int i = 0; i < n + m; i++) {
        if(j == n)
            tmp[i] = arr2[k++];
        else if(k == m)
            tmp[i] = arr1[j++];
        else
            tmp[i] = arr1[j] <= arr2[k] ? arr1[j++] : arr2[k++];
    }

    for(int i = 0; i < n + m; i++)
        arr1[i] = tmp[i];
}

void mergeSort(int *arr, int s, int e) {
    if(e - s + 1 == 1)
        return;
    else if(e - s + 1 == 2) {
        if (arr[s] > arr[e])
            swap(&arr[s], &arr[e]);

        return;
    }
    int mid = (s + e) / 2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(&arr[s], mid - s + 1, &arr[mid + 1], e - mid);
}