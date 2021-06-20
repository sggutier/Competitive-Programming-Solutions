#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <class T, int N> struct Matrix {
    typedef Matrix M;
    array<array<T, N>, N> d{};
    M operator*(const M& m) const {
        M a;
        rep(i,0,N) rep(j,0,N)
            rep(k,0,N) a.d[i][j] |= d[i][k] & m.d[k][j];
        return a;
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
void testCase(int E) {
    Matrix<int, N> mat ;
    int ini, fin, s ;
    for(int i=0, a, b; i < E; i++) {
        scanf("%d%d", &a, &b);
        a--, b--;
        mat.d[a][b] = mat.d[b][a] = 1 ;
    }
    scanf("%d%d%d", &ini, &fin, &s);
    ini--, fin--;
    mat = mat^s;
    puts(mat.d[ini][fin]? "Yes, Teobaldo can travel." : "No, Teobaldo can not travel.");
}

int main() {
    function<void(int)> funcs[] = {testCase<1>, testCase<2>, testCase<3>, testCase<4>, testCase<5>, testCase<6>, testCase<7>, testCase<8>, testCase<9>, testCase<10>, testCase<11>, testCase<12>, testCase<13>, testCase<14>, testCase<15>, testCase<16>, testCase<17>, testCase<18>, testCase<19>, testCase<20>, testCase<21>, testCase<22>, testCase<23>, testCase<24>, testCase<25>, testCase<26>, testCase<27>, testCase<28>, testCase<29>, testCase<30>, testCase<31>, testCase<32>, testCase<33>, testCase<34>, testCase<35>, testCase<36>, testCase<37>, testCase<38>, testCase<39>, testCase<40>, testCase<41>, testCase<42>, testCase<43>, testCase<44>, testCase<45>, testCase<46>, testCase<47>, testCase<48>, testCase<49>, testCase<50>, testCase<51>, testCase<52>, testCase<53>, testCase<54>, testCase<55>, testCase<56>, testCase<57>, testCase<58>, testCase<59>, testCase<60>, testCase<61>, testCase<62>, testCase<63>, testCase<64>, testCase<65>, testCase<66>, testCase<67>, testCase<68>, testCase<69>, testCase<70>, testCase<71>, testCase<72>, testCase<73>, testCase<74>, testCase<75>, testCase<76>, testCase<77>, testCase<78>, testCase<79>, testCase<80>, testCase<81>, testCase<82>, testCase<83>, testCase<84>, testCase<85>, testCase<86>, testCase<87>, testCase<88>, testCase<89>, testCase<90>, testCase<91>, testCase<92>, testCase<93>, testCase<94>, testCase<95>, testCase<96>, testCase<97>, testCase<98>, testCase<99>, testCase<100>};
    int N, E ;
    while(scanf("%d%d", &N, &E) && N) {
        funcs[N-1](E);
    }
}
