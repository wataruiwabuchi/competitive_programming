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

    long long N;
    cin >> N;

    map<long long, long long> m;
    m[-1] = 3;
    long long c = 1;
    for (long long i = 0; i < N; i++)
    {
        long long t;
        cin >> t;
        c *= (m[t - 1] - m[t]);
        c %= MOD;
        m[t]++;
    }

    cout << c << endl;
}