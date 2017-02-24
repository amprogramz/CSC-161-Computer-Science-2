//																		Alec McDaugale
//
//	This program was made too add elements to the binary search tree and too convert the tree to an ordered
//linked list

#ifndef H_binarySearchTree
#define H_binarySearchTree

#include "binaryTree.h"
#include "orderedLinkedList.h"


template<class type>
class bSearchTreeType : public binaryTreeType<type>
{
public:
	void insert(type num);
		//function to insert the nuber
	void createList(orderedLinkedList<type> &List);
		//function to convert the tree to a linked list
	void convert(bnode<type> *a, orderedLinkedList<type> &List);
		//recursive function to read the linked list inorder and input it into an ordered linked list
	bSearchTreeType();
		//default constructor, initializes the tree
};

#endif // !H_binarySearchTree


template<class type>
void bSearchTreeType<type>::insert(type num)
{
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
	n = new bnode < type > ;
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

template<class type>
void bSearchTreeType<type>::createList(orderedLinkedList<type> &List)
{

	convert(root, List);
	//convert the tree to a list
}

template<class type>
void bSearchTreeType<type>::convert(bnode<type> *a, orderedLinkedList<type> &List)
{
	if (a != NULL)
	{
		//if pointer a is not null 
		convert(a->l, List);
		//call back this function to move left
		List.insertLast(a->info);
		//insert the info
		convert(a->r, List);
		//recursively call to the right
	}
}
template<class type>
bSearchTreeType<type> ::bSearchTreeType()
{
	binaryTreeType();
	//initialize to the binary tree initialization, same
}

