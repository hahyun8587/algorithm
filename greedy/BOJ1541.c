#include <stdio.h>
#include <math.h>

#define MAX_SIZE 50
#define ASCII_VAL 48
#define ASCII_MINUS 45

int str2int(char *arr, int n);
int minVal(char *arr);

int main() {
    char arr[MAX_SIZE + 1];

    scanf("%s", arr);
    printf("%d\n", minVal(arr));

    return 0;
}

int str2int(char *arr, int n) {
    int unit;
    int val = 0;

    unit = (int) pow(10, n - 1);

    for (int i = 0; i < n; i++) {
        val += (arr[i] - ASCII_VAL) * unit;
        unit /= 10;
    }
    return val;
}

int minVal(char *arr) {
    int count = 0;
    int type = 1;
    int val = 0;
    int i;

    for (i = 0; arr[i] != '\0'; i++) {
        if (arr[i] >= ASCII_VAL)
            count++;
        else {
            val += type * str2int(&arr[i - count], count);

            if (type == 1 && arr[i] == ASCII_MINUS)
                type = -1; 

            count = 0;    
        }    
    }
    val += type * str2int(&arr[i - count], count);

    return val;
}