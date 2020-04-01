#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;
#define MOD int(1e9 + 7)

int main()
{
    vector<vector<int>> c2i(26, vector<int>());
    string S, T;
    cin >> S;
    cin >> T;

    for (int i = 0; i < S.size(); i++)
        c2i[S[i] - 'a'].push_back(i);

    //for (auto is : c2i)
    //{
    //    for (auto i : is)
    //        cout << i << " ";
    //    cout << endl;
    //}

    int cur = 0, count = 0;
    int ci;
    int insertedIdx;
    for (int i = 0; i < T.size(); i++)
    {
        ci = T[i] - 'a';
        insertedIdx = lower_bound(c2i[ci].begin(), c2i[ci].end(), cur) - c2i[ci].begin();

        if (c2i[ci].size() == 0)
        {
            cout << -1 << endl;
            return 0;
        }

        if (insertedIdx == c2i[ci].size() || c2i[ci][insertedIdx] < cur)
        {
            count++;
            cur = c2i[ci][0] + 1;
        }
        else
            cur = c2i[ci][insertedIdx] + 1;
    }

    cout << count * S.size() + cur << endl;
}