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
    vector<long long> w{0};

    cin >> N;
    for (long long i = 0; i < N; i++)
    {
        long long t;
        cin >> t;

        if (w.back() < t)
            w.push_back(t);
        else
        {
            long long j = lower_bound(w.begin(), w.end(), t) - w.begin();
            w[j] = t;
            sort(w.begin(), w.end());
        }
    }

    cout << w.size() - 1 << endl;
}