//																			Alec McDaugale
//This is the class bubbleSortClass, it outputs each iteration to show how it sorts information.



#ifndef H_bubbleSortClass
#define H_bubbleSortClass

#include<iostream>
#include<string>

using namespace std;

template <class type>
class bubbleSortClass
{
public:
	//function to add the elements of the array to the back of the list
	void addToBack(type elm, int dex);
	//function to exchange the locations of the list elements
	void moveInts(type arrayList[], int index1, int index2);
	//function to print the array
	void print();
	//function to sort the elements
	void bubbleSort();
	//constructor
	bubbleSortClass(type inpArray[], int max);

private:  
	//ptr to make the array dynamic
	type *arrayPtr;
	//int to store the length of the array
	int length;

};
#endif

//adds to the back of the list when inserted via a for loop
template <class type>
void bubbleSortClass<type>::addToBack(type elm, int dex)
{
	//add the element to the array for the index provided
	arrayPtr[dex] = elm;
}
//function to swap two elements
template <class type>
void bubbleSortClass<type>::moveInts(type arrayList[], int index1, int index2)
{
	//temp is a variable to temporarily store the variable that is being moved
	type temp;

	//temporary is equal to the first item in the array
	temp = arrayList[index1];
	//the seccond item in the array is moved to the first location
	arrayList[index1] = arrayList[index2];
	//the seccond item is equal to the first item stored in temporary 
	arrayList[index2] = temp;
}

//function to print the array
template <class type>
void bubbleSortClass<type>::print()
{
	//location stores the location of the element in the array to print
	int location;

	//for all locations starting at 0, 1st position
	for (location = 0; location < length; location++)
	{
		//output the element separated by spaces
		cout << arrayPtr[location] << " ";
	}
	//add a newline for a nice separation
	cout << endl;
}
template <class type>
void bubbleSortClass<type>::bubbleSort()
{
	//int to store the iterations
	int iterations;
	//int to store the location
	int location;

	//for the iterations less than length
	for (iterations = 1; iterations < length; iterations++)
	{
		cout << "Iteration " << iterations << ": ";
		//print each iteration
		print();
		//for the unsorted location in the list, pushing the highest element to the top
		for (location = 0; location < length - iterations; location++)
		{
			//if the first location is larger than the next
			if (arrayPtr[location] > arrayPtr[location + 1])
			{
				//exchange the elements
				moveInts(arrayPtr, location, location + 1);

			}
		}
	}
}
//constructor
template <class type>
bubbleSortClass<type>::bubbleSortClass(type inpArray[], int max)
{
	//index to hold the current location to input
	int index;
	//length of the array is the max
	length = max;
	//initialize the dynamic array with length
	arrayPtr = new int[length];
	
	//for all locations 
	for (index = 0; index > length; index++)
	{
		//coppy the input array
		arrayPtr[index] = inpArray[index];
	}
}
