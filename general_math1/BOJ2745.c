#include <stdio.h>
#include <string.h>

#define MAX_SIZE 31

#define ASCII_COLON 58
#define ASCII_NUMBER_CONST 48
#define ASCII_LETTER_CONST 55

int a2i(char c);
int b2d(char *num, int b);

int main() {
    char N[MAX_SIZE];
    int B;

    scanf("%s %d", N, &B); 
    printf("%d\n", b2d(N, B));

    return 0;
}

int a2i(char c) {
    return c < ASCII_COLON ? c - ASCII_NUMBER_CONST : c - ASCII_LETTER_CONST;
}

int b2d(char *num, int b) {
    int n;
    int digit = 1;
    int dec = 0;

    n = strlen(num);

    for (int i = n - 1; i >= 0; i--) {
        dec += a2i(num[i]) * digit;
        digit *= b;
    }

    return dec;
}
