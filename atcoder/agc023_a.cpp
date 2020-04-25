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
    long long N;
    vector<long long> A;
    map<long long, long long> c;

    cin >> N;
    A.push_back(0);
    c[0]++;
    for (long long i = 0; i < N; i++)
    {
        long long t;
        cin >> t;
        A.push_back(A[i] + t);
        c[A[i + 1]]++;
    }

    long long total = 0;
    for (auto x : c)
    {
        total += x.second * (x.second - 1);
    }

    cout << total / 2 << endl;
}