#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int minDepthStep( struct TreeNode* root ) {
    int x = 0;
    int y = 0;
    
    if ( root == NULL ) {
        return INT_MAX;
    } else
    if ( root->left == NULL && root->right == NULL ) {
        return 1;
    } else {
        x = minDepthStep( root->left );
        y = minDepthStep( root->right );

        if ( x < y ) {
            return x + 1;
        } else {
            return y + 1;
        }
    }
}

int minDepth( struct TreeNode* root ) {
    int result;
    if ( root == NULL ) {
        return 0;
    } else {
        result = minDepthStep( root );
    }

    return result;
}