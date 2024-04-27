#include <stdio.h>
#include "tree.h"
#include "insert.h"
#include "search.h"
#include "test.h"

void test_search_empty_tree(void) {
    struct Node *root = NULL;

    struct Node *result = search(root, 13); 

    if (result == NULL) {
        printf("PASS: Search in empty tree returned NULL as expected.\n");
    } else {
        printf("FAIL: Search in empty tree returned a non-NULL result.\n");
    }
}

void test_search_one_node_tree(void) {
    struct Node *root = NULL;
    root = insert(root, 23); 

    struct Node *result = search(root, 23); 

    if (result != NULL && result->data == 23) {
        printf("PASS: Search in one-node tree returned the correct node.\n");
    } else {
        printf("FAIL: Search in one-node tree did not return the correct node.\n");
    }
}

void test_search_multiple_node_tree(void) {
    struct Node *root = NULL;
    root = insert(root, 23);
	root = insert(root, 26);
	root = insert(root, 17);
	root = insert(root, 34);

    struct Node *result1 = search(root, 23); 
	struct Node *result2 = search(root, 26);
	struct Node *result3 = search(root, 17);
	struct Node *result4 = search(root, 34);

    if (result1 != NULL && result1->data == 23 && result2 != NULL && result2->data == 26 && result3 != NULL && result3->data == 17 && result4 != NULL && result4->data == 34) {
        printf("PASS: Search in multiple-node tree returned the correct node.\n");
    } else {
        printf("FAIL: Search in multiple-node tree did not return the correct node.\n");
    }
}

// Function to perform in-order traversal
void in_order_traversal(Node *node) {
    if (node == NULL) return;
    in_order_traversal(node->left);
    printf("%d ", node->data);
    in_order_traversal(node->right);
}

int test_insert() {
    // Initialize red-black tree
    struct Node *root = NULL;

    // Insert some nodes into the tree
    insert(root, 10);
    insert(root, 20);
    insert(root, 5);
    insert(root, 30);
    insert(root, 15);
    insert(root, 25);

    // Perform in-order traversal to verify tree structure
    printf("In-order traversal: ");
    in_order_traversal(root);
    printf("\n");
}


int main(void) {
	test_search_empty_tree();
	test_search_one_node_tree();
	test_search_multiple_node_tree();
    test_insert();

	return 0;
}
