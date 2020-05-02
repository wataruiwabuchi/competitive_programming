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

    long long N, M;

    cin >> N >> M;

    vector<bool> f(N, false);
    vector<long long> num(N, 1);
    f[0] = true;
    for (long long i = 0; i < M; i++)
    {
        long long x, y;
        cin >> x >> y;
        if (f[x - 1])
            f[y - 1] = true;
        num[y - 1]++;
        num[x - 1]--;
        if (num[x - 1] == 0)
            f[x - 1] = false;
    }

    long long c = 0;
    for (long long i = 0; i < N; i++)
        c += f[i];

    cout << c << endl;
}