#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i=a; i < (b); ++i)
#define trav(a, x) for(auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;

template <class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const {return tie (x, y) < tie(p.x, p.y); }
    bool operator==(P p) const {return tie(x,y)==tie(p.x,p.y); }
    P operator+(P p) const {return P(x+p.x, y+p.y); }
    P operator-(P p) const {return P(x-p.x, y-p.y); }
    P operator*(T d) const {return P(x*d, y*d); }
    P operator/(T d) const {return P(x/d, y/d); }
    T dot(P p) const {return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
    T dist2() const {return x*x + y*y; }
    double dist() const {return sqrt((double) dist2()); }
    // angulo va entre pi y -pi incl.
    double angle() const {return atan2(y, x); }
    P unit() const { return *this/dist(); } // makes dist = 1
    P perp() const { return P(-y, x); } // rota + 90 grados
    P normal() const {return perp().unit(); }
    // regresa el punto a rotado 'a' radianes antihorariamente con respecto al origen
    P rotate(double a) const {
        return P(x*cos(a) - y*sin(a), x*sin(a)+y*cos(a)); }
};

typedef Point<ll> P;
pair<vi, vi> ulHull(const vector <P> &S) {
    vi Q(sz(S)), U, L;
    iota(all(Q), 0);
    sort(all(Q), [&S](int a, int b) { return S[a] < S[b]; }) ;
    trav(it, Q) {
#define ADDP(C, cmp) while(sz(C) > 1 && S[C[sz(C)-2]].cross(\
    S[it], S[C.back()]) cmp 0) C.pop_back(); C.push_back(it);
    ADDP(U, <=); ADDP(L, >=);
    }
    return {U, L};
}

vi convexHull(const vector <P> &S) {
    vi u, l; tie(u, l) = ulHull(S);
    if (sz(S) <= 1) return u;
    if (S[u[0]] == S[u[1]]) return {0};
    l.insert(l.end(), u.rbegin()+1, u.rend()-1);
    return l;
}

double dist_ln(P &a, P &b, P &p) {
    return (double)(b-a).cross(p-a)/(b-a).dist();
}

int N, X, Y;
vector <P> L, NL;
vector <int> ch;
double ANS = 1e20;

int main() {
    scanf("%d", &N);
    L.resize(N);

    for(int i=0;i<N;i++) {
        scanf("%d %d", &X, &Y);
        L[i] = P(X, Y);
    }

    ch = convexHull(L);
    for(int c : ch)
        NL.push_back(L[c]);

    N = NL.size();

    for(int i=0;i<N;i++) {
        P a = NL[i], b = NL[(i + 1) % N];

        double NANS = 0.0;

        for(int k=0;k<N;k++) {
            if(k == i || k == ((i + 1) % N)) continue;
            P c = NL[k];
            double d = dist_ln(a, b, c);
            NANS = max(NANS, d);
        }

        ANS = min(ANS, NANS);
    }

    printf("%.7lf\n", ANS);

    return 0;
}
