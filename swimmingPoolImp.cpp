//															Alec McDaugale
//swimming pool definitions
//defines the swimming pool header declarations

//input and output
#include <iostream>
//math
//#include <cmath>
//class name
#include "swimmingPool.h"

//using the std namespace
using namespace std;

//sets the pool with in values
void swimmingPool::setPool(int len, int wid, int dep)
{
	length = len;
	width = wid;
	depth = dep;
	
}
//allows user to enter dimensions
void swimmingPool::setDimensions()
{
	int len;
	int wid; 
	int dep;

	//input and output
	cout << "Please enter the length, width, and depth of the pool" << endl;
	cin >> len >> wid >> dep;
	
	//get watter in pool from the user
	cout << endl << "Please enter in gallons the ammount of watter already in the pool \n";
	cin >> watterInPool;
	cout << endl;;
	
	//once entered set the pool
	setPool(len, wid, dep);
}
//set the volume in sq ft and gallons
void swimmingPool::setVolume()
{
	//sq ft 
	volume = length * width * depth;
	//gallons
	//there are 7.8 gallons in 1 sq ft
	volInGallons = volume * 7.8;
	//return volume;
}
//sets the rate of fill 
void swimmingPool::setRate()
{
	//prompts user for the rate p/min
	double rate;
	cout << "Please enter the gallons per minute that the pool fills." << endl;
	cin >> fillRate;
	cout << endl;

	//if theres watter then subtract that from the volume, otherwise divide the volume
	//by the fill rate to get the total minutes
	if (watterInPool == 0 && watterInPool >= 0)
		rate = volInGallons / fillRate;
	else if (watterInPool > 0)
		rate = (volInGallons - watterInPool ) / fillRate;
	
	//if more than 60 minutes then  get convert to hours and minutes, else display minutes
	if (rate > 60)
	{
		fillTimeH = (rate / 60);
		fillTimeM = rate - (fillTimeH * 60);
	}
	else
	{
		fillTimeH = 0;
		fillTimeM = rate;
	}

}
//print the pool data
void swimmingPool::printPool()
{
	cout <<"Pool Data: \n\n \tLength: " << length << " feet" << endl
		<< "\tWidth: " << width << " feet" << endl
		<< "\tDepth: " << depth << " feet" << endl << endl
		<< "\tVolume: " << volume << " sq. feet" << endl
		<< "\tVolume in Gallons: " << volInGallons << " gallons \n" <<endl
		<< "Time To Fill The Pool: \n\n \tTotal watter already in the pool: " << watterInPool << " gallons \n"
		<< "\tFill Rate: " << fillRate << " gallons per minute" << endl
		<< "\tTime to fill is approximantly " << static_cast<int>(fillTimeH) << " hours and " << static_cast<int>(fillTimeM)
		<< " minutes." << endl;
		
}
/*int swimmingPool::getRate()
{
	return fillRate;
}*/ //dont need this in this program
//constructor that initializes and allows the user to set the pool diensions
swimmingPool::swimmingPool(int len, int wid, int dep)
{
	setPool(len, wid, dep);
	setDimensions();
}
//default constructor, initalizes values to 0 only
swimmingPool::swimmingPool()
{
	length = 0;
	width = 0;
	depth = 0;
	
}

/*
int length;
int width;
int depth;

int fillRate;
*/