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
    vector<long long> D;

    cin >> N;

    long long s = 0;
    long long m = 0;
    for (long long i = 0; i < N; i++)
    {
        long long t;
        cin >> t;
        s += t;
        m = max(m, t);
        D.push_back(t);
    }

    cout << s << endl;

    if (N == 1)
        cout << D[0] << endl;
    else if (N == 2)
        cout << abs(D[0] - D[1]) << endl;
    else
    {
        if (s < 2 * m)
            cout << 2 * m - s << endl;
        else
            cout << 0 << endl;
    }
}