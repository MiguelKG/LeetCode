#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main () {
    int numsSize = 4;
    int nums2[4] = {2,7,11,15};
    int target = 9, *returnSize;

    int *nums = (int *) malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        nums[i] = nums2[i];
    }
    
    twoSum(nums, numsSize, target, returnSize);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *returnNums = malloc(sizeof(int) * 2);

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                returnNums[0] = i;
                returnNums[1] = j;
                
                printf("%d - %d", returnNums[0], returnNums[1]);
                *returnSize = sizeof(returnNums) / sizeof(int);
                return returnNums;
            }
        }
    }

    returnNums[0] = -1;
    returnNums[1] = -1;

    *returnSize = sizeof(returnNums) / sizeof(int);
    return returnNums;
}