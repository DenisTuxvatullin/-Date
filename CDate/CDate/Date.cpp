#include "stdafx.h"
#include "Date.h"
using namespace std;
#include <string>
#include <cstring>


CDate::CDate(unsigned int  day, Month month, unsigned year):d_day(1), d_month(FEBRUARY), d_year(MIN_YEAR), d_days(0)
{
	if (IsValid(day, month, year))
	{
		d_day = day;
		d_month = month;
		d_year = year;
		DetermineDataToDays(day, month, year);
		DetermineDayWeek();
	}
	
}
CDate::~CDate()
{
}
/////////////////////////////////
Month CDate::GetMonth()const
{
	return d_month;
}
unsigned CDate::GetYear()const
{
	return d_year;
}
WeekDay CDate::GetWeekDay()const
{
	return d_weekDay;
}
unsigned CDate::GetDay()const
{
	return d_day;
}
///////////////////////////////////
bool CDate::IsValid(unsigned day, Month month, unsigned year)const
{
	if (day > MAX_DAY || day < 1)
		return false;
	
	if (Month(month) > 12 || Month(month) < 1)
		return false;

	if (year < MIN_YEAR)
		return false;

	return true;
}


void CDate::DetermineDaysToDate(unsigned int days)
{
	unsigned int year = d_days / DAY_IN_YEAR;
	days = days % DAY_IN_YEAR;
	unsigned int month = 0;
	for (unsigned int  i = 0; DAYS_IN_MONTH[i] < days; i++)
	{
		days = days - DAYS_IN_MONTH[i];
		month++;
	}
	//month++;
	d_day = days;
	d_month = Month(month);
	d_year = year;
}

void CDate::DetermineDayWeek()//Определение дня недели
{
	int yearCode = 0, mCode = 0, dayWeek;
	unsigned start = 2000;
	bool weFindCode = false;
	while (!weFindCode)
	{
		if (d_year < start)
		{
			weFindCode = true;
		}
		else
		{
			yearCode = yearCode - 2;
			if (yearCode == -2)
			{
				yearCode = 6;
			}
			start = start + 100;
		}
	}
	mCode = MONTH_CODE[d_month - 1];
	dayWeek = ((d_day + yearCode + mCode) % 7) - 2;
	if (dayWeek < 1)
	{
		dayWeek = dayWeek + 7;
	}
	d_weekDay = WeekDay(dayWeek);
}

bool CDate::DetermineDataToDays(unsigned int days, Month month, unsigned int year)//считаем сколько дней
{
	int dayInMonth = 0;
	for (int i = 0; i < Month(month); i++)
	{
		dayInMonth += DAYS_IN_MONTH[i];
	}	
	d_days = days + (year * DAY_IN_YEAR) + dayInMonth;
	return true;
}


bool CDate::DataOperation(char* opeartion, unsigned int day, unsigned int mon, unsigned int year)
{
	Month month;
	month = Month(mon);
	unsigned int oldDays = d_days;
	DetermineDataToDays(day, month, year);

	if (opeartion == "+")
	{
		d_days = oldDays + day;
		DetermineDaysToDate(d_days);
		return true;
	}
	if (opeartion == "-")
	{
		if (year >= 1970)
		{
			OperatonResult = oldDays - d_days;
			DetermineDaysToDate(oldDays);
			return true;
		}
		else
		{
			d_days = oldDays - day;
		}

		if (d_days > START_DATA)
		{
			DetermineDaysToDate(d_days);
			return true;
		}
		else
		{
			DetermineDaysToDate(oldDays);
			return false;
		}
	}
	if (opeartion == "==")
	{
		if (oldDays == d_days)
		{
			return true;
		}
		else
		{
			DetermineDaysToDate(oldDays);
			return false;
		}
	}
	selection = true;
	if (opeartion == ">" || opeartion == "<")
	{
		if (opeartion == "<")
			selection = false;
		currentDays = d_days;
		DetermineDaysToDate(oldDays);
		if (oldDays > currentDays)
		{
			return selection;
		}
		else
		{
			return !selection;
		}
	}

	if (opeartion == "<=" || opeartion == ">=")
	{
		if (opeartion == "<=")
			selection = false;
		currentDays = d_days;
		DetermineDaysToDate(oldDays);
		if (oldDays == currentDays)
			return true;
		if (oldDays > currentDays)
		{
			return selection;
		}
		else
		{
			return !selection;
		}
	}
	return false;
}