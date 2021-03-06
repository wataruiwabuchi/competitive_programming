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

    long long A, B, C;

    cin >> A >> B >> C;

    long long d = C - A - B;
    if (d > 0 && 4 * A * B < d * d)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}