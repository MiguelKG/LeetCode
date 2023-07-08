#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char * shortestCompletingWord(char * licensePlate, char ** words, int wordsSize);

int main () {
    char licensePlate[] = "Ah71752";
    char *words[] = {"suggest","letter","of","husband","easy","education","drug","prevent","writer","old"};

    shortestCompletingWord(licensePlate, words, ( sizeof(words) / sizeof(words[0]) ));
}

char * shortestCompletingWord(char * licensePlate, char ** words, int wordsSize){
    int c = 0, change = 0, shortSize = -1, shortestWord = 0;
    char wordsCopy[wordsSize][15];

    for (int i = 0; i < wordsSize; i++) {
        strcpy(wordsCopy[i], words[i]);
    }

    for (int i = 0; i < wordsSize; i++) {
        c = 0;
        for (int j = 0; j < strlen(licensePlate); j++) {
            if (licensePlate[j] != ' ' && isdigit(licensePlate[j]) == 0) {
                    
                for (int i2 = 0; i2 < strlen(words[i]); i2++) {
                    /*
                    printf("%c = %c ( %s ) : %d\n",
                        licensePlate[j], words[i][i2], wordsCopy[i],
                        toupper(licensePlate[j]) == toupper(wordsCopy[i][i2]));
                    */
                        
                    if (toupper(licensePlate[j]) == toupper(wordsCopy[i][i2])) {
                        wordsCopy[i][i2] = ' ';
                        c++;
                        change = 1;
                        break;
                    }
                }

                if (change == 0) {
                    c = 0;
                    break;
                }
                change = 0;

            } else {
                c++;
            }
        }
        
        if (c == strlen(licensePlate)) {
            if (strlen(words[i]) < shortSize || shortSize == -1) {
                shortSize = strlen(words[i]);
                shortestWord = i;
            }
        }

    }

    printf("%d ", shortSize);
    printf("%s", words[shortestWord]);
    return words[shortestWord];
}