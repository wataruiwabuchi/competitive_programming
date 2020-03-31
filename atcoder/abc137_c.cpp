#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
#define MOD int(1e9 + 7)

int main()
{
    int N;
    vector<string> S;
    map<string, long long> mp;
    long long count = 0;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string t;
        cin >> t;
        sort(t.begin(), t.end());

        auto itr = mp.find(t);
        if (itr != mp.end())
            mp[t] += 1;
        else
            mp[t] = 1;
    }

    for (auto itr = mp.begin(); itr != mp.end(); ++itr)
        count += itr->second * (itr->second - 1) / 2;

    cout << count << endl;
}