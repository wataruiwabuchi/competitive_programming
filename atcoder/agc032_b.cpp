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

    cout << (N * N - N - N + N % 2) / 2 << endl;
    for (long long i = 0; i < N; i++)
    {
        for (long long j = i + 1; j < N; j++)
        {
            if (i == j)
                continue;
            else if ((N - 1) - i - N % 2 == j)
                continue;
            else
                cout << i + 1 << ' ' << j + 1 << endl;
        }
    }
}