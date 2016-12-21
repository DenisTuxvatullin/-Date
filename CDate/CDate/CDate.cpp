// CDate.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"
#include <iostream>
#include "Date.h"
#include <string>
#include <fstream>
using namespace std;
#include <iostream>
#include <cctype>

int main()
{
	int day, month, year;
	cout << "Enter day: ";  cin >> day;
	cout << "Enter month: "; cin >> month;
	cout << "Enter year: "; cin >> year;
	Month mon = Month(month);
	CDate cDate(day, mon, year);
	return 0;
}

