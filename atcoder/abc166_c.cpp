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
    vector<long long> H;

    cin >> N >> M;
    for (long long i = 0; i < N; i++)
    {
        long long t;
        cin >> t;
        H.push_back(t);
    }

    vector<vector<long long>> e(N, vector<long long>{});
    for (long long i = 0; i < M; i++)
    {
        long long a, b;
        cin >> a >> b;
        e[a - 1].push_back(b - 1);
        e[b - 1].push_back(a - 1);
    }

    vector<long long> f(N, false);
    long long c = 0;
    for (long long i = 0; i < N; i++)
    {
        if (f[i] == false)
        {
            bool t = false;
            for (auto x : e[i])
            {
                if (H[i] <= H[x])
                {
                    t = true;
                    break;
                }
            }

            if (t == false)
            {
                c++;
                for (auto x : e[i])
                {
                    f[x] = true;
                }
            }
        }
    }
    cout << c << endl;
}