#include <stdio.h>
#include <stdlib.h>
#include <bool.h>
#include "tree.h"

// Function to insert a key into the red-black tree
void insert(RedBlackTree* tree, int key) {
    Node* node = createNode(key);
    Node* parent = NULL;
    Node* current = tree->root;

    // Find the appropriate position for the new node
    while (current != NULL) {
        parent = current;
        if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }

    node->parent = parent;
    if (parent == NULL)
        tree->root = node;
    else if (key < parent->key)
        parent->left = node;
    else
        parent->right = node;

    fixInsertion(tree, node);
}

// Function to fix violations caused by insertion
void fixInsertion(RedBlackTree* tree, Node* node) {
    while (node != tree->root && node->parent->color == 'R') {
        if (node->parent == node->parent->parent->left) {
            Node* uncle = node->parent->parent->right;
            if (uncle != NULL && uncle->color == 'R') {
                node->parent->color = 'B';
                uncle->color = 'B';
                node->parent->parent->color = 'R';
                node = node->parent->parent;
            } else {
                if (node == node->parent->right) {
                    node = node->parent;
                    leftRotate(tree, node);
                }
                node->parent->color = 'B';
                node->parent->parent->color = 'R';
                rightRotate(tree, node->parent->parent);
            }
        } else {
            Node* uncle = node->parent->parent->left;
            if (uncle != NULL && uncle->color == 'R') {
                node->parent->color = 'B';
                uncle->color = 'B';
                node->parent->parent->color = 'R';
                node = node->parent->parent;
            } else {
                if (node == node->parent->left) {
                    node = node->parent;
                    rightRotate(tree, node);
                }
                node->parent->color = 'B';
                node->parent->parent->color = 'R';
                leftRotate(tree, node->parent->parent);
            }
        }
    }
    tree->root->color = 'B';
}
