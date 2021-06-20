#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Frac {
    ll num, den ;
    Frac(ll _num=0, ll _den=1) : num(_num), den(_den) {
        if(den < 0) {
            num *= -1;
            den *= -1;
        }
        assert(den != 0LL);
        ll g = __gcd(abs(num), den);
        num /= g ;
        den /= g ;
    }
    Frac operator+(const Frac &b) const {
        return Frac(num*b.den + b.num*den, den * b.den);
    }
    Frac operator-(const Frac &b) const {
        return Frac(num*b.den - b.num*den, den * b.den);
    }
    Frac operator*(const Frac &b) const {
        return Frac(num * b.num, den * b.den);
    }
    Frac operator/(const Frac &b) const {
        return Frac(num*b.den, den * b.num);
    }
    bool operator>(const Frac &b) const {
        return num * b.den > b.num * den;
    }
};

Frac abs(const Frac &a) {
    return Frac(abs(a.num), a.den);
}

typedef vector<Frac> vF;
Frac eps = 0 ;

int solveLinear(vector<vF>& A, vF& b, vF& x) {
    int n = sz(A), m = sz(x), rank = 0, br, bc;
    if (n) assert(sz(A[0]) == m);
    vi col(m); iota(all(col), 0);

    rep(i,0,n) {
        Frac v, bv = 0;
        rep(r,i,n) rep(c,i,m)
            if ((v = abs(A[r][c])) > bv)
                br = r, bc = c, bv = v;
        if (bv.num == 0) {
            rep(j,i,n) if (abs(b[j]) > eps) return -1;
            break;
        }
        swap(A[i], A[br]);
        swap(b[i], b[br]);
        swap(col[i], col[bc]);
        rep(j,0,n) swap(A[j][i], A[j][bc]);
        bv = Frac(1)/A[i][i];
        rep(j,i+1,n) {
            Frac fac = A[j][i] * bv;
            b[j] = b[j] - fac * b[i];
            rep(k,i+1,m) A[j][k] = A[j][k] - fac*A[i][k];
        }
        rank++;
    }

    x.assign(m, 0);
    for (int i = rank; i--;) {
        b[i] = b[i] / A[i][i];
        x[col[i]] = b[i];
        rep(j,0,i) b[j] = b[j] - A[j][i] * b[i];
    }
    return rank; // (multiple solutions if rank < m)
}

int getNum(ll &x) {
    int c ;
    bool neg = false;
    while( (c = getchar()) != EOF && !isdigit(c) ) {
        if(c == '-')
            neg = true;
    }
    x = c - '0';
    while( (c = getchar()) != EOF && isdigit(c) ) {
        x = x*10 + c - '0';
    }
    if(neg)
        x *= -1;
    return c ;
}


Frac getFrac() {
    ll x, y ;
    int c = getNum(x);
    if(c != '/') {
        // printf("F: %lld\n", x);
        return Frac(x, 1);
    }
    // printf("F: %lld / %lld\n", x, y);
    getNum(y);
    return Frac(x, y);
}


void testCase() {
    ll M, N ;
    vector <vF> A ;
    vF b, x;

    getNum(M);
    getNum(N);
    // printf("TC: %lld %lld\n", M, N );
    A.resize(N);
    b.resize(N);
    x.resize(M);
    for(int i=0; i < N; i++) {
        A[i].resize(M);
        for(int j=0; j < M; j++) {
            A[i][j] = getFrac();
        }
        b[i] = getFrac();
    }

    int r = solveLinear(A, b, x);
    // int r = 0 ;

    if(r == -1) {
        printf("No Solution.\n");
        return ;
    }
    else if(r < M) {
        printf("Infinitely many solutions containing %lld arbitrary constants.\n", M - r);
        return ;
    }

    for(int i=0; i < M; i++) {
        printf("x[%d] = %lld", i+1, x[i].num);
        if(x[i].den != 1)
            printf("/%lld", x[i].den);
        printf("\n");
    }
}


int main() {
    ll tc ;
    bool fst = true;
    while(getNum(tc) != EOF && tc) {
        if(!fst)
            printf("\n");
        fst = false;
        printf("Solution for Matrix System # %lld\n", tc);
        testCase();
    }
}
