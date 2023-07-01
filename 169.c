#include <stdio.h>

int majorityElement(int* nums, int numsSize);

int main () {
    int nums[7] = {2,2,1,1,1,2,2};
    majorityElement(nums, sizeof(nums) / sizeof(int));
}

int majorityElement(int* nums, int numsSize){
    int amount = 0, majority = -1, numTemp = -1, majorityAmount = 0;

    for (int i = 0; i < numsSize; i++) {
        amount = 1;

        if (nums[i] != -1 && nums[i] != majority) {
            numTemp = nums[i];
            for (int i2 = i + 1; i2 < numsSize; i2++) {
                if (nums[i] == nums[i2]) {
                    nums[i2] = -1;
                    amount++;
                }
            }

            if (amount > majorityAmount) {
                majority = numTemp;
                if (amount > numsSize / 2) break;
                majorityAmount = amount;
            }
        }
    }

    printf("%d", majority);
    return majority;
}

//tentei deixar o código o mais otimizado possível (tempo de execução e memória)