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

map<long long, long long> decomposit_prime(long long n)
{
    map<long long, long long> primes;
    long long a = 2;
    while (n >= a * a)
    {
        if (n % a == 0)
        {
            primes[a]++;
            n /= a;
        }
        else
        {
            a++;
        }
    }

    primes[n]++;
    return primes;
}

int main()
{
    map<long long, long long> primes = decomposit_prime(311114770564041497);
    for (auto x : primes)
    {
        cout << x.first << ' ' << x.second << endl;
    }
}