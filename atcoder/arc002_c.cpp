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

string S;

long long dfs(int i, vector<char> &b)
{
    if (i == 4)
    {
        if (b[3] == b[1] && b[2] == b[0])
            return INF;

        long long j = 0;
        long long c = 0;
        while (j < S.size())
        {
            if (j + 1 < S.size())
            {
                if (S[j] == b[1] && S[j + 1] == b[0])
                    j += 2;
                else if (S[j] == b[3] && S[j + 1] == b[2])
                    j += 2;
                else
                    j++;
            }
            else
                j++;
            c++;
        }

        return c;
    }

    long long min_c = INF;
    for (auto x : vector<char>{'A', 'B', 'X', 'Y'})
    {
        b[i] = x;
        min_c = min(min_c, dfs(i + 1, b));
    }

    return min_c;
}

int main()
{
    cout.precision(18);

    long long N;

    cin >> N;
    cin >> S;

    vector<char> b(4, 0);
    cout << dfs(0, b) << endl;
}