#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <climits>
using namespace std;
#define MOD int(1e9 + 7)
#define INF (long long)(1e18)

int main()
{
    cout.precision(18);

    string S;
    cin >> S;

    long long min_v = INF;
    string min_s;
    for (auto m : {'S', 'H', 'D', 'C'})
    {
        long long i = 0;
        string cs = "";
        long long c = 0;
        while (i < S.size())
        {
            if (S[i] == m)
            {
                switch (S[i + 1])
                {
                case '1':
                    i++;
                case 'A':
                case 'J':
                case 'Q':
                case 'K':
                    c++;
                    break;
                default:
                    cs += S[i];
                    cs += S[i + 1];
                    break;
                }

                if (c == 5 && min_v > i)
                {
                    min_s = cs;
                    min_v = i;
                    break;
                }
            }
            else
            {
                cs += S[i];
                cs += S[i + 1];
                if (S[i + 1] == '1')
                {
                    cs += S[i + 2];
                    i++;
                }
            }

            i += 2;
        }
    }

    if (min_s.size() == 0)
        cout << 0 << endl;
    else
        cout << min_s << endl;
}