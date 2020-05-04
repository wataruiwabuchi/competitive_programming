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

    long long N, M, X, Y;
    vector<long long> A, B;

    cin >> N >> M >> X >> Y;
    for (long long i = 0; i < N; i++)
    {
        long long t;
        cin >> t;
        A.push_back(t);
    }
    for (long long i = 0; i < M; i++)
    {
        long long t;
        cin >> t;
        B.push_back(t);
    }

    long long i = 0, j = 0, t = 0, c = 0;
    while (i < N && j < M)
    {
        while (i < N)
        {
            if (t <= A[i])
                break;
            i++;
        }

        if (i >= N)
            break;
        t = A[i] + X;

        while (j < M)
        {
            if (t <= B[j])
            {
                c++;
                break;
            }
            j++;
        }

        if (j >= M)
            break;

        t = B[j] + Y;
    }

    cout << c << endl;
}