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
    long long H, W, A, B;
    cin >> H >> W >> A >> B;

    vector<vector<bool>> m(H, vector<bool>(W, 0));
    for(long long i = 0; i < A; i++)
        for(long long j = 0; j < B; j++)
            m[j][i] = 1;

    for(long long i = A; i < W; i++)
        for(long long j = B; j < H; j++)
            m[j][i] = 1;


    for(long long i = 0; i < H; i++){
        long long c = 0;
        for(long long j = 0; j < W; j++){
            if(m[i][j])
                c++;
        }
        if(min(c, W - c) != A){
            cout << "No" << endl;
            return 0;
        }
    }

    for(long long i = 0; i < W; i++){
        long long c = 0;
        for(long long j = 0; j < H; j++){
            if(m[j][i])
                c++;
        }
        if(min(c, H - c) != B){
            cout << "No" << endl;
            return 0;
        }
    }

    for(long long i = 0; i < H; i++){
        for(long long j = 0; j < W; j++){
            cout << m[i][j];
        }
        cout << endl;
    }

}