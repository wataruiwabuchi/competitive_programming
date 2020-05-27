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
  long long N, M, S, T;
  cin >> N >> M >> S >> T;

  vector<vector<long long>> d(N, vector<long long>(N, INF));
  for(long long i = 0; i < N; i++)
    d[i][i] = 0;
  for(long long i = 0; i < M; i++){
    long long a, b, c;
    cin >> a >> b >> c;
    d[a - 1][b - 1] = c;
    d[b - 1][a - 1] = c;
  }

  warshall_floyd(N, d);

  for( long long i = 0; i < N; i++ ){
    if(d[S - 1][i] == d[T - 1][i] && d[S - 1][i] != INF){
      cout << i + 1 << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;

}
