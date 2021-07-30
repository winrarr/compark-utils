#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void addition(char *a, char *b, short size) {
    char b_sign = b[0];

    short carry = 0;
    for (short i = 0; i < size; i++) {
        short index = size-1-i;
        short res = a[index] - '0' + b[index] - '0' + carry;
        if (res < 2) {
            b[index] = res + '0';
            carry = 0;
        } else {
            b[index] = res % 2 + '0';
            carry = 1;
        }
    }

    printf("%s", b);
    if (b_sign == a[0] && b[0] != b_sign) {
        printf(" overflow");
    }
    if (carry) {
        printf(" carry");
    }
    printf("\n");
}

void subtraction(char *a, char *b, short size) {
    char b_sign = b[0];

    short carry = 0;
    for (short i = 0; i < size; i++) {
        short index = size-1-i;
        short res = a[index] - b[index] - carry;
        if (res >= 0) {
            b[index] = res + '0';
            carry = 0;
        } else {
            b[index] = (-res) % 2 + '0';
            carry = 1;
        }
    }

    printf("%s", b);
    if (b_sign != a[0] && b[0] == b_sign) {
        printf(" overflow");
    }
    printf("\n");
}

int main(int argc, char **args){
    if (argc != 2) {
        printf("You need to specify 2 bit-strings with an operation between them (e.g. 1010+0101 or 0100-0011).\n");
        exit(-1);
    }

    char *input = args[1];
    short size = strlen(input) / 2;

    char op = input[size];

    char *a = input;
    char *b = input + size + 1;

    switch (op) {
        case '+':
            addition(a, b, size);
            break;
        case '-':
            subtraction(a, b, size);
            break;
    }
}