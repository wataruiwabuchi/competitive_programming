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
    long long N;

    cin >> S;
    cin >> N;
    for (long long i = 0; i < S.size(); i++)
    {
        if (S[i] != 'a' && N >= 26 - (S[i] - 'a'))
        {
            N -= (26 - (S[i] - 'a'));
            S[i] = 'a';
        }
    }

    S[S.size() - 1] = (S[S.size() - 1] - 'a' + N) % 26 + 'a';

    cout << S << endl;
}