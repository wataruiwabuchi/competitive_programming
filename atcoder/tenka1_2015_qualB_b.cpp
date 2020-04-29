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

    stack<char> c;
    bool f = false;
    for (long long i = 0; i < S.size(); i++)
    {
        if (c.size() == 1)
        {
            if (S[i] == ':')
            {
                cout << "dict" << endl;
                return 0;
            }
            else if (S[i] == ',')
            {
                cout << "set" << endl;
                return 0;
            }
            else if (S[i] != '}')
                f = true;
        }
        if (S[i] == '}')
            c.pop();
        else if (S[i] == '{')
            c.push('{');
    }

    if (f)
        cout << "set" << endl;
    else
        cout << "dict" << endl;
}