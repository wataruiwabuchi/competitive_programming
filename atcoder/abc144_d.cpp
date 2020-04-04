#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
#define MOD int(1e9 + 7)

int main()
{
    double a, b, x;
    cin >> a >> b >> x;

    if (x >= a * a * b / 2)
    {
        double h = (a * a * b - x) / (a * a) * 2;
        cout << fixed << setprecision(10) << 180 * atan2(h, a) / M_PI << endl;
    }
    else
    {
        double c = 2 * x / (a * b);
        cout << fixed << setprecision(10) << 180 * atan2(b, c) / M_PI << endl;
    }
}