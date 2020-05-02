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

    string S;
    long long T;

    cin >> S;
    cin >> T;

    long long h = 0, w = 0, c = 0;
    for (long long i = 0; i < S.size(); i++)
    {
        switch (S[i])
        {
        case 'U':
            h++;
            break;
        case 'D':
            h--;
            break;
        case 'R':
            w++;
            break;
        case 'L':
            w--;
            break;
        case '?':
            c++;
            break;
        }
    }

    h = abs(h);
    w = abs(w);

    if (T == 1)
        cout << h + w + c << endl;
    else
    {
        if (h + w > c)
            cout << h + w - c << endl;
        else
            cout << (c - h - w) % 2 << endl;
    }
}