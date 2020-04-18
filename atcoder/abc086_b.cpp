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
    string A, B;
    cin >> A >> B;

    if (stol(A + B) == long(pow(double(long(sqrt(stod(A + B)))), 2)))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}