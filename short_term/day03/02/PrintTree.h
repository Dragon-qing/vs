struct TNode{
	char data;
	struct TNode* left;
	struct TNode* right;
};

TNode* LayersToTree(char *A, int n);////
void PrintTreeRootLeft(TNode* r, int layer);////
void DeleteTree(TNode* t);///