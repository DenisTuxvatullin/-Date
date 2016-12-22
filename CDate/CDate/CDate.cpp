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
	/*
	int day, month, year;
	cout << "Enter day: ";  cin >> day;
	cout << "Enter month: "; cin >> month;
	cout << "Enter year: "; cin >> year;
	Month mon = Month(month);
	CDate cDate(day, mon, year);
	*/
	CDate cDate(1, JANUARY, 1970);
	cDate.DataOperation("-", 1, 1, 1970);
	cout << cDate.OperatonResult;
	int c;
	cin >> c;
	return 0;
}

