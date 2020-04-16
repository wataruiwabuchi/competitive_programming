#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
#define MOD int(1e9 + 7)

long long mod_pow(long long _x, long long _n)
{
    long long ret = 1;
    while (0 < _n)
    {
        if ((_n % 2) == 0)
        {
            _x = (_x * _x) % MOD;
            _n >>= 1;
        }
        else
        {
            ret = (ret * _x) % MOD;
            --_n;
        }
    }
    return ret;
}

string S;
long long dfs(int i)
{
    if (i == S.size())
        return 1;

    long long t;
    if (S[i] == '1')
    {
        t = mod_pow(3, S.size() - i - 1);
        t = (t + (2 * dfs(i + 1)) % MOD) % MOD;
    }
    else
        t = dfs(i + 1);

    return t;
}

int main()
{
    cin >> S;
    cout << dfs(0) << endl;
}