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

void in_order_traversal(Node* root) {
    char colorID = 'R';
    if (root != NULL) {
        in_order_traversal(root->left);
        if(root->color == 1) {
            colorID = 'R';
        } else {
            colorID = 'B';
        }
        printf("%d (%c) ", root->data, colorID);
        in_order_traversal(root->right);
    }
}

int check_tree(Node* root) {

    //initializing variables for counting black nodes recursively
    int right_black_nodes = 0;
    int left_black_nodes = 0;

    //root can't be null
    if(root == NULL) {
        printf("\nINSERTION FAILED: root is null");
        return 0;
    }

    //nodes color has to be 1 or 0 (red or black)
    if(root->color != 1 && root->color != 0) {
        printf("INSERTION FAILED: Node #%d has an invalid color type", root->data);
        return 0;
    }

    //root node MUST be black
    if(root->color != 0) {
        printf("INSERTION FAILED: Root node MUST be black", root->data);
        return 0;
    }

    //red nodes cannot have red children
    if (root->left != NULL && root->left->color == 1) {
        printf("INSERTION FAILED: Left child of node %d is red\n", root->data);
        return 0;
    }

    //red nodes cannot have red children
    if (root->right != NULL && root->right->color == 1) {
        printf("INSERTION FAILED: Right child of node %d is red\n", root->data);
        return 0;
    }

    //checking for same number of black nodes
    left_black_nodes = check_tree(root->left);
    right_black_nodes = check_tree(root->right);
    if (left_black_nodes != right_black_nodes) {
        printf("INSERTION FAILED: Uneven number of black nodes\n", root->data);
        return 0;
    }

    // Return the black height of the subtree rooted at this node
    return (root->color == 0) ? left_black_nodes + 1 : left_black_nodes;
}

void test_insert_multi_node() {
    // Initialize rb tree
    struct Node *root = NULL;
    
    // insert multiple nodes
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 12);

    //check tree
    if(check_tree(root)) {
        printf("PASS: Insert in multiple-node tree passed criteria, Red Black tree is valid\n");
    } else {
        printf("FAIL: (THIS IS THE EXPECTED CASE) Insert in multiple-node tree failed criteria, Red Black tree is invalid\n");
    }

    // Perform in-order traversal to verify tree structure
    printf("In-order traversal test for multi node tree (should be empty): ");
    in_order_traversal(root);
    printf("\n");

}


void test_insert_one_node() {
    // Initialize rb tree
    struct Node *root = NULL;

    //insert one node
    root = insert(root, 10);

    //check tree
    if (check_tree(root)) {
        printf("PASS: Insert in one tree passed criteria, Red Black tree is valid\n");
    } else {
        printf("FAIL: Insert in one tree failed criteria, Red Black tree is invalid\n");
    }

    // Perform in-order traversal to verify tree structure
    printf("In-order traversal test for one node tree: ");
    in_order_traversal(root);
    printf("\n");
}

void test_insert_no_nodes() {
    // Initialize rb tree
    struct Node *root = NULL;
    //root = insert(root, NULL);


    if (check_tree(root)) {
        printf("\nFAIL: Insert in empty tree passed criteria when Red Black tree should NOT be valid\n");
    } else {
        printf("\nPASS: Insert in empty tree failed criteria as expected, Red Black tree is invalid\n");
    }

    // Perform in-order traversal to verify tree structure
    printf("In-order traversal test for one node tree (should be empty): ");
    in_order_traversal(root);
}


int main(void) {
    printf("SEARCH TESTS:\n");
	test_search_empty_tree();
	test_search_one_node_tree();
	test_search_multiple_node_tree();
    printf("\nINSERTION TESTS:");
    test_insert_no_nodes();
    test_insert_one_node();
    test_insert_multi_node();

	return 0;
}
