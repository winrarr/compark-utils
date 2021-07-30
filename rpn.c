#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Stack* stack;

struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

void createStack(unsigned capacity) {
    stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(char item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

char pop() {
    if (isEmpty(stack))
        return '0';
    return stack->array[stack->top--];
}

// void print_stack() {
//     for (int i = 0; i <= stack->top; i++) {
//         printf("%c", stack->array[i]);
//     }
// }

char *rpn() {
    char *op = malloc(sizeof(char));
    *op = pop(stack);
    // printf("stack: ");
    // print_stack();
    // printf(", op: %c\n", *op);

    switch (*op) {
        case '+':
        case '-':
        case '*':
        case '/': ;
            char *right = rpn();
            char *left = rpn();

            char *buff = malloc(100*sizeof(char));

            if (*op != '*') strcpy(buff, "(");
            strcat(buff, left);
            strcat(buff, op);
            strcat(buff, right);
            if (*op != '*') strcat(buff, ")");

            return buff;

        default:
            return op;
    }
}

long main(int argc, char **args){
    if (argc != 2) {
        printf("You need to specify the RPN string.\n");
        exit(-1);
    }
    char *input = args[1];

    createStack(100);

    for (int i = 0; i < strlen(input); i++) {
        push(input[i]);
    }

    printf("%s\n", rpn(stack));
}
