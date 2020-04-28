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
    vector<long long> m(N, -1);
    for (long long i = 0; i < N; i++)
    {
        long long t;
        cin >> t;
        m[t-1] = i;
    }

    long long i = 0;
    long long max_count = 1;
    while (i < N - 1)
    {
        long long count = 1;
        while (i < N - 1 && m[i] < m[i + 1])
        {
            count++;
            i++;
        }
        max_count = max(max_count, count);
        i++;
    }

    cout << N - max_count << endl;
}