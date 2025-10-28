#include "Date.h"
#include<iostream>
using namespace std;

bool Date::validateDate()
{
	if (day < 1 || month < 1 || month>12 || year < 1)
	{
		return false;
	}
	else if (month == 2)
	{
		if (isLeapYear())
		{
			day = 29;
		}
		else
		{
			day = 28;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		day = 30;
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		day = 31;
	}
	else
	{
		cout << "Please enter a valid date. " << endl;
	}

	return true;
}
Date::Date()
{
	month = 1;
	day = 1;
	year = 1000;
}
Date::Date(int d, int m, int y)
{
	this->day = d;
	this->month = m;
	this->year = y;
	if (!validateDate())   //use default values if user enters an invalid date
	{
		month = 1;
		day = 1;
		year = 1000;
	}
}
Date::Date(const Date& other)
{
	day = other.day;
	month = other.month;
	year = other.year;
}
bool Date::inputDate()
{
	cout << "Enter day: ";
	cin >> day;
	cout << "Enter month: ";
	cin >> month;
	cout << "Enter year: ";
	cin >> year;

	if (validateDate())
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Date::inputCompleteDate(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;

	if (validateDate())
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Date::copyDate(const Date& other)
{
	day = other.day;
	month = other.month;
	year = other.year;

	return true;
}
void Date::retrieveDate(int& d, int& m, int& y)   //copying data from private attributes to the external variables d, m, y
{
	d = day;
	m = month;
	y = year;
}

void Date::showDate()
{
	cout << "----------------" << endl;
	cout << "Day: " << getDay() << endl;
	cout << "Month: " << getMonth() << endl;
	cout << "Year: " << getYear() << endl;
	cout << "Formatted date: " << getDay() << "-" << getMonth() << "-" << getYear() << endl;
}
bool Date::isEqual(const Date& other)
{
	if (day == other.day && month == other.month && year == other.year)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Date::isLeapYear()
{
	if (year % 4 != 0)
	{
		cout << "Not a leap year." << endl;
		return false;
	}
	else if (year % 100 != 0)
	{
		cout << "Not a leap year." << endl;
		return false;
	}
	else if (year % 400 != 0)
	{
		cout << "Not a leap year." << endl;
		return false;
	}
	else
	{
		cout << "A leap year!" << endl;
		return true;
	}
}
void Date::setDay(int d)
{
	day = d;

	if (!validateDate())
	{
		day = 1;
	}
}
int Date:: getDay()
{
	return day;
}
void Date::setMonth(int m)
{
	month = m;

	if (!validateDate())
	{
		month = 1;
	}
}
int Date::getMonth()
{
	return month;
}
void Date::setYear(int y)
{
	year = y;

	if (!validateDate())
	{
		year = 1000;
	}
}
int Date::getYear()
{
	return year;
}
void Date::incrementDay()
{
	day++;
	if (!validateDate())
	{
		day = 1;
		month++;
		if (!validateDate())
		{
			month = 1;
			year++;
		}
	}
}
void Date::decrementDay()
{
	day--;
	if (day < 1)
	{
		month--;
		if (month < 1)
		{
			month = 12;
			year--;
		}

		if (month == 2)
		{
			if (isLeapYear())
			{
				day = 29;
			}
			else
			{
				day = 28;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			day = 30;
		}
		else
		{
			day = 31;
		}
	}
}