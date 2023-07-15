#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize);

int main () {
    int digits[] = {9};
    plusOne(digits, sizeof(digits) / sizeof(int), 0);
}

int* plusOne(int* digits, int digitsSize, int* returnSize){
    int *number = malloc(digitsSize * sizeof(int)), numberSize = 0;
    int needRealloc = 0;
    
    for (int i = digitsSize - 1; i >= 0; i--) {
        numberSize++;
        number[i] = digits[i];
    }

    number[numberSize - 1]++;

    if (number[numberSize - 1] > 9) {
        for (int i = numberSize - 1; i >= 0; i--) {
            if (number[i] > 9) {
                number[i] = 0;

                if (i - 1 >= 0) {
                    number[i - 1]++;
                } else {
                    needRealloc = 1;
                }
            }
        }
    }

    if (needRealloc) {
        numberSize++;
        number = (int *) realloc(number, (numberSize) * sizeof(int));

        for (int i = numberSize - 1; i >= 1; i--) {
            number[i] = number[i - 1];
        }

        number[0] = 1;
    }

    for (int i = 0; i < numberSize; i++) {
        printf("%d ", number[i]);
    }

    *returnSize = numberSize;
    return number;
}