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

    long long N, K;
    vector<long long> A;
    bool f = false;

    cin >> N >> K;
    for (long long i = 0; i < N; i++)
    {
        long long t;
        cin >> t;
        A.push_back(t);

        if (t == 0)
            f = true;
    }

    if (f)
    {
        cout << N << endl;
        return 0;
    }

    long long l = -1, r = -1, c = 1;
    long long m = 0;
    while (r < N)
    {
        if (r + 1 < N)
        {
            if (c * A[r + 1] <= K)
            {
                r++;
                c *= A[r];
                m = max(m, r - l);
            }
            else
            {
                l++;
                c /= A[l];
            }
        }
        else
        {
            l++;
            if (l >= N)
                break;
            c /= A[l];
        }

        if (l > r)
        {
            r = l;
            c = A[l];
        }
    }

    cout << m << endl;
}