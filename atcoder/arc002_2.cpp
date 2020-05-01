#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <ctime>
using namespace std;
#define MOD int(1e9 + 7)
#define INF (long long)(1e18)

class Date
{
private:
    int year, month, day;
    int lastday_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool JudgeLeapYear(int y)
    {
        if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
            return true;
        return false;
    }

public:
    Date(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }

    void Add(int dy, int dm, int dd)
    {
        year += dy + (month + dm - 1) / 12;
        month = (month + dm - 1) % 12 + 1;
        day += dd;

        int lastday = lastday_of_month[month - 1];
        lastday += (month == 2) * JudgeLeapYear(year);
        while (day > lastday)
        {
            dd = dd - (lastday - day) - 1;
            day = 1;
            year += (month + 1) / 13;
            month = (month + 1) % 13 + (month + 1) / 13;

            lastday = lastday_of_month[month - 1];
            lastday += (month == 2) * JudgeLeapYear(year);
        }
    }

    int Year() { return year; }

    int Month() { return month; }

    int Day() { return day; }
};

int main()
{
    cout.precision(18);

    string S;
    cin >> S;

    int year = stoi(S.substr(0, 4));
    int month = stoi(S.substr(5, 2));
    int day = stoi(S.substr(8, 2));

    Date d(year, month, day);

    for (int i = 0; i < 1000; i++)
    {
        if (d.Year() % (d.Month() * d.Day()) == 0)
        {
            cout << d.Year();
            cout << '/' << setw(2) << setfill('0') << d.Month();
            cout << '/' << setw(2) << setfill('0') << d.Day();
            cout << endl;
            return 0;
        }
        d.Add(0, 0, 1);
    }
}