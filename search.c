#include <stdio.h>
#include "tree.h"

/* Finds a node with the same number as data and returns NULL if it doesn't exist
*/
struct Node *search(struct Node *root, int data) {
	struct Node *p;

	p.data = root->data;

	while (p != NULL) {
		int dif = data - p->data;

		if (dif == 0){
			return p;
		}

		p = cmp < 0 ? p->left : p->right;
	}

	return NULL;
}