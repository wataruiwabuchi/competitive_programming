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
    long long N, M;
    vector<vector<long long>> A;

    cin >> N >> M;
    for (long long i = 0; i < N; i++)
    {
        vector<long long> tmp;
        for (long long j = 0; j < 3; j++)
        {
            long long t;
            cin >> t;
            tmp.push_back(t);
        }
        A.push_back(tmp);
    }

    long long max_v = 0;
    for (long long i = -1; i <= 1; i += 2)
    {
        for (long long j = -1; j <= 1; j += 2)
        {
            for (long long k = -1; k <= 1; k += 2)
            {
                vector<vector<vector<long long>>> dp(N + 1, vector<vector<long long>>(M + 1, vector<long long>(3, 0)));
                for (long long l = 1; l < N + 1; l++)
                {
                    for (long long m = 1; m <= M; m++)
                    {
                        long long eat_v = 0;
                        long long neat_v = 0;
                        eat_v += i * (dp[l - 1][m - 1][0] + A[l - 1][0]);
                        eat_v += j * (dp[l - 1][m - 1][1] + A[l - 1][1]);
                        eat_v += k * (dp[l - 1][m - 1][2] + A[l - 1][2]);
                        neat_v += i * (dp[l - 1][m][0]);
                        neat_v += j * (dp[l - 1][m][1]);
                        neat_v += k * (dp[l - 1][m][2]);

                        if (l == m || eat_v > neat_v)
                            for (long long n = 0; n < 3; n++)
                                dp[l][m][n] = dp[l - 1][m - 1][n] + A[l - 1][n];
                        else
                            for (long long n = 0; n < 3; n++)
                                dp[l][m][n] = dp[l - 1][m][n];
                    }
                }
                max_v = max(max_v, i * dp[N][M][0] + j * dp[N][M][1] + k * dp[N][M][2]);
            }
        }
    }

    cout << max_v << endl;
}