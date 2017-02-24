//																		Alec McDaugale
//
// This program main tests the three sorting algoritms and presents the number of comparisons
//and the number of assignments at the end.

#include <cmath>
#include "searchSortAlgorithms.h"

using namespace std;

int main()
{
	// pointer to store random array
	int *p;
	//value to store index
	int index;
	//set max here
	int max = 5000;

	//create new array
	p = new int[max];

	//fill array with ints to be random numbers
	for (index = 0; index < max; index++)
	{
		//fill the array
		p[index] = rand() % max;
	}
	
	//create 3 test objects to sort the random array
	searchSortAlgorithms<int> test1(p, max);
	searchSortAlgorithms<int> test2(p, max);
	searchSortAlgorithms<int> test3(p, max);

	//outputs bubble array sort before and after
	cout << "Bubble Sort: \n before sort:" << endl;
	test1.print();
	cout << endl << " after sort: \n";
	test1.bubbleSort();
	test1.print();
	cout << endl << endl;

	//output selection sort before and after
	cout << "Selection Sort: \n before sort:" << endl;
	test2.print();
	cout << endl << " after sort: \n";
	test2.selectionSort();
	test2.print();
	cout << endl << endl;

	//output the insertion sort before and after
	cout << "Insertion Sort: \n before sort:" << endl;
	test3.print();
	cout << endl << " after sort: \n";
	test3.insertionSort();
	test3.print();
	cout << endl << endl;

	//output the number of comparisons and assignmens for all sorting methods on the data.
	cout << "Number of Comparisons--- \n Bubble Sort: " << test1.getComparisons() << endl
		<< " Selection Sort: " << test2.getComparisons() << endl
		<< " Insertion Sort: " << test3.getComparisons() << endl
		<< "Number of assignments--- \n Bubble Sort: " << test1.getAssignments() << endl
		<< " Selection Sort: " << test2.getAssignments() << endl
		<< " Insertion Sort: " << test3.getAssignments() << endl;

	//done
	system("pause");
	return 0;
}
