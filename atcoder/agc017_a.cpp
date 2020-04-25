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
    long long N, P;
    vector<long long> A(2, 0);

    cin >> N >> P;
    for (long long i = 0; i < N; i++)
    {
        long long t;
        cin >> t;
        A[t % 2]++;
    }

    long long t = pow(2, A[0]);
    long long total = 0;
    for (long long i = P; i <= A[1]; i += 2)
    {
        long long c = 1;
        for (long long j = 0; j < min(i, A[1] - i); j++)
            c *= (A[1] - j);
        for (long long j = 1; j < min(i, A[1] - i) + 1; j++)
            c /= j;
        total += t * c;
    }

    cout << total << endl;
}