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
