#include <stdio.h>
#include <stdlib.h>

int firstUniqChar (char * s);

int main () {
    firstUniqChar ("aabb");
}

int firstUniqChar(char * s){
    int baseCharInd = (int) 'a';
    int sSize;
    for (sSize = 0; s[sSize] != '\0'; sSize++);

    int table[26];

    for (int i = (int) 'a'; i <= (int) 'z'; i++) {
        table[i - baseCharInd] = 0;
    }

    for (int i = 0; i < sSize; i++) {
        table[s[i] - baseCharInd]++;
    }

    for (int i = 0; i < sSize; i++) {
        if (table[s[i] - baseCharInd] == 1) {
            printf("%d\n", i);
            return i;
        }
    }

    printf("-1\n");
    return -1;
}