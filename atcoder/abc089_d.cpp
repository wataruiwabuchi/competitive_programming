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

int main()
{
    int H, W, D, Q;
    vector<vector<long long>> A;
    map<long long, vector<int>> v2xy;

    cin >> H >> W >> D;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            long long t2;
            cin >> t2;
            t2--;
            v2xy[t2] = vector<int>{i, j};
        }
    }
    cin >> Q;

    vector<long long> R2L(H * W, 0);
    for (long long i = 0; i < D; i++)
    {
        long long t = 0, x = v2xy[i][0], y = v2xy[i][1];
        for (long long j = 0; j * D + i < H * W; j++)
        {
            t += abs(v2xy[j * D + i][0] - x) + abs(v2xy[j * D + i][1] - y);
            x = v2xy[j * D + i][0];
            y = v2xy[j * D + i][1];
            R2L[j * D + i] = t;
        }
    }

    for (long long i = 0; i < Q; i++)
    {
        long long L, R;
        cin >> L >> R;
        L--;
        R--;
        cout << R2L[R] - R2L[L] << endl;
    }
}