#include "Date.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Date::Date()
{
    day = month = year = 0;
}

Date::~Date() {}

void Date::setDate(int d, int m, int y)
{
    try
    {
        if (y < 0)
            throw invalid_argument("Year cannot be negative.");
        if (m < 1 || m > 12)
            throw invalid_argument("Month must be between 1 and 12.");
        if (d < 1 || d > 31)
            throw invalid_argument("Day must be between 1 and 31.");
        if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
            throw invalid_argument("Invalid day for the given month.");

        bool isLeap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
        if (m == 2 && ((isLeap && d > 29) || (!isLeap && d > 28)))
            throw invalid_argument("Invalid day for February.");

        day = d;
        month = m;
        year = y;
    }
    catch (exception& e)
    {
        cerr << "Error setting date: " << e.what() << endl;
    }
}

void Date::show() 
{
    try
    {
        if (day == 0 || month == 0 || year == 0)
            throw  invalid_argument("Date is not set properly.");

        cout << day << "/" << month << "/" << year;
    }
    catch (exception& e)
    {
        cerr << "Error displaying date: " << e.what() << endl;
    }
}

int Date::getDay()
{ 
    return day;
}
int Date::getMonth()
{ 
    return month;
}
int Date::getYear()
{ 
    return year;
}
