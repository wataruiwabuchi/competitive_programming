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
    vector<long long> A, c;

    cin >> N;
    for (long long i = 0; i < N; i++)
    {
        long long t;
        cin >> t;
        A.push_back(t);
    }

    sort(A.begin(), A.end());

    long long b = 0;
    for (long long i = 0; i < N; i++)
    {
        b += A[i];
        c.push_back(b);
    }

    long long count = 0;
    for (long long i = 0; i < N - 1; i++)
        if (2 * c[i] >= A[i + 1])
            count++;
        else
            count = 0;

    cout << count + 1 << endl;
}