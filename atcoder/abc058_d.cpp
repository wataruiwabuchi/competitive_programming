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
using namespace std;
#define MOD int(1e9 + 7)
#define INF (long long)(1e18)

int main()
{
    long long N, M;
    vector<long long> X, Y;

    cin >> N >> M;
    for (long long i = 0; i < N; i++)
    {
        long long t;
        cin >> t;
        X.push_back(t);
    }
    for (long long i = 0; i < M; i++)
    {
        long long t;
        cin >> t;
        Y.push_back(t);
    }

    long long x = 0, y = 0;
    for (long long i = 0; i < N - 1; i++)
    {
        x += (X[i + 1] - X[i]) * (i + 1) % MOD * (N - i - 1) % MOD;
        x %= MOD;
    }
    for (long long i = 0; i < M - 1; i++)
    {
        y += (Y[i + 1] - Y[i]) * (i + 1) % MOD * (M - i - 1) % MOD;
        y %= MOD;
    }

    cout << (x * y) % MOD << endl;
}