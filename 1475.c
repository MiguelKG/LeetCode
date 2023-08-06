#include <stdio.h>

int* finalPrices(int* prices, int pricesSize, int* returnSize);

int main () {
    int prices[] = {10, 1, 1, 6};
    finalPrices (prices, sizeof(prices) / sizeof(int), prices);
}

int* finalPrices(int* prices, int pricesSize, int* returnSize){
    for (int i = 0; i < pricesSize; i++) {
        for (int i2 = i; i2 < pricesSize; i2++) {
            if (prices[i2] <= prices[i] && i != i2) {
                prices[i] = prices[i] - prices[i2];
                break;
            }
        }
    }

    /**returnSize = pricesSize;

    for (int i = 0; i < pricesSize; i++) {
        printf("%d ", prices[i]);
    }*/
    return prices;
}