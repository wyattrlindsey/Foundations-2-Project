#include <stdio.h>
#include "tree.h"
#include "search.h"

/* Finds a node with the same number as data and returns NULL if it doesn't exist
*/
struct Node *search(struct Node *root, int data) {
	//making a new node equal to the root
	struct Node *current = root;
    
	//traversing the tree
    while (current != NULL) {
		//returning the current node if its value is data
        if (data == current->data) {
            return current;
		//going into the left subtree if data is less than the current node
        } else if (data < current->data) {
            current = current->left;
		//going into the right subtree if data is greater than the current node
        } else {
            current = current->right;
        }
    }
    
	//returning NULL if no node has data as its value
    return NULL;
}
