//																		Alec McDaugale
//
//	This program is a class to hold the ordered linked list methods. I created one to add an element to the 
//back of the list from the binary tree since the data has already been organized.


#ifndef H_orderedLinkedList
#define H_orderedLinkedList

#include "linkedList.h"

template<class type>
class orderedLinkedList : public linkedListType<type>
{
public:
	
	void insertLast(type item);
	//inserts item to the end of the list
	orderedLinkedList();
	//default constructor


};

#endif // !H_orderedLinkedList

template<class type>
void orderedLinkedList<type>::insertLast(type item)
{
	//create a new node
	nodeType<type> *node;
	node = new nodeType<type>;
	node->info = item;
	//insert the info
	node->link = NULL;

	if (first != NULL)
	{//if he first is null
		//add it o he link of last 
		last->link = node;
		//move last to point to the end
		last = node;
	}
	else
	{
		//otherwise first and last are null
		first = node;
		last = node;
	}
	index++;
	//count the index
}


template<class type>
orderedLinkedList<type>::orderedLinkedList()
{
	setList();
	//set the list, iniialise it
}


