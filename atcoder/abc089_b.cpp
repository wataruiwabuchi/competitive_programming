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
    set<string> S;

    cin >> N;
    for(long long i = 0; i < N; i++){
        string t;
        cin >> t;
        S.insert(t);
    }

    if(S.size() == 3)
        cout << "Three" << endl;
    else
        cout << "Four" << endl;

}