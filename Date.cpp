#include "Date.h"

Date::Date()   // When called, it creates an object of this class and
	{                 // initializes the data members of the object with zero.
    month = 0;
    day = 0;
    year = 0;
	}
Date::Date(int m, int d, int y)   //When called, it creates an object of this class
	{                             // and initializes components with the received values.
    month = m;
    day = d;
    year = y;
	}
int Date::getMonth()  //to extract month component of a Date object
	{
    return month;
	}
int Date::getDay()  //to extract day component of a Date object
	{
    return day;
	}
int Date::getYear()  //to extract year component of a Date object
	{
    return year;
	}
void Date::getDate()
	{
    cout << "Enter month, day then year: ";
    cin >> month >> day >> year;
	}
void Date::displayDate()      // When called, it displays the date
	{
    cout << month << "/" << day << "/" << year << endl;
	}
 void Date::readDate(ifstream &stream1)
    {
      stream1 >> month >> day >> year;
    }
void Date::copyDate(Date &d1)
	{
		month=d1.month;
		day=d1.day;
		year=d1.year;
	}
