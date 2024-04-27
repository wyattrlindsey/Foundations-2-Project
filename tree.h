typedef struct Node {
	int data;
	int color;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
} Node;

Node* createNew(int data) {};

void rotateLeft(struct Node *node, struct Node **r){};

void rotateRight(struct node *n, struct node **root){};