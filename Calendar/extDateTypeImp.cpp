//													Alec McDaugale
//these functions are intended to expand the base class



#include <iostream>
#include <string>
#include "extDateType.h"
#include "dateType.h"

using namespace std;

//function to set the date
//also included the dayspassed/left function to set this value
void extDateType::setDate(int mm, int dd, int yyyy)
{
	dateType::setDate(mm, dd, yyyy);
	daysPassedLeft();
}
//function to get the days left and passed
void extDateType::daysPassedLeft()
{
	int month;
	int day;

	month = dateType::getMonth();
	day = dateType::getDay();

	//this switch calculates the days left based on the month, 30 or 31 days
	//and the day of the month
	switch (month)
	{
	case 1:
		dPassed = day;
		lMonth = "January";
		break;
	case 2:
		dPassed = 31 + day;
		lMonth = "February";
		break;
	case 3:
		dPassed = 61 + day;
		lMonth = "March";
		break;
	case 4:
		dPassed = ((31 * 2) + 30) + day;
		lMonth = "April";
		break;
	case 5:
		dPassed = ((31 * 2) + (30 * 2)) + day;
		lMonth = "May";
		break;
	case 6:
		dPassed = ((31 * 3) + (30 * 2)) + day;
		lMonth = "June";
		break;
	case 7:
		dPassed = ((31 * 3) + (30 * 3)) + day;
		lMonth = "July";
		break;
	case 8:
		dPassed = ((31 * 4) + (30 * 3)) + day;
		lMonth = "August";
		break;
	case 9:
		dPassed = ((31 * 4) + (30 * 4)) + day;
		lMonth = "September";
		break;
	case 10:
		dPassed = ((31 * 5) + (30 * 4)) + day;
		lMonth = "October";
		break;
	case 11:
		dPassed = ((31 * 5) + (30 * 5)) + day;
		lMonth = "November";
		break;
	case 12:
		dPassed = ((31 * 6) + (30 * 5)) + day;
		lMonth = "December";
		break;
	};
	dLeft = dPassed - 365;

}
//calculates days passed out of 365
//void extDateType::daysLeft();
//days left
//returns days passed
int extDateType::numberOfDaysPassed() const
{
	return dPassed;
}
//returns days left
int extDateType::numberOfDaysLeft() const
{
	return dLeft;
}
//prints with standard format
void extDateType::print() const
{
	dateType::printDate();
}
//prints date with the exteded format, including the month name String
void extDateType::printLongDate()
{
	cout << lMonth << dateType::getDay() << ", " << dateType::getYear();
}
//incriments the date
void extDateType::incrementDate(int num)
{
	int month;
	int day;
	int year;

	day = dateType::getDay();
	day = day + num;
	dateType::setDate(month, day, year);

}
//constructor
extDateType::extDateType(int mm = 1, int dd = 1, int yyyy = 2014)
{
	setDate(mm, dd, yyyy); 
}
