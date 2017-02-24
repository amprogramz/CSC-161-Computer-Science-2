#include "binaryTreeType.h"

using namespace std;

int main()
{
	int index;
	const int size1 = 1;
	const int size2 = 5;
	const int size3 = 7;

	int treeList1[size1] =  { 54, 32, 61 };
	int treeList2[size2] =  { 54, 32, 61, 62, 60};
	int treeList3[size3] =  { 54, 32, 61, 62, 60, 33, 30 };

	binaryTreeType<int> test1;
	binaryTreeType<int> test2;
	binaryTreeType<int> test3;
	
	for (index = 0; index < size1; index++)
	{
		test1.insert(treeList1[index]);
	}
	for (index = 0; index < size2; index++)
	{
		test2.insert(treeList2[index]);
	}
	for (index = 0; index < size3; index++)
	{
		test3.insert(treeList3[index]);
	}


	cout << "leaves in test 1: " << test1.returnLeaves() << endl;
	cout << "leaves in test 2: " << test2.returnLeaves() << endl;
	cout << "leaves in test 3: " << test3.returnLeaves() << endl;

	system("pause");
	return 0;
}