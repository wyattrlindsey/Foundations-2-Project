#include <stdio.h>
#include "tree.h"
#include <stdbool.h>

// Function to insert a data into the red-black tree
void insert(RedBlackTree* tree, int data) {
    Node* node = createNew(data);
    Node* parent = NULL;
    Node* current = tree->parent;

    // Find the appropriate position for the new node
    while (current != NULL) {
        parent = current;
        if (data < current->data)
            current = current->left;
        else
            current = current->right;
    }

    node->parent = parent;
    if (parent == NULL)
        tree->parent = node;
    else if (data < parent->data)
        parent->left = node;
    else
        parent->right = node;

    fixInsertion(tree, node);
}

// Function to fix violations caused by insertion
void fixInsertion(RedBlackTree* tree, Node *node) {
    while (node != tree->parent && node->parent->color == 1) {
        if (node->parent == node->parent->parent->left) {
            Node* uncle = node->parent->parent->right;
            if (uncle != NULL && uncle->color == 1) {
                node->parent->color = 0;
                uncle->color = 0;
                node->parent->parent->color = 1;
                node = node->parent->parent;
            } else {
                if (node == node->parent->right) {
                    node = node->parent;
                    leftRotate(tree, node);
                }
                node->parent->color = 0;
                node->parent->parent->color = 1;
                rightRotate(tree, node->parent->parent);
            }
        } else {
            Node* uncle = node->parent->parent->left;
            if (uncle != NULL && uncle->color == 1) {
                node->parent->color = 0;
                uncle->color = 0;
                node->parent->parent->color = 1;
                node = node->parent->parent;
            } else {
                if (node == node->parent->left) {
                    node = node->parent;
                    rightRotate(tree, node);
                }
                node->parent->color = 0;
                node->parent->parent->color = 1;
                leftRotate(tree, node->parent->parent);
            }
        }
    }
    tree->parent->color = 0;
}
