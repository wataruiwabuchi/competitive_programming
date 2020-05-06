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

    long long N, Q;
    cin >> N >> Q;

    vector<long long> c(N + 1, 0);
    for (long long i = 0; i < Q; i++)
    {
        long long l, r;
        cin >> l >> r;
        c[l - 1] += 1;
        c[r] -= 1;
    }

    long long t = 0;
    for (long long i = 0; i < N; i++)
    {
        t += c[i];
        cout << t % 2;
    }
    cout << endl;
}