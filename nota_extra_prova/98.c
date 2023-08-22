#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode Node;

Node* createNode( int val ) {
    Node* node = ( Node* ) malloc ( sizeof( Node ) );
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void insert ( Node *root, int val ) {
    Node *newNode = createNode( val );
    Node *temp = root;
    Node *tempParent = NULL;

    while ( temp != NULL ) {
        tempParent = temp;

        if ( val > temp->val ) {
            temp = temp->right;
        } else
        if ( val < temp->val ) {
            temp = temp->left;
        } else {
            return;
        }
    }

    if ( val > tempParent->val ) {
        tempParent->right = newNode;
    } else {
        tempParent->left = newNode;
    }
}

bool isValidBSTStep( struct TreeNode *node, long int minValue, long int maxValue ) {
    bool result;
    if ( node == NULL ) return true;

    if ( node->val <= minValue || node->val >= maxValue ) return false;

    result = ( isValidBSTStep( node->left, minValue, node->val ) &&
        isValidBSTStep( node->right, node->val, maxValue ) );

    return result;
}

bool isValidBST( struct TreeNode *root ) {  
    if ( root == NULL ) return true;

    return isValidBSTStep( root, LONG_MIN, LONG_MAX );
}

void preOrder( Node *root ) {
    if ( root == NULL ) return;

    printf( "%d ", root->val );
    preOrder( root->left );
    preOrder( root->right );
}


int main ( ) {
    Node *root = createNode( 2 );
    insert( root, 1 );
    insert( root, 3 );
    preOrder( root );
    int result = isValidBST( root );
    printf( "\n%d", result );
}