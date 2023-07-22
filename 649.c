#include <stdio.h>
#include <string.h>

char * predictPartyVictory(char * senate);

int main () {
    char senate[] = "DRRDRDRDRDDRDRDR";
    predictPartyVictory(senate);
}

char * predictPartyVictory(char * senate) {
    int end = 0;
    char vote;
    int dWin, rWin;

    while (end == 0) {
        for (int i = 0, j; i < strlen(senate); i++) {
            if (senate[i] != ' ') {
                if (senate[i] == 'R') {
                    vote = 'D';
                } else {
                    vote = 'R';
                }

                if (i == strlen(senate) - 1) {
                    j = 0;
                } else {
                    j = i + 1;
                }

                while (vote != senate[j] && j != i) {
                    if (j == strlen(senate) - 1) {
                        j = 0;
                    } else {
                        j++;
                    }
                }

                if (j != i) {
                    senate[j] = ' ';
                }
            }
        }

        dWin = 0, rWin = 0;
        for (int i = 0; i < strlen(senate); i++) {
            if (senate[i] == 'D') {
                dWin = 1;
            } else
            if (senate[i] == 'R') {
                rWin = 1;
            }
        }
        if (dWin != rWin) end = 1;
    }

    if (dWin) {
        printf("Dire");
        return "Dire";
    } else {
        printf("Radiant");
        return "Radiant";
    }
    return " ";
}