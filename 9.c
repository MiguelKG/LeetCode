#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(int x);

int main () {
    isPalindrome(676);
    isPalindrome(12);
    isPalindrome(3489843);
    isPalindrome(100);
}

bool isPalindrome(int x){
    char number[100];
    sprintf(number, "%d", x);

    for(int i = 0; i <= strlen(number) / 2; i++) {
        if (number[i] != number[strlen(number) - i - 1]) return false;
    }

    printf("%d é palíndromo\n", x);
    return true;
}