//																		Alec McDaugale
//
//	This program is the base class to create a binary tree.

#ifndef H_binaryTree
#define H_binaryTree

#include <iostream>
#include <cmath>

template<class type>
struct bnode
{//struct to hold the binary node object
	type info;
	//var to hold the info
	bnode<type> *l;
	//left link pointer
	bnode<type> *r;
	//right link pointer
};


template<class type>
class binaryTreeType
{
public:
	int returnLeaves();
		//function to return the leaf count

	void insert(type num);
		//insert function
	int treeHeight();
		//returns the tree height
	bool emptyTree();
		//returns if the tree is empty

	void inorderTraversal();
		//calls inorder 
	binaryTreeType();
		//default constructor


protected:
	bnode<type> *root;
	//root pointer

private:
	int leafCount;
	//variable to hold the leaf count
	void countLeaves(bnode<type> *a);
	//recursive function to find the leaf count


	int greater(int a, int b);
	//returns the greater element
	int findHeight(bnode<type> *a);
	//returns the height
	void inorder(bnode<type> *a);
	//returns the contents of the tree inorder


};

#endif // !H_binaryTree

//new defs
template<class type>
int binaryTreeType<type>::returnLeaves()
{//returns the leaf count
	leafCount = 0;
	//initialise the count to 0
	countLeaves(root);
	//calculate with a pointer paramater, the root pointer
	return leafCount;
	//return the count to the other program
}
template<class type>
void binaryTreeType<type>::countLeaves(bnode<type> *a)
{//function to count the leaves in a binary tree
	
	if (a != NULL)
	{//as long as a is not null
		countLeaves(a->l);
		//call this function to transverse the left side
		if (a->l == NULL && a->r == NULL)
		{//since this function will not exicute is a is null, when the links of the pointer are null
		 //the leaves are counted since a leaf is at the tip of the tree.
			leafCount++;
		}
		
		countLeaves(a->r);
		//transversal to the right
		
	}
}

template<class type>
void binaryTreeType<type>::insert(type num)
{// inserts the data in order
	//inserts a num to the tree
	bnode<type> *currentNode;
	//the current node
	bnode<type> *tailCurrent;
	//the previous node
	bnode<type> *n;
	//pointer n to hold the node
	bool duplicate = false;
	//create a boolean variable to detect duplicates

	//initialize the node, and set the information to hold num
	n = new bnode < type >;
	n->info = num;
	n->l = NULL;
	n->r = NULL;

	if (emptyTree())
	{
		root = n;
		//if the tree is empty insert the data in the first position or the root
	}
	else
	{
		currentNode = root;
		//otherwise the current node is initialized to the root
		while (currentNode != NULL && !duplicate)
		{
			tailCurrent = currentNode;
			//set the tail before progressing the current node foreward
			if (currentNode->info < num)
			{
				currentNode = currentNode->r;
				//if the info is less than the number progress to the right side of the tree
			}
			else if (currentNode->info > num)
			{
				currentNode = currentNode->l;
				//else if its bigger go to the left
			}
			else
			{
				duplicate = true;
				//otherwise it is a duplicate
				cout << "cannot enter duplicates! " << num << endl;
				//output the error
			}
		}
		if (!duplicate)
		{//if its not a duplicate
			if (tailCurrent->info < num)
			{//if the last number is less than num
				tailCurrent->r = n;
				//put the data to the right
			}
			else
			{//otherwise its greater
				tailCurrent->l = n;
				//otherwise put it to the left
			}
		}
	}

}



//definitions

template<class type>
int binaryTreeType<type>::treeHeight()
{
	return findHeight(root);
	//retutn the results from the private function
}

template<class type>
bool binaryTreeType<type>::emptyTree()
{
	return(root == NULL);
	//returns true if the list is equal to null
}

template<class type>
void binaryTreeType<type>::inorderTraversal()
{
	inorder(root);
	//prints the variables inorder starting at the root
}

template<class type>
int binaryTreeType<type>::greater(int a, int b)
{
	if (a > b)
	{
		return a;
		//if a is larger then return it
	}
	else
	{
		return b;
		//otherwise return b
	}
}

template<class type>
int binaryTreeType<type>::findHeight(bnode<type> *a)
{
	//need to count the height
	if (a == NULL)
	{
		return 0;
		// if the root is null then the height is 0
	}
	else
	{
		return 1 + greater(findHeight(a->r), findHeight(a->l));
		//otherwise the height is the longer distance of the two sides
	}

}


template<class type>
void binaryTreeType<type>::inorder(bnode<type> *a)
{
	//prints data inorder untill the end has been reached
	if (a != NULL)
	{//if its not null
		inorder(a->l);
		//recursivly move down the right
		cout << a->info << " ";
		//print the info
		inorder(a->r);
		//recursively move through the righ
	}
}



template<class type>
binaryTreeType<type>::binaryTreeType()
{
	root = NULL;
	//initialise the root to null

}
