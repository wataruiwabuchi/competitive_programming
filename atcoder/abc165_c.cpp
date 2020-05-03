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

long long N, M, Q;

long long dfs(int i, int v, vector<long long> &A, vector<vector<long long>> &B)
{
    if (v > M)
        return 0;
    if (i == N)
    {
        long long c = 0;
        for (long long j = 0; j < Q; j++)
            if (A[B[j][1] - 1] - A[B[j][0] - 1] == B[j][2])
                c += B[j][3];
        return c;
    }

    long long max_c = 0;
    for (long long j = v; j < M + 1; j++)
    {
        A[i] = j;
        max_c = max(max_c, dfs(i + 1, j, A, B));
    }

    return max_c;
}

int main()
{
    cout.precision(18);

    cin >> N >> M >> Q;

    vector<long long> A(N, 0);
    vector<vector<long long>> B;
    for (long long i = 0; i < Q; i++)
    {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        B.push_back(vector<long long>{a, b, c, d});
    }

    cout << dfs(0, 1, A, B) << endl;
}