typedef struct Node {
	int data;
	//RED = 1, BLACK = 0
	int color;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
} Node;

Node* createNew(int data);
void rotateLeft(Node node);
void rotateRight(Node node);
