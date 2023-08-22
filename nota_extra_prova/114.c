#include <stdio.h>
#include <stdlib.h>

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

void flatten( struct TreeNode *root ) {
    if ( root == NULL ) return;
    
    struct TreeNode *rootRight = root->right;
    struct TreeNode *rootLeft = root->left;
    root->left = NULL;

    flatten( rootLeft );
    flatten( rootRight );

    root->right = rootLeft;
    struct TreeNode *temp = root;

    while ( temp->right != NULL ) {
        temp = temp->right;
    }
    temp->right = rootRight;
}

int main ( ) {
    Node *root = createNode( 1 );
    insert( root, 2 );
    insert( root, 5 );
    insert( root, 3 );
    insert( root, 4 );
    insert( root, 5 );
    insert( root, 6 );
    printf("\n");
    flatten( root );
}