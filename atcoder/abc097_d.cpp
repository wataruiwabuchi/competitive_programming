#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <iterator>
using namespace std;
#define MOD int(1e9 + 7)

struct UnionFind
{
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N)
    { //最初は全てが根であるとして初期化
        for (int i = 0; i < N; i++)
            par[i] = i;
    }

    int root(int x)
    { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y)
    {                     // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry)
            return;   //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y)
    { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main()
{
    long long N, M;
    vector<long long> P;
    vector<vector<long long>> XY;

    cin >> N >> M;
    for (long long i = 0; i < N; i++)
    {
        long long t;
        cin >> t;
        t--;
        P.push_back(t);
    }
    for (long long i = 0; i < M; i++)
    {
        long long x, y;
        cin >> x >> y;
        x--;
        y--;
        XY.push_back(vector<long long>{x, y});
    }

    UnionFind uf(N);
    for (long long i = 0; i < M; i++)
        uf.unite(XY[i][0], XY[i][1]);
    for (long long i = 0; i < N; i++)
        uf.root(i);

    vector<vector<long long>> u(N, vector<long long>{});
    for (long long i = 0; i < N; i++)
        u[uf.par[i]].push_back(i);

    long long count = 0;
    for (long long i = 0; i < N; i++)
    {
        vector<long long> t;
        for (auto x : u[i])
            t.push_back(P[x]);
        sort(t.begin(), t.end());

        vector<long long> inter;
        set_intersection(t.begin(), t.end(),
                         u[i].begin(), u[i].end(),
                         inserter(inter, inter.end()));

        count += inter.size();
    }

    cout << count << endl;
}