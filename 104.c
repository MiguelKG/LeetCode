#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth( struct TreeNode* root ) {
    int x = 0;
    int y = 0;

    if ( root == NULL ) {
        return 0;
    }

    x = maxDepth( root->left ) + 1;
    y = maxDepth( root->right ) + 1;

    if ( x > y ) {
        return x;
    } else {
        return y;
    }

    return x;
}