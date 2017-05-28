#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Date
{
  public:
    int day;
    int month;
    int year;

    Date(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }

    bool operator<=(const Date &d)
    {
        if (year < d.year)
        {
            return true;
        }
        else if (year == d.year)
        {
            if (month < d.month)
            {
                return true;
            }
            else if (month == d.month)
            {
                if (day <= d.day)
                {
                    return true;
                }
            }
        }

        return false;
    }
};

class Book
{
  public:
    Date *expectedReturn;
    Date *actualReturn;
    Book(Date *d1, Date *d2)
    {
        expectedReturn = d2;
        actualReturn = d1;
    }

    bool isLate()
    {
        return !(*actualReturn <= *expectedReturn);
    }
};

int main()
{
    int fine = 0;
    int d, m, y;
    cin >> d >> m >> y;
    Date d1(d, m, y);
    cin >> d >> m >> y;
    Date d2(d, m, y);
    Book book(&d1, &d2);

    if (book.isLate())
    {
        if (book.actualReturn->year > book.expectedReturn->year)
        {
            fine = 10000;
        }
        else if (book.actualReturn->month > book.expectedReturn->month)
        {
            int monthsLate = book.actualReturn->month - book.expectedReturn->month;
            fine = 500 * monthsLate;
        }
        else
        {
            int daysLate = book.actualReturn->day - book.expectedReturn->day;
            fine = 15 * daysLate;
        }
    }

    cout << fine << endl;

    return 0;
}
