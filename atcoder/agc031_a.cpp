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
    vector<long long> c(26, 1);

    cin >> N;
    for(long long i = 0; i < N; i++){
        char t;
        cin >> t;
        c[t - 'a']++;
    }

    long long total = 1;
    for(long long i = 0; i < 26; i++){
        total *=  c[i];
        total %= MOD;
    }

    cout << total - 1 << endl;
}