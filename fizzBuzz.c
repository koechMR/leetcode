#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char** fizzBuzz(int n, int* returnSize) {
    char** result = (char**)malloc(n * sizeof(char*));

    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            result[i - 1] = strdup("FizzBuzz");
        } else if (i % 3 == 0) {
            result[i - 1] = strdup("Fizz");
        } else if (i % 5 == 0) {
            result[i - 1] = strdup("Buzz");
        } else {
            int digits = snprintf(NULL, 0, "%d", i);
            result[i - 1] = (char*)malloc((digits + 1) * sizeof(char));
            snprintf(result[i - 1], digits + 1, "%d", i);
        }
    }

    *returnSize = n;
    return result;
}

void freeFizzBuzz(char** result, int returnSize) {
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
}
/**
* main - entry point 
* Return: 0 on succses
*/

int main() {
    int n = 20;
    int returnSize;
    char** result = fizzBuzz(n, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
    }

    freeFizzBuzz(result, returnSize);

    return 0;
}

