// template
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

template <class T>
struct Point {
    typedef Point P ;
    T x, y ;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
    bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
    P operator+(P p) const { return P(x + p.x, y +p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double) dist2()); }
    // angle to x-axis in interval [-pi, pi]
    double angle() const { return atan2(y, x); }
    P unit() const { return *this/dist(); }
    P perp() const { return P(-y, x); } // rotates + 90 deg
    P normal() const { return perp().unit(); }
    // returns point rotated 'a' radians ccw around the origin
    P rotate(double a) const {
        return P(x*cos(a) - y*sin(a), x*sin(a)+y*cos(a));
    }
};

typedef Point<ll> P;
const int limN = 1e4 + 5;

int numS = 0;
P poly[limN];
int N;
P pts[limN];
int vals[limN];
int ordsPoly[limN], ordsPts[limN];
int dp[700][700];

void calca(const int ref) {
    const P w = poly[ref];
    for(int i=0; i<N; i++)
        ordsPts[i] = i;
    for(int i=0; i<numS; i++)
        ordsPoly[i] = i;

    sort(ordsPts, ordsPts + N,
            [&](const int a, const int b) {
                return (pts[a]-w).cross(pts[b]-w) > 0;
    });
    sort(ordsPoly, ordsPoly + numS,
         [&](const int a, const int b) {
             return (poly[a]-w).cross(poly[b]-w) > 0;
         });

   for(int i=0; i<numS; i++) {
       int p = ordsPoly[i];
       printf("%lld %lld (%d)\n", poly[p].x, poly[p].y, p + 1);
   }

    int tt = 0;
    for(int i=0, j=0; i<numS; i++) {
        int p = ordsPoly[i];
        if(p == ref) continue;
       printf("%d => (%lld %lld)\n", p+1, poly[p].x, poly[p].y);
        const P v = poly[p] - w;
        while(j < N) {
            int q = ordsPts[j];
            if(pts[q] == w) {
                j++;
                continue;
            }
            if(v.cross(pts[q] - w) >= 0)
                break;
           printf("\t%d (%lld %lld %d)\n", q+1, pts[q].x, pts[q].y, vals[q]);
            tt += vals[q];
            j ++;
        }
        dp[ref][p] = tt;
        printf("%d a %d => %d\n", ref+1, p+1, tt);
    }
}

int main() {    
    int tot = 0;

    scanf("%d", &numS);
    for(int i=0; i<numS; i++)
        scanf("%lld%lld", &poly[i].x, &poly[i].y);
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%lld%lld%d", &pts[i].x, &pts[i].y, &vals[i]);
        tot += vals[i];
    }
    for(int i=0; i<numS; i++) {
//        printf("%d <<<< %lld %lld\n", i+1, poly[i].x, poly[i].y);
        calca(i);
    }

//    printf("tot = %d\n", tot);
    int ans = -2e9 - 100;
    for(int i=0; i<numS; i++) {
        for(int j=i+1; j<numS; j++) {
            for(int k=j+1; k<numS; k++) {
                int x = dp[j][i];
                int y = dp[k][j];
                int z = dp[i][k];
//                printf("%d %d %d >>>>>> %d\n", i+1, j+1, k+1, tot - x - y - z);
//                printf("\t%d %d %d\n", x, y, z);
                ans = max(ans, tot - x - y - z);
            }
        }
    }

    printf("%d\n", ans);
}
