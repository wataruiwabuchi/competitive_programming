#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
#define MOD int(1e9+7)

int main()
{
    string S;
    vector<vector<long long>> mod(2, vector<long long>(13, 0));
    cin >> S;

    if (S[S.size() - 1] == '?')
    {
        for (long long j = 0; j < 10; j++)
            mod[(S.size() - 1) % 2][j] = 1;
    }
    else
        mod[(S.size() - 1) % 2][(int)(S[S.size() - 1]) - (int)('0')] = 1;

    long long ketamod = 1;
    if (S.size() >= 2)
    {
        for (long long i = S.size() - 2; i >= 0; i--)
        {
            ketamod = (ketamod * 10) % 13;
            if (S[i] == '?')
            {
                for (long long j = 0; j < 13; j++)
                    mod[i % 2][j] = 0;

                for (long long j = 0; j < 10; j++)
                    for (long long k = 0; k < 13; k++)
                        mod[i % 2][(k + j * ketamod) % 13] += mod[(i + 1) % 2][k];
            }
            else
            {
                for (long long k = 0; k < 13; k++)
                    mod[i % 2][(k + ((int)(S[i]) - (int)('0')) * ketamod) % 13] = mod[(i + 1) % 2][k];
            }

            for (long long j = 0; j < 13; j++)
                mod[i % 2][j] %= MOD;
        }
    }

    cout << mod[0][5] << endl;
}