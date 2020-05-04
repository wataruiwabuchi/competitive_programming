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
    vector<long long> A;
    cin >> N;

    map<long long, long long> m;
    for (long long i = 0; i < N; i++)
    {
        long long t;
        cin >> t;
        A.push_back(t);
        m[i + 1 - t]++;
    }

    long long c = 0;
    for (long long i = 0; i < N; i++)
        c += m[i + 1 + A[i]];

    cout << c << endl;
}