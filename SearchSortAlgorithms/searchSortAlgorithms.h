//																		Alec McDaugale
//
// This program contains the sorting functions for bubble sort, selection sort, and insertion sort.
//It also counts the number of comparisons and the number of assignments to return to main.

#ifndef H_searchSortAlgorithms
#define H_searchSortAlgorithms

#include<iostream>
#include<string>

using namespace std;


template <class type>
class searchSortAlgorithms
{
public:
	void move(type list[], int dex1, int dex2);
	//function to move items in the list. dex1 gets replaced with dex2.
	void print();
	//function to print the array
	int getComparisons();
	//function to retrive the number of comparisons
	int getAssignments();
	//function to return the number of assignments


	void bubbleSort();
	//bubble sort function

	void selectionSort();
	//selection sort function
	int findSmallest(type list[], int currentDex);
	//returns the smallest int

	void insertionSort();
	//insertion sort  function
	int findPosition(type list[], int max, int num);
	//returns the position where the elm belongs 
	searchSortAlgorithms(type list[], int lengthVar);
	//constructor
private:
	//counter to store the number of comparisons
	int comparison_counter;
	//counter to store the number of item assignments
	int item_assignment_counter;
	//int to store the length
	int length;
	//pointer to store the array
	type *p;
};
#endif

//move
template <class type>
void searchSortAlgorithms<type>::move(type list[], int dex1, int dex2)
{
	//var to store the var being moved
	type temp;

	//temp is equal to the first item
	temp = list[dex1];
	//the seccond item is moved to the first location
	list[dex1] = list[dex2];
	//the first item stored in temp is moved to the seccond location
	list[dex2] = temp;

	//items assigned 3 times
	item_assignment_counter += 3;
}

//prints array
template <class type>
void searchSortAlgorithms<type>::print()
{
	//int to store the location
	int index;
	
	//through all locations
	for (index = 0; index < length; index++)
	{
		//output item
		cout << p[index] << " ";
	}
	//add a space for neat appearance
	cout << endl;
}

//get comparisons
template <class type>
int searchSortAlgorithms<type>::getComparisons()
{
	//returns the counter
	return comparison_counter;
}

//get the number of assignments
template <class type>
int searchSortAlgorithms<type>::getAssignments()
{
	//returns the counter
	return item_assignment_counter;
}

//function to use the bubble sort algorithm
template <class type>
void searchSortAlgorithms<type>::bubbleSort()
{
	//int to store the count or iterations
	int count;
	//int to store the item being compared
	int item;

	//for the iterations less than length
	for (count = 1; count < length; count++)
	{
		//count comparison
		comparison_counter++;

		//for the unsorted items in the list
		for (item = 0; item < length - count; item++)
		{
			//count comparison
			comparison_counter++;

			//if item 1 is greater than the next item
			if (p[item] > p[item + 1])
			{
				//count comparison
				comparison_counter++;

				//swap the items with eachother
				move(p, item, item + 1);

			}
		}
	}
}

//function to return the smallest index
template <class type>
int searchSortAlgorithms<type>::findSmallest(type list[], int currentDex)
{
	int index;
	//initialise the smallest element to the curren index
	int smallest = currentDex;

	//for the curent spot to the end
	for (index = currentDex; index < length; index++)
	{
		//count comparison
		comparison_counter++;

		//if this item is smaller than the smallest
		if (p[index] < p[smallest])
		{
			//count comparison
			comparison_counter++;

			//replace with this item
			smallest = index;
		}
	}
	//return the smallest element
	return smallest;
}


//selection sort algorithm
template <class type>
void searchSortAlgorithms<type>::selectionSort()
{
	//the curent iteration
	int curentDex;
	//the smallest number
	int smallest;

	//for each iteration
	for (curentDex = 0; curentDex < length; curentDex++)
	{
		//count comparison
		comparison_counter++;
		
		//find the smallest element
		smallest = findSmallest(p, curentDex);
		//move it to the front
		move(p, curentDex, smallest);
	}
}

//insert sort algorithm
template <class type>
void searchSortAlgorithms<type>::insertionSort()
{
	//iteration
	int index;
	//item
	int dex;
	//int to store the position that the item is moved to
	int pos;

	//for the first to last iteration
	for (index = 1; index < length; index++)
	{
		//count comparison
		comparison_counter++;

		//if the first element is less than the last element
		if (p[index] < p[index - 1])
		{
			//count comparison
			comparison_counter++;

			//store this item in temp
			type temp;
			temp = p[index];
			//item assigned
			item_assignment_counter++;

			//find where it belongs
			pos = findPosition(p, index - 1 , index);
			
			//move the elements all up one space while dex is greater than the desired position to move the element
			for (dex = index; dex >= pos; dex--)
			{
				//count comparison
				comparison_counter++;

				//the current index is equal to the last index
				p[dex] = p[dex - 1];
				//items assigned
				item_assignment_counter++;
				
			}
			//put the item being moved in its proper location
			p[pos] = temp;
			//items assigned
			item_assignment_counter++;
			
		}

	}
}

template <class type>
int searchSortAlgorithms<type>::findPosition(type list[], int max, int num)
{
	int min;
	int position = 0;
	for (min = 1; min < max; min++)
	{
		//count comparison
		comparison_counter++;

		//if the number is less than the first element
		if (list[num] < list[0])
		{
			//count comparison
			comparison_counter++;

			//move it here
			position = 0;
			//return the position
			return position;
		}
		//else if its between two elements
		else if (list[num] <= list[min] && list[num] >= list[min - 1])
		{

			//count 2 comparisons
			comparison_counter += 2;

			//return the number it is lower than
			position = min;
			return position;
		}
	}
	
	//i tried to do a more efficent search but it has problems

	/*int mid;
	bool found = false;
	min = 0;
	while (!found)
	{
		if ((min + max) % 2 == 0)
		{
			mid = (min + max) / 2;
		}
		else
		{
			mid = (min + max + 1) / 2;
		}

		if (list[num] <= list[mid] && list[num] >= list[mid - 1])
		{
			
			found = true;
			
		}
		else if (list[num] > list[mid])
		{
			max = mid - 1;
		}
		else
		{
			
			min = mid + 1;
		}
	}
	cout << mid << endl;
	return position;*/
	
}

//default constructor
template <class type>
searchSortAlgorithms<type>::searchSortAlgorithms(type list[], int lengthVar)
{
	//counter for initialization
	int index;
	//assign pointer p to create a dynamic array
	p = new int[lengthVar];
	//set length of array
	length = lengthVar;
	//initialize counter
	comparison_counter = 0;
	//initialize assignment counter
	item_assignment_counter = 0;

	//set the random array list
	for (index = 0; index < length; index++)
	{
		p[index] = list[index];
	}
	
}
