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
    long long A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    A *= 100;
    B *= 100;

    // ありえる水の量を列挙
    set<int> w;
    for (int i = 0; i <= F / A; i++)
        for (int j = 0; j <= F / B; j++)
            if (i * A + j * B <= F && i * A + j * B != 0)
                w.insert(i * A + j * B);

    double m = 0, ms = 0, mw = A;
    for (auto x : w)
    {
        for (int i = 0; i <= min((x / 100 * E) / C, (F - x) / C); i++)
        {
            int sugar = i * C + min((x / 100 * E - i * C) / D * D, (F - x - i * C) / D * D);
            double noudo = (double)sugar / (x + sugar);
            if (noudo > m)
            {
                m = noudo;
                ms = sugar;
                mw = x;
            }
        }
    }

    cout << ms + mw << ' ' << ms << endl;
}