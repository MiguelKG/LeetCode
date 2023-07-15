#include <stdio.h>

int singleNumber(int* nums, int numsSize);

int main () {
    int nums[3] = {2, 2, 1};
    singleNumber(nums, sizeof(nums) / sizeof(int));
}

int singleNumber(int* nums, int numsSize){
    int single = -1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != -1) {
            for (int i2 = i; i2 < numsSize; i2++) {
                if (nums[i] == nums[i2] && i != i2) {
                    nums[i] = -1;
                    nums[i2] = -1;
                    break;
                }

                if (i2 == numsSize - 1) {
                    single = nums[i];
                }
            }
            if (single != -1) break;
        }
    }

    printf("%d", single);
    return single;
}