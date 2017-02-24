/*#include "unorderedLinkedList.h"

template <class Type>
void unorderedLinkedList::insertLast(const Type& item)
{
	nodeType<Type> *node;
	node = new node<Type>;
	node->info = item;
	node->link = NULL;

	if (first != NULL)
	{
		last->link = node;
		last = node;
	}
	else
	{
		first = node;
		last = node;
	}
	index++;
}

template <class Type>
void unorderedLinkedList::divideMid(linkedList<Type> &sublist)
{
	sublist = sublist;
}
*/
