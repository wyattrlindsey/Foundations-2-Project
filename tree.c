#include <stdio.h>
#include <stdbool.h>

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

void rotateLeft(Node node) {
  Node parent = node.parent;
  Node rightChild = node.right;

  node.right = rightChild.left;
  if (rightChild.left != null) {
    rightChild.left.parent = node;
  }

  rightChild.left = node;
  node.parent = rightChild;

  replaceParentsChild(parent, node, rightChild);
}

void rotateLeft(Node node) {
  Node parent = node.parent;
  Node rightChild = node.right;

  node.right = rightChild.left;
  if (rightChild.left != null) {
    rightChild.left.parent = node;
  }

  rightChild.left = node;
  node.parent = rightChild;

  replaceParentsChild(parent, node, rightChild);
}