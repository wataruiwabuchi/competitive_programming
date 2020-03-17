class UnionFind:
    def __init__(self, n):
        self.par = [i for i in range(n)]
        self.rank = [0] * (n)

    def find(self, x):
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if self.rank[x] < self.rank[y]:
            self.par[x] = y
        else:
            self.par[y] = x
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

    def same_check(self, x, y):
        return self.find(x) == self.find(y)
    
    
class BIT:
    def __init__(self, n):
        self.state = [0] * (n + 1)
        
    def update(self, i, x): # state[i] += x
        while i <= n:
            self.state[i] += x
            i += i & (-i)
        return
        
    def query(self, i):
        t = 0
        while i > 0:
            t += self.state[i]
            i -= i & (-i)
        return t


# 区間に対する和を実装したBIT
class BIT_LR:
    def __init__(self, n):
        self.bit0 = BIT(n)
        self.bit1 = BIT(n)
        
    def update(self, l, r, x): # state[i] += x
        self.bit0.update(l, -x * (l - 1))
        self.bit1.update(l, x)
        self.bit0.update(r + 1, x * r)
        self.bit1.update(r + 1, -x)
        return
        
    def query(self, i):
        return self.bit0.query(i) + self.bit1.query(i) * i

    
# mod. m での a の逆元 a^{-1} を計算する
# b * a^{-1} (mod m)を計算したい場合はb * modinv(a, m) % m
def modinv(a, m):
    b = m
    u = 1
    v = 0
    while b:
        t = int(a / b)
        a -= t * b
        a, b = b, a
        u -= t * v
        u, v = v, u
    u %= m
    if u < 0:
        u += m
    return u


# 高速な累乗計算
def pow_k(x, n):
    """
    O(log n)
    """
    if n == 0:
        return 1

    K = 1
    while n > 1:
        if n % 2 != 0:
            K *= x
        x *= x
        n //= 2

    return K * x
    
    
# 途中計算でmodを計算する高速な累乗計算
def pow_k_mod(x, n, m):
    """
    O(log n)
    """
    if n == 0:
        return 1

    K = 1
    while n > 1:
        if n % 2 != 0:
            K *= x
            K %= m
        x *= x
        x %= m
        n //= 2

    return (K * x) % m


# nを素因数分解
# 各素因数を数え上げる場合はcounterを使うとよい
def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a
