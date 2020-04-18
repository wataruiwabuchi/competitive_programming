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
    long long N;
    vector<long long> A;

    cin >> N;
    for (long long i = 0; i < N; i++)
    {
        long long t;
        cin >> t;
        A.push_back(-t);
    }

    sort(A.begin(), A.end());

    vector<long long> o{0, 0};
    for (long long i = 0; i < N; i++)
        o[i % 2] -= A[i];

    cout << o[0] - o[1] << endl;
}