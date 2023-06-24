#include <stdio.h>
#include <stdlib.h>

int* shuffle(int* nums, int numsSize, int n, int *returnSize);

int main () {
    int v[8] = {2,5,1,3,4,7};
    shuffle (v, 6, 3, 3);
    printf("\n");
}

int* shuffle(int* nums, int numsSize, int n, int *returnSize){
    int *rnums = (int *) malloc(sizeof(int) * n * 2);
    
    for (int i = 0, i2 = 0; i < n * 2; i+=2) {
        rnums[i] = nums[i2];
        rnums[i + 1] = nums[i2 + n];
        i2++;
    }

    for (int i = 0; i < (n * 2); i++) {
        printf("%d ", rnums[i]);
    }

    *returnSize = n*2;
    return rnums;
}