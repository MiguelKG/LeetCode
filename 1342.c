#include <stdio.h>

int main () {
    int c = 0, n;
    printf("Número: ");
    scanf("%d", &n);

    if (n < 0) n = 0;
    else if (n > 1000000) n = 1000000;
    
    while (n != 0) {
        c++;
        printf("Passo %d: %d => ", c, n);
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n -= 1;
        }
        printf("%d\n", n);
    }

    printf("%d passos foram necessário para a resolução", c);
}