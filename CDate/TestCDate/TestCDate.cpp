// TestCDate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <boost/test/unit_test.hpp>
#include "..\CDate\Date.h"



BOOST_AUTO_TEST_CASE(NormData)
{
	CDate cDate(23, DECEMBER, 2016);
	BOOST_CHECK(cDate.GetDay() == 23);
	BOOST_CHECK(cDate.GetMonth() == DECEMBER);
	BOOST_CHECK(cDate.GetYear() == 2016);
	BOOST_CHECK(cDate.GetWeekDay() == THURSDAY);
}

BOOST_AUTO_TEST_CASE(AddDay)
{
	CDate cDate(1, JANUARY, 1970);
	BOOST_CHECK(cDate.GetDay() == 1);
	BOOST_CHECK(cDate.GetMonth() == JANUARY);
	BOOST_CHECK(cDate.GetYear() == 1970);
	BOOST_CHECK(cDate.DataOperation("+", 1, 0, 0));
	BOOST_CHECK(cDate.GetDay() == 2);
	BOOST_CHECK(cDate.DataOperation("+", 7, 0, 0));
	BOOST_CHECK(cDate.GetDay() == 9);
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

BOOST_AUTO_TEST_CASE(DeductData)
{
	CDate cDate(1, JANUARY, 1970);
	BOOST_CHECK(cDate.DataOperation("-", 1, 1, 1970));
	BOOST_CHECK(cDate.OperatonResult == 0);
	BOOST_CHECK(!cDate.DataOperation("-", 1, 0, 0));
	BOOST_CHECK(cDate.GetDay() == 1);
	BOOST_CHECK(cDate.GetMonth() == JANUARY);
	BOOST_CHECK(cDate.GetYear() == 1970);
	

}

BOOST_AUTO_TEST_CASE(Equality)
{
	CDate cDate(1, JANUARY, 1970);
	BOOST_CHECK(cDate.DataOperation("==", 1, 1, 1970));
	BOOST_CHECK(!cDate.DataOperation("==", 1, 2, 1970));

}

BOOST_AUTO_TEST_CASE(MoreLessStrict)
{
	CDate cDate(10, JANUARY, 1971);
	BOOST_CHECK(cDate.DataOperation(">", 1, 1, 1970));
	BOOST_CHECK(!cDate.DataOperation(">", 1, 10, 1970));
	BOOST_CHECK(cDate.DataOperation("<", 1, 10, 1970));
	BOOST_CHECK(!cDate.DataOperation("<", 1, 1, 1970));

}

BOOST_AUTO_TEST_CASE(MoreLessEq)
{
	CDate cDate(10, JANUARY, 1971);
	BOOST_CHECK(cDate.DataOperation(">=", 1, 1, 1970));
	BOOST_CHECK(!cDate.DataOperation(">=", 1, 10, 1970));
	BOOST_CHECK(!cDate.DataOperation("<=", 1, 10, 1956));
	BOOST_CHECK(cDate.DataOperation("<=", 1, 10, 1978));
	BOOST_CHECK(cDate.DataOperation(">=", 1, 1, 1970));
	BOOST_CHECK(cDate.DataOperation("<=", 1, 1, 1970));
}

BOOST_AUTO_TEST_CASE(IncorrectOpearator)
{
	CDate cDate(1, JANUARY, 1971);
	BOOST_CHECK(!cDate.DataOperation("dfwefwef", 7, 0, 0));
}