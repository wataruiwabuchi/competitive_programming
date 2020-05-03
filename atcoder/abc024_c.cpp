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

    long long N, D, K;
    vector<vector<long long>> LR, ST;

    cin >> N >> D >> K;
    for (long long i = 0; i < D; i++)
    {
        long long l, r;
        cin >> l >> r;
        LR.push_back(vector<long long>{l, r});
    }
    for (long long i = 0; i < K; i++)
    {
        long long s, t;
        cin >> s >> t;

        long long c = s;
        for (long long j = 0; j < D; j++)
        {
            if (LR[j][0] <= c && LR[j][1] >= c)
            {
                if (LR[j][0] <= t && LR[j][1] >= t)
                {
                    cout << j + 1 << endl;
                    break;
                }
                else if (c > t)
                    c = LR[j][0];
                else
                    c = LR[j][1];
            }
        }
    }
}