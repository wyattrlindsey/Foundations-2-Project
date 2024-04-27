#include <stdio.h>
#include "tree.h"
#include <stdbool.h>

Node *createNew(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->color = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

bool compareStruct(Node node1, Node node2)
{
    if ((node1.data == node2.data) && (node1.color == node2.color) && (node1.left == node2.left) && (node1.right == node2.right) && (node1.parent == node2.parent))
    {
        return true;
    }
}

void rotateLeft(Node node) {
    Node* parent = node.parent;
    Node* rightChild = node.right;

    node.right = rightChild->left;
    if (rightChild->left != NULL) {
        *(rightChild->left->parent) = node;
    }

    *(rightChild->left) = node;
    node.parent = rightChild;

    if (parent == NULL) {
        Node root = *rightChild;
    } else if (compareStruct(*parent->left, node)) {
        parent->left = rightChild;
    } else if (compareStruct(*parent->right, node)) {
        parent->right = rightChild;
    } else {
        printf("ERROR: Node is not a child");
    }

    if (rightChild != NULL) {
        rightChild->parent = parent;
    }
}

void rotateLeft(Node node) {
    Node* parent = node.parent;
    Node* rightChild = node.right;

    node.right = rightChild->left;
    if (rightChild->left != NULL) {
        *(rightChild->left->parent) = node;
    }

    *(rightChild->left) = node;
    node.parent = rightChild;

    if (parent == NULL) {
        Node root = *rightChild;
    } else if (compareStruct(*parent->left, node)) {
        parent->left = rightChild;
    } else if (compareStruct(*parent->right, node)) {
        parent->right = rightChild;
    } else {
        printf("ERROR: Node is not a child");
    }

    if (rightChild != NULL) {
        rightChild->parent = parent;
    }
}
