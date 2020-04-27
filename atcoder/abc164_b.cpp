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
    long long A, B, C, D;
    cin >> A >> B >> C >> D;

    while(true){
        C -= B;
        if(C <= 0){
            cout << "Yes" << endl;
            return 0;
        }
        A -= D;
        if(A <= 0){
            cout << "No" << endl;
            return 0;
        }
    }
}