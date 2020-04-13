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

long long gcd(long long a, long long b)
{
    while (1)
    {
        if (a < b)
            swap(a, b);
        if (!b)
            break;
        a %= b;
    }
    return a;
}

int main()
{
    long long K;
    cin >> K;

    long long total = 0;
    for (long long i = 1; i < K + 1; i++)
    {
        for (long long j = 1; j < K + 1; j++)
        {
            for (long long k = 1; k < K + 1; k++)
            {
                total += gcd(gcd(i, j), k);
            }
        }
    }

    cout << total << endl;
}