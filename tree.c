#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"


Node *createNew(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->color = 1;
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
    return false;
}

void rotateRight(Node node) {
    Node* parent = node.parent;
    Node* lChild = node.left;

    node.left = lChild->right;
    if (lChild->right != NULL) {
    *lChild->right->parent = node;
    }

    *(lChild->right) = node;
    node.parent = lChild;

    if (parent == NULL) {
        Node root = *lChild;
    } else if (compareStruct(*parent->left, node)) {
        parent->left = lChild;
    } else if (compareStruct(*parent->right, node)) {
        parent->right = lChild;
    } else {
        printf("ERROR: Node is not a child");
    }

    if (lChild != NULL) {
        lChild->parent = parent;
    }
}

void rotateLeft(Node node) {
    Node* parent = node.parent;
    Node* rChild = node.right;

    node.right = rChild->left;
    if (rChild->left != NULL) {
        *(rChild->left->parent) = node;
    }

    *(rChild->left) = node;
    node.parent = rChild;

    if (parent == NULL) {
        Node root = *rChild;
    } else if (compareStruct(*parent->left, node)) {
        parent->left = rChild;
    } else if (compareStruct(*parent->right, node)) {
        parent->right = rChild;
    } else {
        printf("ERROR: Node is not a child");
    }

    if (rChild != NULL) {
        rChild->parent = parent;
    }
}
