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

    long long A, B, N;
    cin >> A >> B >> N;

    if (B - 1 > N)
        cout << floor(A * N / B) - A * floor(N / B) << endl;
    else
        cout << floor(A * (B - 1) / B) - A * floor((B - 1) / B) << endl;
}