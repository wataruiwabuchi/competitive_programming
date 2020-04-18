#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <climits>
using namespace std;
#define MOD int(1e9 + 7)

int main()
{
    long long N, K;
    vector<vector<long long>> XY;

    cin >> N >> K;
    for (long long i = 0; i < N; i++)
    {
        long long x, y;
        cin >> x >> y;
        XY.push_back(vector<long long>{x, y});
    }

    long long min_area = LLONG_MAX;
    for (long long i = 0; i < N; i++)
    {
        for (long long j = 0; j < N; j++)
        {
            long long min_x = min(XY[i][0], XY[j][0]);
            long long max_x = max(XY[i][0], XY[j][0]);
            for (long long k = 0; k < N; k++)
            {
                for (long long l = 0; l < N; l++)
                {
                    if (i != j && k != l)
                    {
                        long long count = 0;
                        long long min_y = min(XY[k][1], XY[k][1]);
                        long long max_y = max(XY[l][1], XY[l][1]);
                        for (long long m = 0; m < N; m++)
                            if (XY[m][0] >= min_x && XY[m][0] <= max_x)
                                if (XY[m][1] >= min_y && XY[m][1] <= max_y)
                                    count++;
                        if (count >= K)
                            min_area = min(min_area, (max_x - min_x) * (max_y - min_y));
                    }
                }
            }
        }
    }

    cout << min_area << endl;
}