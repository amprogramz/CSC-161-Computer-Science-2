//															Alec McDaugale
//main method
//combines functions to make the program


#include <iostream>
//includes the swimming pool class
#include "swimmingPool.h"

using namespace std;

//main5
int main()
{
	int done = 1;
	/*int length;
	int width; 
	int depth;*/
	
	//swimmingPool pool();
	//pool.setDimensions();

	//while not done
	while (done != 0)
	{
		//iniialize pool1 to 000, but i made it so that the user can input the dimensions
		swimmingPool pool1(0, 0, 0);
		//calculates the volume in both sq ft and gallons
		pool1.setVolume();
		//sets the rate of fill
		pool1.setRate();
		//pool1.getRate();

		//prints pool data
		pool1.printPool();
		
		//continue?
		cout << endl << "Enter 0 to quit or 1 to continue . . . " << endl;
		//stores user response
		cin >> done;

		
	}//end while

	//system exit
	return 0;
}//end main