//													Alec McDaugale
//this functions define the day from sunday through saturday and allows you 
//to add and subtract from the days of the week



#include <iostream>
#include <string>
#include "dayType.h"
#include "dateType.h"

using namespace std;

//sets day name corrosponding to a number
void dayType::setDay(int day)
{
	dayNum = day;

	//if the day is greater than 7 subtracts 7 untill at the begining of the week
	while (day > 7)
	{
		day = day - 7;
	}
	//switch to convert the numeric value into a string, beggining with sunday
	switch (day)
	{
	case 1:
		Day = "Sunday";
		break;
	case 2:
		Day = "Monday";
		break;
	case 3:
		Day = "Tuesday";
		break;
	case 4:
		Day = "Wensday";
		break;
	case 5:
		Day = "Thursday";
		break;
	case 6:
		Day = "Friday";
		break;
	case 7:
		Day = "Saturday";
		break;
	};
}
//sets day based on string, reverse of the previous function
//im attempting to overload this
void dayType::setDay(string day)
{
	Day = day;
	if (day == "Sunday")
		dayNum = 1;
	else if (day == "Monday")
		dayNum = 2;
	else if (day == "Tuesday")
		dayNum = 3;
	else if (day == "Wensday")
		dayNum = 4;
	else if (day == "Thursday")
		dayNum = 5;
	else if (day == "Friday")
		dayNum = 6;
	else if (day == "Saturday")
		dayNum = 7;

}
//adds a day
int dayType::nextDay()
{
	return addDay(1);
}
//adds a negative number to the day to work in inverse of the previous function
int dayType::prevDay()
{
	return addDay(-1);
}
//adds days to the day to convert to a string, if more than 7 subtracts 7 untill the day is within the valid range
int dayType::addDay(int num)
{
	int day;
	day = num + dayNum;

	while (day > 7)
	{
		day = day - 7;
	}
	switch (day)
	{
	case 1:
		Day = "Sunday";
		break;
	case 2:
		Day = "Monday";
		break;
	case 3:
		Day = "Tuesday";
		break;
	case 4:
		Day = "Wensday";
		break;
	case 5:
		Day = "Thursday";
		break;
	case 6:
		Day = "Friday";
		break;
	case 7:
		Day = "Saturday";
		break;

		return day;
	};
}
//prints the day
void dayType::print()
{
	cout << Day;
}
//default constructor to set the day
dayType::dayType(int day)
{
	setDay(day);
}
//overloaded constructor  to accept string value
dayType::dayType(string day)
{
	setDay(day);
}

