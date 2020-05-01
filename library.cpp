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

long long mod_pow(long long _x, long long _n)
{
    long long ret = 1;
    while (0 < _n)
    {
        if ((_n % 2) == 0)
        {
            _x = (_x * _x) % MOD;
            _n >>= 1;
        }
        else
        {
            ret = (ret * _x) % MOD;
            --_n;
        }
    }
    return ret;
}

// mod. m での a の逆元 a^{-1} を計算する
long long modinv(long long a, long long m)
{
    long long b = m, u = 1, v = 0;
    while (b)
    {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0)
        u += m;
    return u;
}

// 日付計算のためのクラス
class Date
{
private:
    int year, month, day;
    int lastday_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool JudgeLeapYear(int y)
    {
        if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
            return true;
        return false;
    }

public:
    Date(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }

    void Add(int dy, int dm, int dd)
    {
        year += dy + (month + dm - 1) / 12;
        month = (month + dm - 1) % 12 + 1;
        day += dd;

        int lastday = lastday_of_month[month - 1];
        lastday += (month == 2) * JudgeLeapYear(year);
        while (day > lastday)
        {
            dd = dd - (lastday - day) - 1;
            day = 1;
            year += (month + 1) / 13;
            month = (month + 1) % 13 + (month + 1) / 13;

            lastday = lastday_of_month[month - 1];
            lastday += (month == 2) * JudgeLeapYear(year);
        }
    }

    int Year() { return year; }

    int Month() { return month; }

    int Day() { return day; }
};
