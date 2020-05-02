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
    for (long long i = 0; i < N; i++)
    {
        long long t;
        cin >> t;
        A.push_back(t);
    }

    sort(A.begin(), A.end());

    long long c = 0;
    for (long long i = 0; i < N; i++)
    {
        for (long long j = i + 1; j < N; j++)
        {
            long long k = lower_bound(A.begin(), A.end(), A[i] + A[j]) - A.begin();
            c += k - j - 1;
        }
    }

    cout << c << endl;
}