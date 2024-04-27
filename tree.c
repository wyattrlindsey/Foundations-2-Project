#include <stdio.h>
struct Node {
	int dat;
	char color;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
};

struct Node createNew(int data) {
    struct Node newNode;
    newNode.dat = data;
    newNode.color = 'b';
    newNode.left = NULL;
    newNode.right = NULL;
    newNode.parent = NULL;

    return newNode;
}

// Red-Black Tree structure
typedef struct RedBlackTree {
    Node *root;
} RedBlackTree;

void rotateLeft(struct Node *node, struct Node **r)
{
    if (!node || !node->right) return;
    //store pointer of right child
    struct Node *childR = node->right;

    //store y's left subtree's pointer as x's right child
    node->right = childR->left;

    //update parent pointer of x's right
    if (node->right != NULL) node->right->parent = node;

    //update y's parent pointer
    childR->parent = node->parent;

    // if x's parent is null make y as root of tree
    if (node->parent == NULL) {
        (*r) = childR;
    } else if (node == node->parent->left) {
        node->parent->left = childR;
    } else {
        node->parent->right = childR;
    }
    // make x as left child of y
    childR->left = node;

    //update parent pointer of x
    node->parent = childR;
}

void rotateRight(struct node *n, struct node **root)
{
    if (!y || !y->left)
        return ;
    struct node *x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;
    x->parent =y->parent;
    if (x->parent == NULL)
        (*root) = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else y->parent->right = x;
    x->right = y;
    y->parent = x;
}

//iteration