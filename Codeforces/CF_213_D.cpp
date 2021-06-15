#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

template <class T>
struct Point {
    typedef Point P;
    T x, y;
    Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
    // angle to x-axis in interval [-pi, pi]
    double angle() const { return atan2(y, x); }
    P unit() const { return *this/dist(); } // makes dist()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated 'a' radians ccw around the origin
    P rotate(double a) const {
        return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
};

typedef Point <ld> P ;

string baseStrs[5] = {
"3.830127018922193 3.366025403784439",
"-3.601321235851749 10.057331467373021",
"0.466045194906253 19.192786043799030",
"10.411264148588986 18.147501411122495",
"12.490381056766580 8.366025403784439"
};

P base[5] ;

set <int> adj[50000];

void euPath(const int pos) {
    while(!adj[pos].empty()) {
        int nxt = *adj[pos].begin();
        adj[pos].erase(adj[pos].begin());
        adj[nxt].erase(pos);
        euPath(nxt);
    }
    printf("%d ", pos + 1);
}

int main() {
    int N ;
    for(int i=0; i < 5; i++) {
        sscanf(baseStrs[i].c_str(), "%Lf%Lf", &base[i].x, &base[i].y);
        // base[i] = base[i] - base[0];
    }

    scanf("%d", &N);

    printf("%d\n", N*4 + 1);
    printf("%.15Lf %.15Lf\n", base[0].x, base[0].y);
    P delt = 0 ;
    for(int i=0; i < N; i++) {
        for(int j=1; j < 5; j++) {
            P r = delt + base[j];
            printf("%.15Lf %.15Lf\n", r.x, r.y);
        }
        delt = delt + base[3] - base[0];
    }
    for(int i=0, lastP = 0, acm = 1; i < N; i++) {
        int novs[] = {
            lastP,
            acm,
            acm + 1,
            acm + 2,
            acm + 3
        };
        for(int i=0; i < 5; i++)
            printf("%d ", novs[i] + 1);
        printf("\n");
        for(int i=0; i < 5; i++) {
            adj[novs[i]].insert(novs[(i+2)%5]);
            adj[novs[i]].insert(novs[(i+3)%5]);
        }
        lastP = novs[3];
        acm += 4 ;
    }
    euPath(0);
    printf("\n");
}
