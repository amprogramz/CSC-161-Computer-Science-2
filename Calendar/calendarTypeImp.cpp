//													Alec McDaugale
//This is the calender class to print a calender




#include <iostream>
#include "calendarType.h"
#include "dateType.h"


using namespace std;
// method to set the calender with the date
void calendarType::setCalendar(int month, int year)
{
	int day = 1;
	dateType::setDate(month, day, year);
}
//function to print the calender
//not yet completed, //having problems compileing so i didnt have time to format this
void calendarType::printCalendar()
{
	cout << dateType::getMonth();
}
//constructor
calendarType::calendarType(int month = 1, int year = 2014)
{
	setCalendar(month, year);
}
