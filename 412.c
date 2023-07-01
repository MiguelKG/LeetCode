#include <stdio.h>

int main () {
    int n, fb;
    printf("Número: ");
    scanf("%d", &n);

    if (n < 1) n = 1;
    else if (n > 10000) n = 10000;
    
    for (int c = 0; c < n; c++) {
        fb = 0;
        if (c % 3 == 0) {
            printf("Fizz");
            fb = 1;
        }
        if (c % 5 == 0) {
            printf("Buzz");
            fb = 1;
        }
        if (fb == 0) printf("%d", c);
        printf("\n");
    }
}