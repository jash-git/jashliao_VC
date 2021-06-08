#include <iostream.h>
#include "BSTree.h"

void main()
{
	nodeValueType a[]={30, 20, 10,  5, 80,
		               70, 60, 40, 50, 90,
					   28, 35, 45, 65, 80,
					   35, 25, 35, 32, 38, 
					   12, 35,  9,  1,  7};
	int i;
	
	CBSTree tree;

	for(i=0; i<25; i++)
		tree.insertItem(a[i]);

	tree.printOut(0);
	cout <<endl;

	tree.deleteItem(30);
	tree.printOut(0);
	cout <<endl;

	tree.deleteItem(70);
	tree.printOut(0);
	cout <<endl;

	tree.deleteItem(35);
	tree.printOut(0);
	cout <<endl;

	tree.deleteItem(90);
	tree.printOut(0);
	cout <<endl;

}