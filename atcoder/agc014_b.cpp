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
    long long N, M;
    cin >> N >> M;

    vector<long long> c(N, 0);
    for (long long i = 0; i < M; i++)
    {
        long long a, b;
        cin >> a >> b;
        c[min(a, b) - 1] += 1;
        c[max(a, b) - 1] += -1;
    }

    long long t = 0;
    for (long long i = 0; i < N; i++)
    {
        t += c[i];
        if (t % 2 == 1)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}