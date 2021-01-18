#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int MOD ;

template <class T, int N> struct Matrix {
    typedef Matrix M;
    array<array<T, N>, N> d{};
    M operator*(const M& m) const {
        M a;
        rep(i,0,N) rep(j,0,N)
            rep(k,0,N) a.d[i][j] = (a.d[i][j] + d[i][k]*m.d[k][j]) % MOD;
        return a;
    }
    vector<T> operator*(const vector<T>& vec) const {
        vector<T> ret(N);
        rep(i,0,N) rep(j,0,N) ret[i] = (ret[i] + d[i][j] * vec[j]) % MOD;
        return ret;
    }
    M operator^(ll p) const {
        assert(p >= 0);
        M a, b(*this);
        rep(i,0,N) a.d[i][i] = 1;
        while (p) {
            if (p&1) a = a*b;
            b = b*b;
            p >>= 1;
        }
        return a;
    }
};

template <int N>
void testCase(int p) {
    Matrix<int, N> mat ;
    vector <int> bas(N);
    for(int i=0; i + 1 < N; i++)
        mat.d[i][i+1] = 1 ;
    for(int i=N-1; i >= 0; i--) {
        scanf("%d", &mat.d[N-1][i]);
        mat.d[N-1][i] %= MOD;
    }
    for(int i=0; i < N; i++) {
        scanf("%d", &bas[i]);
        bas[i] %= MOD;
    }
    if(MOD == 1) {
        printf("0\n");
    }
    else {
        printf("%d\n", ((mat^(p-1))*bas)[0]);
    }
}


int main() {
    function<void(int)> funcs[] = {testCase<1>, testCase<2>, testCase<3>, testCase<4>, testCase<5>, testCase<6>, testCase<7>, testCase<8>, testCase<9>, testCase<10>, testCase<11>, testCase<12>, testCase<13>, testCase<14>, testCase<15>};
    int N, p ;
    while(scanf("%d%d%d", &N, &p, &MOD)!=EOF && MOD) {
        funcs[N-1](p);
    }
}
