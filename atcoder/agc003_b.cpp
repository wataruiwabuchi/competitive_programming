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
    vector<long long> A;

    cin >> N;
    for(long long i = 0; i < N; i++){
        long long t;
        cin >> t;
        A.push_back(t);
    }

    A.push_back(0);

    long long c = 0;
    for(long long i = 0; i < N; i++){
        c += A[i] / 2;
        if(A[i] % 2 == 1 && A[i+1] > 0){
            A[i+1]--;
            c++;
        }
    }

    cout << c << endl;
}