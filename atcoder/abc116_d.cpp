#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <functional>
using namespace std;
#define MOD int(1e9 + 7)

int main()
{
    long long N, K;
    vector<vector<long long>> TD;

    cin >> N >> K;
    for (long long i = 0; i < N; i++)
    {
        long long t, d;
        cin >> t >> d;
        TD.push_back(vector<long long>{t, d});
    }

    sort(TD.begin(), TD.end(), [](const vector<long long> &x, const vector<long long> &y) { return x[1] > y[1]; });

    set<long long> t, idx;
    vector<long long> v;
    priority_queue<
        long long,
        vector<long long>,
        greater<long long>>
        q;
    long long total = 0;
    for (long long i = 0; i < N; i++)
    {
        if (t.find(TD[i][0]) == t.end())
        {
            t.insert(TD[i][0]);
            total += TD[i][1];
            idx.insert(i);
            q.push(TD[i][1]);

            if (idx.size() >= K)
                break;
        }
    }

    for (long long i = 0; idx.size() < K; i++)
    {
        if (idx.find(i) == idx.end())
        {
            idx.insert(i);
            total += TD[i][1];
            q.push(TD[i][1]);
        }
    }

    long long count = t.size();
    for (long long i = 0; i < N; i++)
    {
        if (idx.find(i) == idx.end())
        {
            if (total + count * count < total - q.top() + TD[i][1] + (count - 1) * (count - 1))
            {
                total = total - q.top() + TD[i][1];
                count--;
                q.pop();
            }
        }
    }

    cout << total + count * count << endl;
}