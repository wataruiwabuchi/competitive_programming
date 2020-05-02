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

int main()
{
    cout.precision(18);

    long long X, Y;
    cin >> X >> Y;

    long long c = abs(abs(X) - abs(Y));
    if (X == 0 && Y < 0)
        c++;
    else if (Y == 0 && X > 0)
        c++;
    else if (X * Y < 0)
        c++;
    else if (X > 0)
    {
        if (X > Y)
            c += 2;
    }
    else if (X < 0)
    {
        if (X > Y)
            c += 2;
    }

    cout << c << endl;
}