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
    vector<vector<char>> M;

    cin >> H >> W;
    M.push_back(vector<char>(W + 1, '.'));
    for (long long i = 0; i < H; i++)
    {
        vector<char> tv{'.'};
        for (long long j = 0; j < W; j++)
        {
            char t;
            cin >> t;
            tv.push_back(t);
        }
        M.push_back(tv);
    }

    vector<vector<long long>> dp(H + 1, vector<long long>(W + 1, INF));
    dp[1][0] = 0;
    dp[0][1] = 0;
    for (long long i = 1; i < H + 1; i++)
    {
        for (long long j = 1; j < W + 1; j++)
        {
            if (M[i - 1][j] == M[i][j])
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            else
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            if (M[i][j - 1] == M[i][j])
                dp[i][j] = min(dp[i][j], dp[i][j - 1]);
            else
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
        }
    }

    cout << (dp[H][W] + 1) / 2 << endl;
}