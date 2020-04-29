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
    cin >> S;

    long long c = 0;
    for (long long i = 0; i < S.size() / 2; i++)
        if (S[i] != S[S.size() - i - 1])
            c++;

    if (S.size() == 1)
        cout << 0 << endl;
    else if (c == 1)
    {
        long long t = 0;
        for (long long i = 0; i < S.size(); i++)
        {
            if (S[i] != S[S.size() - i - 1])
                t += 24;
            else
                t += 25;
        }
        cout << t << endl;
    }
    else if (c == 0)
        cout << 25 * (S.size() - S.size() % 2) << endl;
    else
        cout << 25 * S.size() << endl;
}