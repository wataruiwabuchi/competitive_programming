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

    vector<bool> f(N, false);
    for (long long i = 0; i < K; i++)
    {
        long long d;
        cin >> d;
        for (long long j = 0; j < d; j++)
        {
            long long t;
            cin >> t;
            f[t - 1] = true;
        }
    }

    long long c = 0;
    for (long long i = 0; i < N; i++)
        c += f[i];

    cout << N - c << endl;
}