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

    for (long long i = 0; i < INF; i++)
    {
        for (long long j = -1; j <= 1; j += 2)
        {
            long long t = N + j * (long long)pow(i, 5);
            long long a = pow((long double)t, (long double)0.2);
            if ((long long)pow(a, 5) - (long long)pow(j * i, 5) == N)
            {
                cout << a << ' ' << i * j << endl;
                return 0;
            }
        }
    }
}