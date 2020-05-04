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

    long long a[2] = {0, 1};
    long long i = 0;
    while (i < N)
    {
        a[i % 2] = a[0] + a[1];
        i++;
    }

    cout << min(a[0], a[1]) << ' ' << max(a[0], a[1]) << endl;
}