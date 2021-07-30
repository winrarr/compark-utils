#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

long main(int argc, char **args){
    if (argc != 2) {
        printf("You need to specify the 2s complement string.\n");
        exit(-1);
    }

    char *input = args[1];

    int *max = malloc(sizeof(int));
    *max = (int)strlen(input);

    int add = 1;

    if (input[0] == '1') {
        for (int i = 0; i < *max; i++) {
            if (input[i] == '0') {
                input[i] = '1';
            } else {
                input[i] = '0';
            }
        }

        int i = *max-1;
        while (i > 0 && input[i] == '1') {
            i--;
        }

        input[i] = '1';

        for (int j = i+1; j < *max; j++) {
            input[j] = '0';
        }

        add = -1;
    }

    int res = 0;
    for (int i = 0; i < *max; i++) {
        int index = *max-1-i;
        if (input[index] == '1') {
            res += add; 
        }
        add *= 2;
    }

    printf("%d\n", res);
}