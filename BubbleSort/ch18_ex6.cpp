//																			Alec McDaugale
//This is the main method to test the class bubbleSortClass


#include"bubbleSortClass.h"

int main()
{
	//specify the size of the array here
	const int size = 8;
	//create the array based on the problem in the book
	int Input[size] = { 38, 60, 43, 5, 70, 58, 15, 10 };
	//create the test object
	bubbleSortClass<int> test(Input, size);

	 
	//counter
	int index;
	//fill the array based on its size
	for (index = 0; index < size; index++)
	{
		//add the elements to the array
		test.addToBack(Input[index], index);
	}

	
	//test.print();
	//call the bubble sort function for test
	test.bubbleSort();

	system("pause");
	return 0;
}
