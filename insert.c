#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "insert.h"

struct Node* insert(struct Node* root, int data) {
    // Create a new node with the given data
    struct Node* newNode = createNew(data);

    // If the tree is empty, make the new node the root and color it black
    if (root == NULL) {
        newNode->color = 0;
        return newNode;
    }

    // Traverse the tree to find the appropriate position for the new node
    struct Node* current = root;
    struct Node* parent = NULL;
    while (current != NULL) {
        parent = current;
        if (data < current->data)
            current = current->left;
        else if (data > current->data)
            current = current->right;
        else {
            // Duplicate value, do nothing
            free(newNode);
            return root;
        }
    }

    // Set the parent of the new node
    newNode->parent = parent;

    // Attach the new node to its parent
    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    // Fix any violations of the red-black tree properties
    // (not shown in this example)

    return root;
}
