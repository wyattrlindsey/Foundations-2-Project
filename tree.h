typedef struct Node {
	int data;
	//RED = 1, BLACK = 0
	int color;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
} Node;

struct Node createNew(int data) {};

void rotateLeft(struct Node *node, struct Node **r){};

void rotateRight(struct node *n, struct node **root){};