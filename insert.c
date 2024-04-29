#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "insert.h"

struct Node* insert(struct Node* root, int data) {
    //create a new node
    Node* new = createNew(data);

    //if the tree is empty, color new node black
    if (root == NULL) {
        new->color = 0;     //BLACK = 0
        return new;
    }

    //if the tree is not empty, find position for the new node
    Node* test = root;
    Node* parent = NULL;
    while (test != NULL) {
        parent = test;
        if (data < test->data) {
            test = test->left;
        } else if (data > test->data) {
            test = test->right;
        } else {
            free(new);
            return root;
        }
    }

    //add the new node to the tree
    new->parent = parent;
    if (data < parent->data) {
        parent->left = new;
    } else {
        parent->right = new;
    }
    return root;
}
