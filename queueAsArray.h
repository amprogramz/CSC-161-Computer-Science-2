#ifndef H_queueAsArray
#define H_queueAsArray



#include <iostream>
#include <string>
#include "queueADT.h"

template<class Type>
class queueAsArray: public queueADT<Type>
{
public:
	void resetQueue(int Max);
	//initialize the queue
	void addToBack(const Type& info);
	//add to the queue
	void moveToFront();
	//move item to the front
	void printQueue();
	//print
	queueAsArray(int Max);
	//constructor
	queueAsArray();
	
private:
	int *queue, first, last;
	//variable to hold a dynamic queue, and first and last values
	bool full;
	//boolean value to hold if its full
	bool empty;
	//boolean value to hold if its empty
	int front;
	//front index
	int back;
	//back index
	int count;
	//value of count
	int max;
	//value to hold max queue size
	
};
#endif


template<class Type>
void queueAsArray<Type>::resetQueue(int Max)
{//initializes queue
	max = Max;
	//max equals the value input
	queue = new int[max];
	//initialise the queue array
	queue[0] = NULL;
	//initialize the first value to null
	first = queue[0];
	//first is equal to ques first value
	last = queue[0];
	//last is also initialized to 1
	front = 0;
	//front is initialisrd to 0
	back = 0;
	//so is back
	
}

template<class Type>
void queueAsArray<Type> ::addToBack(const Type& info)
{
	
	if (!isFull(count, max))//if list is not full
	{
		if (front != back)//if front is not equal to back, or not empty
		{
			if (back == max - 1)//if back value is maxed out/*+
			{
				back = 0;
				//reset back to 0
				queue[back] = info;
				//the queue value equals the info
				last = queue[back];
				//the last value is set to eaual this value
				count++;
				//add one to count
			}
			else//otherwise
			{
				
				queue[back] = info;
				//the back value is equal to the info
				last = queue[back];
				//last is reassigned
				back++;
				//add one to back
				count++;
				//add one to count
			}
		}
		else//otherwise if queue is empty
		{
			queue[back] = info;
			//back is equal to info

			last = queue[back];
			//last is equal to this value
			first = queue[back];
			//first is also equal to this value since the queue is empty
			back++;
			//add one to back
			count++;
			//add one to count
		}
	}
	else// otherwise the queue is full
	{
		cout << "Queue is full" << endl;
	}
}

//print
template<class Type>
void queueAsArray<Type>::printQueue()//print the queue data
{
	int index = front;
	//index is used to store the value of front so that front is not changed
	for (index = front; index < back - 1; index++)//from front to the back
	{
		cout << queue[index] << " ";
		//output the value of queue
	}
	cout << endl;
	//make a space
}

template<class Type>
void queueAsArray<Type> :: moveToFront()//move a value to the front
{
	int num;
	//int to store the num being moved
	int index;
	//int to hold the place
	cout << "please enter the position of the element to be moved to the front." << endl;
	cin >> index;
	//enter the element to be moved
	cout << endl;

	if (index < 0 || index > max - 1)//if invalid value is entered user will be prompted to re-enter
	{
		do//reprompt user while input value is no correct
		{
			cout << "The position of the element is out of range. \n Please ener a value between " << front << "and "
				<< back - 1 << endl;
			//clearly depict the problem based on the instance, makes this function user friendly
			cin >> index;
			cout << endl;
		} while (index < 0 || index > max - 1);

	}
	

		index += front - 1;
		//add the value of index to the front and subtract one from the front to accuratley translate the position
		num = queue[index];
		//the value being moved is stored into num
		while (index >= front)//while the index is not the front
		{
			if (index > front)//while it is larger 
			{
				queue[index] = queue[index - 1];
				//the index of the curren index is now equal to the value of the one before it,
				//moving the elements to fill in the empty space
				index--;
				//subtract one from index
			}
			else if (index == front)//if it is the first element
			{
				queue[index] = num;
				//store the value of num here
				index--;
				//subtract one more to exit
			}
		
	}
	//save value in a var and move elements by adding 1 so the int is in front


}
template<class Type>
queueAsArray<Type> ::queueAsArray(int Max)//cunstructor
{
	do//do while info entered is invalid
	{
		if (Max > 0)//if it is valid positive value, initialise the array
		{
			resetQueue(Max);
			//initialise the array
		}
		else//if invalid reprompt user untill it is valid
		{
			cout << "Invalid Max, Max must be a positive value and above 0. \n Please ener a valid value for max."
				<< endl;
			cin >> Max;
			cout << endl;
		}
	}while(max < 0);
}
template<class Type>
queueAsArray<Type> ::queueAsArray()//constructor with no paramaters, prompts user to enter data and checks if it is valid
{
	int Max;
	cout << "Please enter the size of the array." << endl;
	cin >> Max;
	cout << endl;
	do
	{
		if (Max > 0)
		{
			resetQueue(int Max)
		}
		else
		{
			cout << "Invalid Max, Max must be a positive value and above 0. \n Please ener a valid value for max."
				<< endl;
			cin >> Max;
			cout << endl;
		}
	} while (max < 0);
}