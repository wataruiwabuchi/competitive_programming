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
    long long s = 0;
    vector<long long> A;

    cin >> N >> M;
    for (long long i = 0; i < N; i++)
    {
        long long t;
        cin >> t;
        A.push_back(t);
        s += t;
    }

    long long c = 0;
    for (long long i = 0; i < N; i++)
        if ((double)A[i] >= (double)s / (4 * M))
            c++;

    if (c >= M)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}