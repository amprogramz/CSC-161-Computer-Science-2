//Sukhanya Stacy
//CSC 161 - Professor Newby
//Program 10 - Chapter 19 - Program Exercise 2
//Due Date: December 4, 2014

#include <iostream>
#include "binarySearchTree.h"

using namespace std;

int main()
{
	bSearchTreeType<int> treeRoot;
	int num;

	cout << "Enter the elements ending with -999" << endl;
	cin >> num;

	while (num != -999)
	{
		treeRoot.insert(num);
		cin >> num;
	}

	cout << endl;
	cout << "The number of leaves in the binary tree: " << treeRoot.treeLeavesCount() << endl;

	system("pause");

	return 0;
}