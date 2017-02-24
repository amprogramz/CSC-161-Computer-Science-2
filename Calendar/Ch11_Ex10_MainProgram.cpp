//													Alec McDaugale
//this is the main method provided to test the classes



#include <iostream>

#include "dayType.h"
#include "dateType.h"
#include "extDateType.h"
#include "calendarType.h"
   
using namespace std; 
 
int main()
{
	//creates a date type, dosent output with this function, but i made
	//this my base function
    dateType d(1, 2, 1960);
	//the extended date type, has other functions like adding days to the date
    extDateType ed(6, 10, 1981);
	//int to hold the value of num
    int num;

	//prints the long date with the printLongDate function
    ed.printLongDate();
	//newline
    cout << endl;
	
	//prints with the standard format
    ed.print();
	//endline
    cout << endl;

	//days passed in the year function
    cout << "Days gone in the year: " << ed.numberOfDaysPassed();
    cout << endl;

	//days left function
    cout << "Days left in the Year: " << ed.numberOfDaysLeft() << endl;

	//add days function
    cout << "Enter number of days to be added: ";
	//enter value of num here
    cin >> num;
    cout << endl;
	//add the value of num to the date
    ed.incrementDate(num);

	//prints the new date after incrementing
    cout << "After increment date: ";
    //standard print of the date
	ed.print();
    cout << endl;

        //test day object
    dayType newDay("Wednesday");

	//prints the day with a string
    newDay.print();
    cout << endl;

	//increments the day by one
    cout << "Next Day: " << newDay.nextDay() << endl;

	//sets the day with a string
    newDay.setDay("Sunday");
    cout << "Set Day: ";
    //prints the new value of Day
	newDay.print();
    cout << endl;

	//function to go back a day
    newDay.prevDay();
    cout << "Previous Day: " << newDay.prevDay() << endl;

	//function to add days to the day
	//added logic to this so that it could translate 12 into a 7 day week
    newDay.addDay(12);
    cout << "Add days: ";
	//prints the day
    newDay.print();
    cout << endl;

        //test calendar object
    calendarType cal(9, 2015);

	//prints the calender function
    cal.printCalendar();
	//i like this, pauses the output so you can see it
	system("pause");
	//system exit
    return 0;
}
