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

    long long X, Y, A, B, C;
    vector<long long> P, Q, R;

    cin >> X >> Y >> A >> B >> C;
    for (long long i = 0; i < A; i++)
    {
        long long t;
        cin >> t;
        P.push_back(t);
    }
    for (long long i = 0; i < B; i++)
    {
        long long t;
        cin >> t;
        Q.push_back(t);
    }
    for (long long i = 0; i < C; i++)
    {
        long long t;
        cin >> t;
        R.push_back(t);
    }

    sort(P.begin(), P.end(), [](long long &a, long long &b) { return a > b; });
    sort(Q.begin(), Q.end(), [](long long &a, long long &b) { return a > b; });
    sort(R.begin(), R.end(), [](long long &a, long long &b) { return a > b; });

    vector<long long> v;
    for (long long i = 0; i < X; i++)
        v.push_back(P[i]);
    for (long long i = 0; i < Y; i++)
        v.push_back(Q[i]);
    for (long long i = 0; i < C; i++)
        v.push_back(R[i]);

    sort(v.begin(), v.end(), [](long long &a, long long &b) { return a > b; });

    long long t = 0;
    for (long long i = 0; i < X + Y; i++)
        t += v[i];

    cout << t << endl;
}