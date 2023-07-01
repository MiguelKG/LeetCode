#include <stdio.h>
#include <stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n);

int main () {
    int flowerBed[5] = {0};
    canPlaceFlowers(flowerBed, 1, 1);
}

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){

    int flowerbedC[flowerbedSize + 2];
    int flowerbedSizeC = sizeof(flowerbedC) / sizeof(int);
    flowerbedC[0] = 0;
    flowerbedC[flowerbedSizeC - 1] = 0;

    for (int i = 0; i < flowerbedSize; i++) {flowerbedC[i + 1] = flowerbed[i];};

    for (int i = 1; i < (flowerbedSizeC - 1) && n > 0; i++) {
        if (flowerbedC[i - 1] == 0 && flowerbedC[i] == 0 && flowerbedC[i + 1] == 0) {
            flowerbedC[i] = 1;
            n--;
        }
    }

    if (n > 0) {
        printf("Não foi possível adicionar esta quantidade de flores\n");
        return false;
    }
    return true;

}