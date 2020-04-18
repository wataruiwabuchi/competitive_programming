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
    long long N, A;
    cin >> N >> A;

    if(N % 500 <= A)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}