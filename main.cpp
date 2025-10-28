#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
	cout << "Default constructor: " << endl;
	Date d1;
	d1.showDate();

	cout << "Parametrized constructor: " << endl;
	Date d2(23, 10, 2025);
	d2.showDate();

	cout << "Copy constrcutor: " << endl;
	Date d3 = d2;
	d3.showDate();

	cout << "Incremented date: " << endl;
	d2.incrementDay();
	d2.showDate();

	cout << "Decremented date: " << endl;
	d3.decrementDay();
	d3.showDate();

	cout << "Enter a new date: " << endl;
	if (d1.inputDate())
	{
		cout << "You entered: ";
		d1.showDate();
	}

	if (d2.isEqual(d3))
	{
		cout << "Both are equal." << endl;
	}
	else
	{
		cout << "Not equal." << endl;
	}

	return 0;
}