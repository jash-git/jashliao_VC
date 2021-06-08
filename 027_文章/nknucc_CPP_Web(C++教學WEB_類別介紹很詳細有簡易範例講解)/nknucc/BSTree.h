typedef int nodeValueType;
struct node{
	struct node *left, *right;
	nodeValueType value;
};



class CBSTree{

//operations
private:
	void insertNodes(struct node *pNode, nodeValueType v);
	
	void deleteTree(struct node *pNode);

	void printNodeValue(struct node *pNode);
	void printDescendingOrder(struct node *pNode);
	void printAscendingOrder(struct node *pNode);
	
	int searchNodes(struct node *pNode, nodeValueType v);
	
//constructor
public:
	CBSTree(){root = 0;}

	//destructor : need to clear all dynamic storages
public:
	~CBSTree(){ deleteTree(root); }

//operations
public:
	int find(nodeValueType v)
	{  return searchNodes(root, v);}
	void insertItem(nodeValueType v)
	{  insertNodes(root, v); }
	void deleteItem(nodeValueType v);
	void printOut(int ascending);

// attributes
private:
	struct node *root;
};
