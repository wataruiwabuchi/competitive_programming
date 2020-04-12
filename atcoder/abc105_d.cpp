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
    vector<long long> A;

    cin >> N >> M;
    map<long long, long long> count;
    long long tmp = 0;
    count[0]++;
    for(long long i = 0; i < N; i++){
        long long t;
        cin >> t;
        tmp = (tmp + t) % M;
        count[tmp]++;
    }

    long long total = 0;
    for(auto x : count)
        total += (x.second * (x.second - 1)) / 2;

    cout << total << endl;

}