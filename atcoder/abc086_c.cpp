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
    long long N;
    cin >> N;

    long long cx = 0, cy = 0, ct = 0;
    for (long long i = 0; i < N; i++)
    {
        long long t, x, y;
        cin >> t >> x >> y;

        long long d = abs(x - cx) + abs(y - cy);
        if (t - ct >= d && (t - ct - d) % 2 == 0)
        {
            cx = x;
            cy = y;
            ct = t;
        }
        else
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}