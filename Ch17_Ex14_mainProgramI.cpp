#include "queueAsArray.h"

int main()
{
	
	//create testQue to be an object of queueAsArray
	queueAsArray<int> testQueue(100);
	int num;
	//num is a counter value to automate the input of the array values
	int testData[8] = { 45, 38, 22, 18, 42, 10, 27, 5 };
	//array to hold the test values to input


	//int num2 = 7;
	for(num = 0; num <= 8; num++)
	{
		testQueue.addToBack(testData[num]);
		//enter the test data to the back of the queue
	}
	
	testQueue.printQueue();
	//print the queue
	testQueue.moveToFront();
	//move the value you want to the front
	testQueue.printQueue();
	//print the resulting queue

	system("pause");
	//pause 
	return 0;
	//system exit
};