#pragma once
class Date
{
private:
	bool validateDate();
	int day;
	int month;
	int year;
public:
	Date();  //Default C-tor
	Date(int d, int m, int y);           //Parametrized C-tor
	Date(const Date& other);           //Copy C-tor
	
	bool inputDate();
	bool inputCompleteDate(int d, int m, int y); 
	bool copyDate(const Date& other);
	void retrieveDate(int& d, int& m, int& y); 
	void showDate();
	bool isEqual(const Date& other);
	bool isLeapYear();

	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);

	int getDay();
	int getMonth();
	int getYear();

	void incrementDay();
	
	void decrementDay();
};

