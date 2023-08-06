#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool hasAlternatingBits(int n);

int main () {
    hasAlternatingBits(3);
}

bool hasAlternatingBits(int n) {
    int result = n % 2 + 1, prior_result;
    while (n > 1) {
        prior_result = result;
        result = n % 2;
        n /= 2;
        if (result == prior_result) {
            return false;
        }
    }

    prior_result = result;
    result = n;
    if (result == prior_result) {
        return false;
    }

    return true;
}