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
using namespace std;
#define MOD int(1e9 + 7)
#define INF (long long)(1e18)

// 日付計算のためのクラス
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

    long long N;
    set<string> H;
    Date d(2012, 1, 1);

    cin >> N;
    for (long long i = 0; i < N; i++)
    {
        string t;
        cin >> t;
        H.insert(t);
    }

    long long c = 0;
    long long a = 0;
    long long max_a = 0;
    for (long long i = 0; i < 366; i++)
    {
        string t = to_string(d.Month()) + "/" + to_string(d.Day());
        if (i % 7 == 0 || i % 7 == 6) // 土日
        {
            if (H.find(t) != H.end()) // 祝日
            {
                c++;
            }
            a++;
            max_a = max(max_a, a);
        }
        else
        {
            if (H.find(t) != H.end()) // 祝日
            {
                a++;
                max_a = max(max_a, a);
            }
            else if (c > 0)
            {
                c--;
                a++;
                max_a = max(max_a, a);
            }
            else
                a = 0;
        }
        d.Add(0, 0, 1);
    }

    cout << max_a << endl;
}