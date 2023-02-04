#include "MyDate.h"
#include <iostream>

using namespace std;

ostream& operator<<(ostream& out, MyDate& date)
{
	if (date.day < 10)
	{
		out << "0" << date.day;
	}
	else
	{
		out << date.day;
	}
	if (date.month < 10)
	{
		out << " : 0" << date.month;
	}
	else
	{
		out << " : " << date.month;
	}
	out << " : " << date.year;
    return out;
}
