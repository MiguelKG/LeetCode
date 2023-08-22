#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode Node;

bool hasPathSumStep( struct TreeNode *root, int targetSum, int currentSum ) {
    if ( root == NULL ) return false;

    currentSum += root->val;

    if ( root->right == NULL && root->left == NULL ) {
        if ( currentSum == targetSum ) return true;
    }

    if (
        hasPathSumStep( root->left, targetSum, currentSum ) ||
        hasPathSumStep( root->right, targetSum, currentSum )
    ) {
        return true;
    }

    return false;
}

bool hasPathSum(struct TreeNode* root, int targetSum){
    int currentSum = 0;

    return hasPathSumStep( root, targetSum, currentSum );
}

