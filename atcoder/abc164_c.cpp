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
#define INF (long long)(1e18)

int main()
{
    long long N;
    set<string> S;

    cin >> N;
    for (long long i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        S.insert(s);
    }

    cout << S.size() << endl;
}