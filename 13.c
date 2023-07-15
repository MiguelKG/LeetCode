#include <stdio.h>
#include <String.h>

int romanToInt(char * s);
int getRomanCharValue (char c) ;

int main () {
    char n[10] = "MMXIX";
    romanToInt(n);
}

/*
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/

int romanToInt(char * s){
    int lastCharValue = -1, number = 0, charValue;

    for (int i = 0; i < strlen(s); i++) {
        charValue = getRomanCharValue(s[i]);

        if (charValue <= lastCharValue || lastCharValue == -1) {
            number += charValue;
        } else {
            number -= lastCharValue;
            number += (charValue - lastCharValue);
        }
        
        lastCharValue = charValue;
    }

    printf("%d", number);
    return number;
}

int getRomanCharValue (char c) {
    switch (c) {
        case 'I':
            return 1;
            break;
        case 'V':
            return 5;
            break;
        case 'X':
            return 10;
            break;
        case 'L':
            return 50;
            break;
        case 'C':
            return 100;
            break;
        case 'D':
            return 500;
            break;
        case 'M':
            return 1000;
            break;
        default:
            return 0;
            break;
    }
}