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

    for (long long i = 0; i < N + 1; i++)
    {
        long long a = (K - 2 * i) - 3 * (N - i);
        if (a >= 0 && N - i - a >= 0 &&  2 * i + 3 * (N - i - a) + 4 * a == K)
        {
            cout << i << ' ' << N - i - a << ' ' << a << endl;
            return 0;
        }
    }

    cout << "-1 -1 -1" << endl;
}