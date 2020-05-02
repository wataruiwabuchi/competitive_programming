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

    long long N, C, K;
    vector<long long> T;

    cin >> N >> C >> K;
    for (long long i = 0; i < N; i++)
    {
        long long t;
        cin >> t;
        T.push_back(t);
    }

    sort(T.begin(), T.end());

    long long i = 0;
    long long c = 0;
    while (i < N)
    {
        long long v = T[i];

        for (long long j = 0; j < C && i < N; j++)
        {
            if (v + K < T[i])
            {
                break;
            }
            i++;
        }
        c++;
    }
    cout << c << endl;
}