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
    int N;
    cin >> N;

    if(N / 100 == 7 || (N % 100) / 10 == 7 || (N % 10) == 7)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}