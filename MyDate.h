#pragma once
#include <iostream>

using namespace std;

class MyDate
{
private:
	int day;
	int month;
	int year;
public:
	MyDate(int day, int month, int year)
	{
		(month > 0 && month <= 12) ? this->month = month : this->month = 1;
		if (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7
			|| this->month == 8 || this->month == 10 || this->month == 12)
		{
			(day > 0 && day <= 31) ? this->day = day : this->day = 1;
		}
		if (this->month==4||this->month==6||this->month==9||this->month==11)
		{
			(day > 0 && day <= 30) ? this->day = day : this->day = 1;
		}
		if (this->month == 2)
		{
			if ((year % 4) == 0)
			{
				(day > 0 && day <= 29) ? this->day = day : this->day = 1;
			}
			else
			{
				(day > 0 && day <= 28) ? this->day = day : this->day = 1;
			}
		}
		this->year = year;
	}

	MyDate() :MyDate(1, 1, 1970) {}

	void setDate(int day, int month, int year)
	{
		(month > 0 && month <= 12) ? this->month = month : this->month = 1;
		if (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7
			|| this->month == 8 || this->month == 10 || this->month == 12)
		{
			(day > 0 && day <= 31) ? this->day = day : this->day = 1;
		}
		if (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11)
		{
			(day > 0 && day <= 30) ? this->day = day : this->day = 1;
		}
		if (this->month == 2)
		{
			if ((year % 4) == 0)
			{
				(day > 0 && day <= 29) ? this->day = day : this->day = 1;
			}
			else
			{
				(day > 0 && day <= 28) ? this->day = day : this->day = 1;
			}
		}
		this->year = year;
	}

	MyDate operator++()
	{
		day += 1;
		if (month == 2)
		{
			if ((year % 4) == 0)
			{
				if (day > 29)
				{
					day = 1;
					month += 1;
				}
				return* this;
			}
			else
			{
				if (day > 28)
				{
					day = 1;
					month += 1;
				}
				return* this;
			}
			return* this;
		}
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day > 30)
			{
				day = 1;
				month += 1;
				return* this;
			}
			return* this;
		}
		if (month == 12)
		{
			if (day > 31) 
			{
				day = 1;
				month = 1;
				year += 1;
				return* this;
			}
			return* this;
		}
		else
		{
			if (day > 31)
			{
				day = 1;
				month += 1;
				return* this;
			}
		}
		return* this;
	}

	MyDate& operator++(int)
	{
		MyDate old(day, month, year);
		day += 1;
		if (month == 2)
		{
			if ((year % 4) == 0)
			{
				if (day > 29)
				{
					day = 1;
					month += 1;
				}
				return old;
			}
			else
			{
				if (day > 28)
				{
					day = 1;
					month += 1;
				}
				return old;
			}
			return old;
		}
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day > 30)
			{
				day = 1;
				month += 1;
				return old;
			}
		}
		if (month == 12)
		{
			if (day > 31)
			{
				day = 1;
				month = 1;
				year += 1;
				return old;
			}
		}
		if (this->month == 1 || this->month == 3 || this->month == 5 ||
			this->month == 7 || this->month == 8 || this->month == 10)
		{
			if (day > 31)
			{
				day = 1;
				month += 1;
				return old;
			}
		}
		return old;
	}

	void print()
	{
		cout << "Day: " << day << " month: " << month << " year: " << year << endl;
	}

	friend ostream& operator<<(ostream& out, MyDate& date);
};