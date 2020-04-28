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
    string S;
    cin >> S;

    long long count = 0;
    for (long long i = 0; i < S.size(); i++)
    {
        if ((S.size() + 1) / 2 > i)
        {
            if (S[i] == 'p')
                count--;
        }
        else if (S[i] == 'g')
            count++;
    }

    cout << count << endl;
}