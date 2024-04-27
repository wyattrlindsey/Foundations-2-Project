#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

typedef struct Node {
	int data;
    //RED = 1, BLACK = 0
	bool color;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
} Node;

Node *createNew(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->color = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

// Function to insert a data into the red-black tree
void insert(Node* tree, int data) {
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
void fixInsertion(RedBlackTree* tree, Node* node) {
    while (node != tree->parent && node->parent->color == 'R') {
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
    tree->parent->color = 'B';
}
