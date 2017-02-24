#ifndef H_queueADT
#define H_queueADT

#include <iostream>
#include <string>

using namespace std;

template<class Type>
class queueADT
{
public:
	bool isEmpty(int *first);
	//Is queue empty?
	bool isFull(int count, int max);
	//Is it full?
	int returnFirst(const Type& info);
	//return first
	int returnLast(const Type& info);
	//return last

};
#endif

//Is queue empty
template<class Type>
bool queueADT<Type>::isEmpty(int *first)//is it empty
{
	if (first == NULL)
		//if first is null
		return true;
		//true
	else
		return false;
		//else false
}
//Is queue empty

template<class Type>
bool queueADT<Type>::isFull(int count, int max)//is it full
{
	if (count == max)
		//if the count is equal to max 
		return true;
		//its full
	else
		return false;
		//else no
}


template<class Type>
int queueADT<Type>:: returnFirst(const Type& info)
{
	return first;
	//return first
}
//return first
template<class Type>
int queueADT<Type>:: returnLast(const Type& info)
{
	return last;
	//return last
}
