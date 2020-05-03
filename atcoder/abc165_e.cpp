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

    long long N, M;
    cin >> N >> M;

    for (long long i = 0; i < M; i++)
        if (N % 2 == 0 && i >= N / 2 / 2)
            cout << i + 1 << ' ' << N - i - 1 << endl;
        else
            cout << i + 1 << ' ' << N - i << endl;
}