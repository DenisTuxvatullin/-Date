#pragma once
enum Month { JANUARY = 1, FEBRUARY = 2 , MARCH = 3, APRIL = 4, MAY = 5, JUNE = 6, JULY = 7, AUGUST = 8, SEPTEMBER = 9, OCTOBER = 10, NOVEMBER = 11, DECEMBER = 12, EMPTY = 0 };
enum WeekDay { SUNDAY = 1, MONDAY = 2, TUESDAY = 3, WEDNESDAY = 4, THURSDAY = 5, FRIDAY = 6, SATURDAY = 7 };
const int MonthCod[12] {1, 4, 4, 0, 2, 5, 0, 3, 6,  1, 4, 6};
const unsigned int DayInM[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int DayInYear = 365, MaxDay = 31, MinYear = 1970, StartData = 719051;
class CDate
{
public:
	CDate(unsigned day, Month month, unsigned year);
	unsigned GetDay()const;
	Month GetMonth()const;
	unsigned GetYear()const;
	WeekDay GetWeekDay()const;
	unsigned SetData(unsigned days);
	bool IsValid(unsigned day, Month month, unsigned year)const;
	bool DetermineDataToDays(unsigned int days, Month month, unsigned int year);
	unsigned long d_days;
	void DetermineDayWeek();
	void DetermineDaysToDate(unsigned int days);
	int OperatonResult;
	bool DataOperation(char* opeartion, unsigned int day, unsigned int month, unsigned int year);
	~CDate();
private:
	unsigned int d_day;
	Month d_month;
	WeekDay d_weekDay;
	unsigned int  d_year;
	unsigned int d_timestamp;
	
	
};

