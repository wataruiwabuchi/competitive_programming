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
    long long N;
    string S;

    cin >> N;
    cin >> S;

    vector<vector<long long>> ids(3, vector<long long>{});
    for (long long i = 0; i < N; i++)
    {
        if (S[i] == 'R')
            ids[0].push_back(i);
        else if (S[i] == 'G')
            ids[1].push_back(i);
        else
            ids[2].push_back(i);
    }

    long long count = 0;
    for (long long i = 0; i < N - 2; i++)
    {
        for (long long j = i; j < N - 1; j++)
        {
            if (S[i] != S[j])
            {
                if ((S[i] == 'R' && S[j] == 'G') || (S[i] == 'G' && S[j] == 'R'))
                {
                    long long d = lower_bound(ids[2].begin(), ids[2].end(), j) - ids[2].begin();
                    count += ids[2].size() - d;
                    if (j - i + j < N && S[j - i + j] == 'B')
                        count--;
                }
                else if ((S[i] == 'R' && S[j] == 'B') || (S[i] == 'B' && S[j] == 'R'))
                {
                    long long d = lower_bound(ids[1].begin(), ids[1].end(), j) - ids[1].begin();
                    count += ids[1].size() - d;
                    if (j - i + j < N && S[j - i + j] == 'G')
                        count--;
                }
                else if ((S[i] == 'G' && S[j] == 'B') || (S[i] == 'B' && S[j] == 'G'))
                {
                    long long d = lower_bound(ids[0].begin(), ids[0].end(), j) - ids[0].begin();
                    count += ids[0].size() - d;
                    if (j - i + j < N && S[j - i + j] == 'R')
                        count--;
                }
            }
        }
    }
    cout << count << endl;
}