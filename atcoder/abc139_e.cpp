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
    int N, count;
    vector<vector<int>> A;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        vector<int> t;
        for (int j = 0; j < N - 1; j++)
        {
            int tmp;
            cin >> tmp;
            t.push_back(tmp);
        }
        A.push_back(t);
    }

    vector<int> ids(N, N - 2);
    set<int> check;
    for(int i = 0; i < N; i++)
        check.insert(i);
    count = 0;
    while (true)
    {
        //vector<int> update;
        set<int> update;
        //for (int i = 0; i < N; i++)
        for (auto i : check)
            if (ids[i] >= 0 && A[A[i][ids[i]] - 1][ids[A[i][ids[i]] - 1]] - 1 == i){
                update.insert(i);
                update.insert(A[i][ids[i]] - 1);
            }

        for(auto x : update)
            ids[x]--;

        if (update.size() == 0)
            break;

        check = update;

        count++;
    }

    bool f = false;
    for (int i = 0; i < N; i++)
        if (ids[i] != -1)
            f = true;
    if (f == true)
        cout << -1 << endl;
    else
        cout << count << endl;
}