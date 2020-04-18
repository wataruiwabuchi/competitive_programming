#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
#define MOD int(1e9 + 7)

int main()
{
    long long N;

    cin >> N;
    vector<vector<long long>> v2v(N, vector<long long>{});
    for (long long i = 0; i < N - 1; i++)
    {
        long long a, b;
        cin >> a >> b;
        a--;
        b--;
        v2v[a].push_back(b);
        v2v[b].push_back(a);
    }

    vector<long long> r(N, -1);
    r[0] = 0;
    queue<long long> q;
    q.push(0);
    while (q.size() > 0)
    {
        long long t = q.front();
        q.pop();

        if (t == N - 1)
            break;

        for (auto x : v2v[t])
        {
            if (r[x] == -1)
            {
                r[x] = t;
                q.push(x);
            }
        }
    }

    vector<long long> path;
    long long c = N - 1;
    while (true)
    {
        if (c == 0)
            break;

        path.push_back(c);
        c = r[c];
    }

    vector<long long> r2(N, -1);
    queue<long long> q2;
    long long count = 0;
    r2[0] = 0;
    r2[path[(path.size() + 1) / 2 - 1]] = -2;
    q2.push(0);
    while (q2.size() > 0)
    {
        long long t = q2.front();
        q2.pop();

        if (t == N - 1)
            break;

        count++;

        for (auto x : v2v[t])
        {
            if (r2[x] == -1 && r2[x] != -2)
            {
                r2[x] = t;
                q2.push(x);
            }
        }
    }

    if (N - count == count)
        cout << "Snuke" << endl;
    else if (N - count < count)
        cout << "Fennec" << endl;
    else
        cout << "Snuke" << endl;
}