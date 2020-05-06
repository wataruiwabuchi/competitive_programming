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

    long long N, K;
    cin >> N >> K;

    long long c = 0;
    long long v = -1;
    long long a = 0;
    for (long long i = 0; i < N; i++)
    {
        long long t;
        cin >> t;

        if (v < t)
            c++;
        else
            c = 1;
        if (c >= K)
            a++;

        v = t;
    }

    cout << a << endl;
}