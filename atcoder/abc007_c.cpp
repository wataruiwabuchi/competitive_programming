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

    long long H, W, Sx, Sy, Gx, Gy;
    vector<vector<char>> M;

    cin >> H >> W;
    cin >> Sy >> Sx;
    cin >> Gy >> Gx;

    for (long long i = 0; i < H; i++)
    {
        vector<char> tv;
        for (long long j = 0; j < W; j++)
        {
            char t;
            cin >> t;
            tv.push_back(t);
        }
        M.push_back(tv);
    }

    queue<vector<long long>> q;
    q.push(vector<long long>{Sx - 1, Sy - 1, 0});
    vector<vector<bool>> f(H, vector<bool>(W, false));
    f[Sy - 1][Sx - 1] = true;
    while (q.size() > 0)
    {
        long long cy = q.front()[0];
        long long cx = q.front()[1];
        long long d = q.front()[2];
        q.pop();

        if (cy == Gy - 1 && cx == Gx - 1)
        {
            cout << d << endl;
            return 0;
        }

        for (auto x : vector<vector<long long>>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}})
        {
            if (M[cy + x[0]][cx + x[1]] == '.' && f[cy + x[0]][cx + x[1]] == false)
            {
                f[cy + x[0]][cx + x[1]] = true;
                q.push(vector<long long>{cy + x[0], cx + x[1], d + 1});
            }
        }
    }
}