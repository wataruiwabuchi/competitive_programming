#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <numeric>
using namespace std;
#define MOD int(1e9 + 7)
#define INF (long long)(1e18)

int main()
{
    long long N, K;
    vector<long long> A;

    cin >> N >> K;
    for (long long i = 0; i < N; i++)
    {
        long long t;
        cin >> t;
        A.push_back(t);
    }

    long long m = A[0];
    long long g = A[0];
    for (long long i = 1; i < N; i++)
    {
        m = max(m, A[i]);
        g = __gcd(g, A[i]);
    }

    if (m < K || K % g != 0)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << "POSSIBLE" << endl;
}