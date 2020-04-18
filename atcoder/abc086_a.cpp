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
    long long A, B;
    cin >> A >> B;

    if(A * B % 2 == 0)
        cout << "Even" << endl;
    else
        cout << "Odd" << endl;
}