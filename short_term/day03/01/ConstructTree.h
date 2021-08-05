struct TNode{
	char data;
	struct TNode* left;
	struct TNode* right;
};

TNode* InPreToTree(char *pa, char *ia, int p1, int p2, int i1, int i2);
void PrintPostTravel(TNode* t);
void DeleteTree(TNode* t);