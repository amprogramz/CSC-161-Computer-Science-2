//																		Alec McDaugale
//
//	This program is the main method provided


//Data
//68 43 10 56 77 82 61 82 33 56 72 66 99 88 12 6 7 21 -999

#include <iostream>
#include "binarySearchTree.h"
//#include "orderedLinkedList.h"
// i had to exclude this so i could convert the binary tree to a list in binarySearchTree

using namespace std;
  
int main()
{
	bSearchTreeType<int>  treeRoot;
	//create a tree type
	orderedLinkedList<int> newList;
	//create a linked list
	
	int num;
	//declare num

	cout << "Enter numbers ending with -999" << endl;
	cin >> num;
	//accept an entry for num

	while (num != -999)
	{//untill -999 is entered
		treeRoot.insert(num);
		//insert the num
		cin >> num;
		//accept next input
	}

	cout << endl << "Tree nodes in inorder: ";
	treeRoot.inorderTraversal();
	//print the nodes inorder
	cout << endl;
	cout << "Tree Height: " << treeRoot.treeHeight()
		 << endl;
	//output the height
	treeRoot.createList(newList);
	//convert the binary tree to an ordered linked list

	cout << "newList: ";
	newList.print();
	//print the list
	
	cout << endl;
	system("pause");

	return 0;
	//system exit
}
