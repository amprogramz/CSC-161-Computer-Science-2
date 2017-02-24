//																		Alec McDaugale
//
//	This program is the standard functions to set and print a linked list

#ifndef H_linkedList
#define H_linkedList

#include <iostream>

using namespace std;

template<class type>
struct nodeType
{//the standard node type
	type info;
	//to hold the info
	nodeType<type> *link;
	//to create the link
};



template<class type>
class linkedListType
{
public:
	void setList();
	//initializes the list
	void print();
	//prints the list
	int length();
	//returns the length
	linkedListType();
	//default constructor
	~linkedListType();
	//destructor
protected:
	int index;
	//index
	nodeType<type> * first;
	//points to first
	nodeType<type> * last;
	//poins to last node

};

#endif



template <class type>
void linkedListType<type>::setList()
{
	//initialize the list to null 0
	first = NULL;
	last = NULL;
	index = 0;
}

template <class type>
void linkedListType<type>::print()
{
	nodeType<type> *counter;
	//pointer counter
	counter = first;
	//set to first element

	if (counter != NULL)
	{
		while (counter != NULL)
		{
			//while its not null print he info and move to the next link
			cout << counter->info << " ";
			counter = counter->link;
		};
	}
	else
	{
		//otherwise its an empty list so output the appropriate error message
		cout << "ERROR: No data has been entered into your list !!!";
	}
}

template <class type>
int linkedListType<type>::length()
{
	return index;
	//the index holds the length of the list
}

template <class type>
linkedListType<type>::linkedListType()
{
	setList();
	//initialize the list
}

template <class type>
linkedListType<type>::~linkedListType()
{

}


