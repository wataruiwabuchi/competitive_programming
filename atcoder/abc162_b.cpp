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
    cin >> N;

    long long total = 0;
    for(long long i = 0; i < N + 1; i++)
        if(i % 3 != 0 && i % 5 != 0)
            total += i;

    cout << total << endl;
}