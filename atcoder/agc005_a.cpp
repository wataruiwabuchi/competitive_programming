#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
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
    string S;
    cin >> S;

    stack<char> s;
    s.push('T');
    long long count = 0;
    for (long long i = 0; i < S.size(); i++)
    {
        if (S[i] == 'S')
            s.push('S');
        else
        {
            if (s.top() == 'S')
            {
                count += 2;
                s.pop();
            }
            else
                s.push('T');
        }
    }

    cout << S.size() - count << endl;
}