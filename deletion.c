#include <stdio.h>
#include <stdbool.h>

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

// Returns pointer to sibling
struct Node Sibling()
{
    // Sibling null if no parent
    if (parent == NULL)
        return NULL;
 
    if (IsOnLeft())
        return parent.right;
 
    return parent.left;
}

// Check if node is left child of parent
bool IsOnLeft() { return this == parent.left; }

    // Find node that does not have a left child
    // in the subtree of the given node
struct Node Successor(struct Node x)
{
    struct Node temp = x;
    while (temp.left != NULL)
        temp = temp.left;
    return temp;
}

 // Find struct Node that replaces a deleted struct Node in BST
struct Node BSTreplace(struct Node x)
{
    // When struct Node has 2 children
    if (x.left != NULL && x.right != NULL)
        return Successor(x.right);
 
    // When leaf
    if (x.left == NULL && x.right == NULL)
        return NULL;
 
    // When single child
    return x.left != NULL ? x.left : x.right;
    }

// swaps the values
void SwapValues(struct Node u, struct Node v)
{
    int temp = u.val;
    u.val = v.val;
    v.val = temp;
}


// deletes the given struct Node
void deletion(struct Node v)
{
    struct Node u = BSTreplace(v);
 
    // True when u and v are both black
    bool bothBlack = ((u == NULL || u.color == 'b') && (v.color == 'b'));
    struct Node parent = v.parent;
 
    if (u == NULL) {
        // u is NULL therefore v is leaf
        if (v == root) {
            // v is root, making root NULL
            root = NULL;
        } else {
            if (bothBlack) {
                // u and v both black
                // v is leaf, fix double black at v
                FixDoubleBlack(v);
            } else {
                // u or v red, color u black
                if (v.Sibling() != NULL)
                    // Sibling is not NULL, make it red
                    v.Sibling().color = 'r';
            }
                // Delete v from the tree
                if (v.IsOnLeft()) {
                    parent.left = NULL;
                } else {
                    parent.right = NULL;
                }
            }
            return;
        }
 
        if (v.left == NULL || v.right == NULL) {
            // v has 1 child
            if (v == root) {
                // v is root, assign the value of u to v,
                // and delete u
                v.val = u.val;
                v.left = v.right = NULL;
                deletion Node(u);
            } else {
                // Detach v from tree and move u up
                if (v.IsOnLeft()) {
                    parent.left = u;
                } else {
                    parent.right = u;
                }
                u.parent = parent;
 
                if (uvBlack) {
                    // u and v both black, fix double black
                    // at u
                    FixDoubleBlack(u);
                } else {
                    // u or v red, color u black
                    u.color = 'b';
                }
            }
            return;
        }
 
        // v has 2 children, swap values with successor and
        // recurse
        SwapValues(u, v);
        deletion(u);
    }