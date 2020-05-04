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

    long long H, W;
    vector<string> S;

    cin >> H >> W;
    for (long long i = 0; i < H; i++)
    {
        string t;
        cin >> t;
        S.push_back(t);
    }

    vector<vector<char>> m(H, vector<char>(W, '.'));
    for (long long i = 0; i < H; i++)
    {
        for (long long j = 0; j < W; j++)
        {
            long long c1 = 0, c2 = 0;
            for (long long k = -1; k <= 1; k++)
            {
                for (long long l = -1; l <= 1; l++)
                {
                    if (i + k >= 0 && i + k < H)
                    {
                        if (j + l >= 0 && j + l < W)
                        {
                            c1++;
                            if (S[i + k][j + l] == '#')
                                c2++;
                        }
                    }
                }
            }
            if (c1 == c2)
                m[i][j] = '#';
        }
    }

    vector<vector<char>> f(H, vector<char>(W, '.'));
    for (long long i = 0; i < H; i++)
    {
        for (long long j = 0; j < W; j++)
        {
            if (m[i][j] == '#')
            {
                for (long long k = -1; k <= 1; k++)
                {
                    for (long long l = -1; l <= 1; l++)
                    {
                        if (i + k >= 0 && i + k < H)
                        {
                            if (j + l >= 0 && j + l < W)
                            {
                                f[i + k][j + l] = '#';
                            }
                        }
                    }
                }
            }
        }
    }

    for (long long i = 0; i < H; i++)
    {
        for (long long j = 0; j < W; j++)
        {
            if (S[i][j] != f[i][j])
            {
                cout << "impossible" << endl;
                return 0;
            }
        }
    }

    cout << "possible" << endl;
    for (long long i = 0; i < H; i++)
    {
        for (long long j = 0; j < W; j++)
        {
            cout << m[i][j];
        }
        cout << endl;
    }
}