#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int limN = 1e3 + 5;

ll egcd(ll a, ll b, ll &x, ll &y) {
    if(b==0) {
        x = 0;
        y = 1;
        return a;
    }
    else {
        ll res = egcd(b, a%b, x, y), z = x;
        x = y - (a/b) * x;
        y = z;
        return res;
    }
}

struct mi {
    ll n;
    mi() {
    }
    mi(ll n) : n(n) {}
};

mi operator+(mi a, mi b) {
    return ( a.n + b.n )%mod;
}

mi operator-(mi a, mi b) {
    return ( mod + a.n - b.n )%mod;
}

mi operator*(mi a, mi b) {
    return ( a.n * b.n )%mod;
}

mi operator/(mi a, mi b) {
    ll inv, t;
    egcd(mod, b.n, inv, t);
    inv = inv<0? ((mod*mod) + inv)%mod : inv%mod ;
    return (a.n*inv)%mod;
}

mi memoT[limN][limN];
bool udo[limN][limN];
mi p, p2, ct;

mi T(int x, int y) {
    if(y <= 0)
        return mi(0);
    if(udo[x][y])
        return memoT[x][y];
    udo[x][y] = true;
    if(x >= y) {
        return memoT[x][y] = mi(x) + ct;
    }
    mi ans;
    if(x != 0)
        ans = p2*(mi(x) + T(x, y-x));
    else
        ans = mi(0);
    ans = ans + p*T(x+1, y);
    if(x == 0)
        ans = ans * (mi(1) / p);
    return memoT[x][y] = ans;
}

int main() {
    int n, a, b ;
    cin >> n >> a >> b ;
    p = mi(a) / mi(a+b);
    p2 = mi(b) / mi(a+b);
    ct = p/p2;
    mi ans = T(0, n);
    cout << ans.n << endl;
}
