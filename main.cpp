#include <iostream>
#include "MyDate.h"

using namespace std;

int main()
{
	MyDate first(31, 7, 2020);
	cout << first << endl;
	++first;
	cout << first << endl;
	first++;
	cout << first;
	

	return 0;
}