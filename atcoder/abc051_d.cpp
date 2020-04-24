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

void warshall_floyd(int n, vector<vector<long long>>& d) {
  for (int k = 0; k < n; k++){       // 経由する頂点
    for (int i = 0; i < n; i++) {    // 始点
      for (int j = 0; j < n; j++) {  // 終点
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

int main()
{
    long long N, M;
    cin >> N >> M;

    vector<vector<long long>> E(N, vector<long long>(N, INF));
    vector<vector<long long>> d(N, vector<long long>(N, INF));
    for(long long i = 0; i < M; i++){
        long long a, b, c;
        cin >> a >> b >> c;
        E[a-1][b-1] = c;
        E[b-1][a-1] = c;
        d[a-1][b-1] = c;
        d[b-1][a-1] = c;
    }

    for(long long i = 0; i < N; i++){
        E[i][i] = 0;
        d[i][i] = 0;
    }

    warshall_floyd(N, d);

    long long count = 0;
    for(long long i = 0; i < N; i++)
        for(long long j = i + 1; j < N; j++)
            if(E[i][j] != INF && E[i][j] != d[i][j])
                count++;

    cout << count << endl;

}