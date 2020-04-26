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
    string S;
    cin >> S;

    long long min_ope = LLONG_MAX;
    for (long long i = 0; i < 26; i++)
    {
        string c = S;
        long long ope = 0;
        while (true)
        {
            long long count = 0;
            for (long long j = 0; j < c.size(); j++)
                if (c[j] - 'a' == i)
                    count++;

            if (count == c.size())
            {
                min_ope = min(min_ope, ope);
                break;
            }

            string ns(c.size() - 1, '*');
            for (long long j = 0; j < ns.size(); j++)
                if (c[j] - 'a' == i || c[j + 1] - 'a' == i)
                    ns[j] = i + 'a';

            c = ns;
            ope++;
        }
    }

    cout << min_ope << endl;
}