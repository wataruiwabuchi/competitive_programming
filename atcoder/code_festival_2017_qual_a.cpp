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
    long long H, W;
    vector<long long> c(26, 0);

    cin >> H >> W;
    for (long long i = 0; i < H; i++)
    {
        for (long long j = 0; j < W; j++)
        {
            char t;
            cin >> t;
            c[t - 'a']++;
        }
    }

    vector<long long> num(3, 0);
    num[0] = (H / 2) * (W / 2);
    num[1] = (H % 2) * (W / 2) + (H / 2) * (W % 2);
    num[2] = (H % 2) * (W % 2);

    for (long long i = 0; i < 2; i++)
    {
        long long t = pow(2, 2 - i);
        long long count = 0;
        bool f = false;
        for (long long j = 0; j < 26; j++)
        {
            count += c[j] / t;
            c[j] %= t;
            if (count >= num[i])
            {
                c[j] += (count - num[i]) * t;
                f = true;
                break;
            }
        }
        if (f == false)
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}