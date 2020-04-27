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

    vector<vector<long long>> dp(2, vector<long long>(2020, 0));

    long long cv = stoi(S.substr(0, 4));
    dp[1][cv % 2019]++;
    long long count = dp[1][0];
    for (long long i = 4; i < S.size(); i++)
    {
        for (long long j = 0; j < 2019; j++)
        {
            dp[i % 2][((j * 10) + (S[i] - '0')) % 2019] = dp[(i - 1) % 2][j];
        }
        cv = (cv * 10) % 10000;
        cv += S[i] - '0';
        dp[i % 2][cv % 2019]++;
        count += dp[i % 2][0];
    }

    cout << count << endl;
}