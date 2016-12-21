// TestCDate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\CDate\Date.h"



BOOST_AUTO_TEST_CASE(Defoult)
{
	CDate cDate(1, JANUARY, 1971);
	BOOST_CHECK(cDate.GetDay() == 1);
	BOOST_CHECK(cDate.GetMonth() == JANUARY);
	BOOST_CHECK(cDate.GetYear() == 1971);
}

BOOST_AUTO_TEST_CASE(NextDay)
{
	CDate cDate(1, JANUARY, 1971);
	BOOST_CHECK(cDate.GetDay() == 1);
	BOOST_CHECK(cDate.GetMonth() == JANUARY);
	BOOST_CHECK(cDate.GetYear() == 1971);
	BOOST_CHECK(cDate.DataOperation("+", 1, 0, 0));
	BOOST_CHECK(cDate.GetDay() == 2);
}

BOOST_AUTO_TEST_CASE(PlusDays)
{
	CDate cDate(1, JANUARY, 1971);
	BOOST_CHECK(cDate.GetDay() == 1);
	BOOST_CHECK(cDate.GetMonth() == JANUARY);
	BOOST_CHECK(cDate.GetYear() == 1971);
	BOOST_CHECK(cDate.DataOperation("+", 7, 0, 0));
	BOOST_CHECK(cDate.GetDay() == 8);
}

BOOST_AUTO_TEST_CASE(AfterDay)
{
	CDate cDate(2, JANUARY, 1971);
	BOOST_CHECK(cDate.GetDay() == 2);
	BOOST_CHECK(cDate.GetMonth() == JANUARY);
	BOOST_CHECK(cDate.GetYear() == 1971);
	BOOST_CHECK(cDate.DataOperation("-", 1, 0, 0));
	BOOST_CHECK(cDate.GetDay() == 1);
}

BOOST_AUTO_TEST_CASE(MinData)
{
	CDate cDate(2, JANUARY, 1999);
	BOOST_CHECK(cDate.DataOperation("-", 2, JANUARY, 2000));
	BOOST_CHECK(cDate.OperatonResult == -365);
	BOOST_CHECK(cDate.DataOperation("-", 1, JANUARY, 1999));
	BOOST_CHECK(cDate.OperatonResult == 1);
}