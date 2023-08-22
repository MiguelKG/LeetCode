#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* invertTree( struct TreeNode* root ) {
    struct TreeNode *temp;

    if ( root == NULL ) {
        return NULL;
    }

    temp = root->left;
    root->left = invertTree( root->right );
    root->right = invertTree( temp );

    return root;
}