//													Alec McDaugale
//these functions define the base class




#include <iostream>
#include "dateType.h"

using namespace std;

//sets date
void dateType :: setDate(int mm, int dd, int yyyy)
{
	Month = mm;
	Day = dd;
	Year = yyyy;
}

//returns month
int dateType::getMonth() const
{
	return Month;
}
//returns day
int dateType::getDay() const
{
	return Day;
}
//returns the year
int dateType::getYear() const
{
	return Year;
}
//prints date
void dateType::printDate() const
{
	cout << Month << "-" << Day << "-" << Year;
}
//constructor
dateType::dateType(int mm, int dd, int yyyy)
{
	Month = mm;
	Day = dd;
	Year = yyyy;

}