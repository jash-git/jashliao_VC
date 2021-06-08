#include <iostream.h>
#include "BSTree.h"

void CBSTree::deleteTree(struct node *pNode)
{
	if(pNode!=0)
	{
		deleteTree(pNode->left);
		deleteTree(pNode->right);
		delete pNode;
	}
}

void CBSTree::printNodeValue(struct node *pNode)
{

	cout << pNode->value <<" "; 
}


void CBSTree::printPreOrder(struct node *pNode)
{

}

void CBSTree::printAscendingOrder(struct node *pNode)
{
}

void CBSTree::printDescendingOrder(struct node *pNode)
{
}

void CBSTree:: printOut(int traversalType)
{
	if(traversalType == 0)
		printAscendingOrder(root);
	else
		printDescendingOrder(root);
}

int CBSTree:: searchNodes(struct node *pNode, nodeValueType v)
{
	if(pNode)
	{
		if(pNode->value == v)
			return 1;
		else if(pNode->value < v)
			return searchNodes(pNode->right, v);
		else return searchNodes(pNode->left, v);
	}
	else return 0;
}

void CBSTree::insertNodes(struct node *pNode, nodeValueType v)
{
	struct node *pTemp;
	
	if(root==0)//root == 0 ; the tree is empty
	{
		root = new struct node;
		root->value = v;
		root->left = 0;
		root->right = 0;
	}
	else
	{
		if(pNode->value > v)
		{
			if(!pNode->left)
			{
				pTemp = new struct node;
				pTemp->value = v;
				pTemp->left = 0;
				pTemp->right = 0;
				pNode ->left = pTemp;
			}
			else
				insertNodes(pNode->left, v);
		}
		else //in case equal value, then insert to the right subtree
		{    // delete must according to the same rule          
			if(!pNode->right)
			{
				pTemp = new struct node;
				pTemp->value = v;
				pTemp->left = 0;
				pTemp->right = 0;
				pNode ->right = pTemp;
			}
			else
				insertNodes(pNode->right, v);
		}
	}

}

void CBSTree::deleteItem(nodeValueType v)
{
	struct node *pPreviousNode=0, *pCurrentNode=0, *pTemp;

	pCurrentNode = root;

	while(pCurrentNode)
	{
		if(pCurrentNode->value > v)
		{
			pPreviousNode = pCurrentNode;
			pCurrentNode = pCurrentNode->left;
		}
		else if(pCurrentNode->value < v)
		{	pPreviousNode = pCurrentNode;
			pCurrentNode = pCurrentNode->right;
		}
		else // find the node
		{
			//delete a leaf ---
			if(pCurrentNode->left==0 && pCurrentNode->right==0)
			{
				//root is deleted
				if(pCurrentNode==root)
				{
					delete pCurrentNode;
					root = 0;
					pCurrentNode=0;
				}
				else
				{
					if(pPreviousNode->left == pCurrentNode)
						pPreviousNode->left = 0;
					else pPreviousNode->right = 0;
					delete pCurrentNode;
					pCurrentNode=0;
				}
			}//leaf case
			else if(pCurrentNode->left && pCurrentNode->right==0) // node has only left subtree
			{
				if(pPreviousNode==0) //i.e. pCurrentNode == root
				{
					root = pCurrentNode->left;
				}
				else // pPreviousNode != 0
				{
					if(pPreviousNode->left == pCurrentNode)
						pPreviousNode->left = pCurrentNode->left;
					else pPreviousNode->right = pCurrentNode->left;
				}
				delete pCurrentNode;
				pCurrentNode = 0;
			} // has only left subtree
			else if(pCurrentNode->left==0 && pCurrentNode->right) // node has only right subtree
			{
				pTemp = pCurrentNode->right;
				if(pPreviousNode==0) //i.e. pCurrentNode == root
				{
					root = pTemp;
				}
				else // pPreviousNode != 0
				{
					if(pPreviousNode->left == pCurrentNode)
						pPreviousNode->left = pTemp;
					else pPreviousNode->right = pTemp;
				}
				delete pCurrentNode;
				pCurrentNode = pTemp; //keep deleting
			} // has only right subtree
			else // node has two subtrees
			{
				//get the max of the left subtree
				pPreviousNode =  pCurrentNode;
				pTemp = pCurrentNode->left;
				while(pTemp->right)
				{
					pPreviousNode = pTemp;
					pTemp = pTemp->right;
				}
				pCurrentNode->value = pTemp->value;
				if(pTemp->left == 0)//reach to a leaf
				{
					if(pPreviousNode->left == pTemp)
						pPreviousNode->left = 0;
					else pPreviousNode->right = 0;
				}
				else // pTemp has a left subtree; 
				{    // obvious that pTemp has no right subtree 
					if(pPreviousNode->left == pTemp)
						pPreviousNode->left = pTemp->left;
					else pPreviousNode->right = pTemp->left;
				}
				delete pTemp;
				pPreviousNode = pCurrentNode;
				pCurrentNode = pCurrentNode->right;
			}//has two subtrees
		}//else find the node to be deleted
	}// while
}
