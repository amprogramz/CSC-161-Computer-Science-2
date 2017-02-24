//														Alec Mcdaugale
//This is the main method provided wich includes the user defined functions to input the 
//12 hour time to convert to a 24hour format

#include <iostream>
#include <string>
//include the classes for error messages i created
#include "invalidHr.h"
#include "invalidMin.h"
#include "invalidSec.h"

using namespace std; 

//define the functions to get hours, minutes, and secconds and to print the 24 hour time
int getHours();
int getMinutes();
int getSeconds();
void print24HourTime(int hr, int min, int sec, string str);

//main method
int main ()
{
	//declare three variables of type int to hold the values of hour minute and seconds
    int hours;
    int minutes;
    int seconds;

	//create a string variable to hold the value of str
    string str;

	//get the values of hours minutes and secconds with the get functions
    hours = getHours();
    minutes = getMinutes();
    seconds = getSeconds();

	//accept the input of either AM or PM but these must be caps, i would change this
	//to accept both upper and lower case forms
    cout << "Enter AM or PM: ";
    cin >> str;
    cout << endl;

	//output the 24hour time with the values hours, minutes, seconds and str as the 
	//paramaters for the print function
    cout << "24 hour clock time: ";
    print24HourTime(hours, minutes, seconds, str);
 
	//pause the  consold
    system("pause");
    return 0;      //exit system                                   
}

//the function to return the hour as type int
int getHours()
{
	//the boolean done is initialised to false
    bool done = false;     
	//hr is intialised to 0
    int hr = 0;

	//do while done is not equal to true
    do                                                
    {                                                 
        //try to accept the user input for hr
		//must be between 0 and 12
		try                                           
        {       
			//accept the user input for hour
            cout << "Enter hours: ";     
            cin >> hr;                           
            cout << endl;    
			
			//if hour is less than 0 or greater than 12
            if (hr < 0 || hr > 12)
				//throw the invalid hr function with default paramater 
                throw invalidHr();

			//else done is equal to true
            done = true;       
        }    
		//invalid hr catch with invalidHr object
        catch (invalidHr hrObj)
        {
			//outpur the returned value from what
            cout << hrObj.what() << endl;
        }
                                            
    } 
    while (!done);       
	
	//once the loop has been exited we can return the value of hr to main
    return hr;
}

//function to get the minutes
int getMinutes()
{
	//initialize done to false to loop
    bool done = false; 
	//initialize minute to 0 
    int min = 0;

	//do while not done
    do                                                
    {     
		//try to accept the users input
        try                                           
        {     
			//prompt user to enter the value of minutes
			//must be between 0 and 59
            cout << "Enter minutes: ";     
            cin >> min;                           
            cout << endl;    
			
			//if minutes are less than 0 or greater than 59
            if (min < 0 || min > 59)
				//throw the invalidMin() function with blank paramater
                throw invalidMin();

			//if not thrown this will make done equal true and exit the loop
            done = true;       
        }  
		//catch wich creates a minute object in its paramater
        catch (invalidMin minObj)
        {
			// output what is returned for the error message
            cout << minObj.what() << endl;
        }
                                            
    } //sentinal controled do while loop, while not done
    while (!done);       

	//once loop is exited return the minute to main
    return min;
}

//the function getSecconds wich returns the int value of secconds
int getSeconds()
{
	//initialize done to false so loop repeates if value is not valid
    bool done = false; 
	//initialize the value of seccond to 0
    int sec = 0;

	//do while not done
    do                                                
    {    
		//try this code
        try                                           
        {     
			//prompt user to enter the value of secconds
            cout << "Enter seconds: ";     
            cin >> sec;                           
            cout << endl;    

			//if the value of seccond is less than 0 or greater than 59
            if (sec < 0 || sec > 59)
				//throw the invalidSec()
                throw invalidSec();
			
			//otherwise done will be true
            done = true;       
        } 
		//catch the invalid second error thrown and create an invalid seccond object
        catch (invalidSec secObj)
        {
			//output the string returned by the object
            cout << secObj.what() << endl;
        }
                                            
    } //while not done
    while (!done);       

	//when loop exits return the value of seccond
    return sec;
}

//function to print the time in a 24 hour format with the parameters of hour minute second and am pm string
void print24HourTime(int hr, int min, int sec, string str)
{
	//if the string is equal to AM
    if (str == "AM")
    {
		//and if the hour is equal to 12 output 0
        if (hr == 12)
            cout << 0;
		//else the morning hour is simply output
        else 
            cout << hr;

		//output the minute and seccond next
        cout << ":" << min << ":" << sec << endl;
    }
	//else if the string is equal to PM
    else if (str == "PM")
    {
		//if the hour is 12 output the hour
        if (hr == 12)
            cout << hr;
        else//else add 12 to the hour
            cout << hr + 12;
		//next output the minute and seccond respectively
        cout << ":" << min << ":" << sec << endl;
    }
}