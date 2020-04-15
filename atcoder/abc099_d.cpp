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
    long long N, C;
    vector<vector<long long>> D;
    vector<vector<long long>> A;

    cin >> N >> C;
    for (long long i = 0; i < C; i++)
    {
        vector<long long> t1;
        for (long long j = 0; j < C; j++)
        {
            long long t2;
            cin >> t2;
            t1.push_back(t2);
        }
        D.push_back(t1);
    }
    for (long long i = 0; i < N; i++)
    {
        vector<long long> t1;
        for (long long j = 0; j < N; j++)
        {
            long long t2;
            cin >> t2;
            t1.push_back(t2 - 1);
        }
        A.push_back(t1);
    }

    vector<vector<long long>> t(3, vector<long long>(C, 0));
    for (long long i = 0; i < C; i++)
        for (long long j = 0; j < N; j++)
            for (long long k = 0; k < N; k++)
                t[(j + k + 2) % 3][i] += D[A[j][k]][i];

    long long mv = MOD;
    for (long long i = 0; i < C; i++)
        for (long long j = 0; j < C; j++)
            for (long long k = 0; k < C; k++)
                if (i != j && j != k && i != k)
                    mv = min(mv, t[0][i] + t[1][j] + t[2][k]);

    cout << mv << endl;
}