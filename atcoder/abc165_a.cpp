#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <climits>
using namespace std;
#define MOD int(1e9 + 7)
#define INF (long long)(1e18)

int main()
{
    cout.precision(18);

    long long K;
    long long X, Y;

    cin >> K;
    cin >> X >> Y;

    for(long long i = X; i < Y + 1; i++){
        if(i % K == 0){
            cout << "OK" << endl;
            return 0;
        }
    }

    cout << "NG" << endl;
}