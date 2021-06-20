#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
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

template <class P>
int lineIntersection(const P& s1, const P& e1, const P& s2,
		const P& e2, P& r) {
	if ((e1-s1).cross(e2-s2)) { //if not parallell
		r = s2-(e2-s2)*(e1-s1).cross(s2-s1)/(e1-s1).cross(e2-s2);
		return 1;
	} else
		return -((e1-s1).cross(s2-s1)==0 || s2==e2);
}

typedef Point<double> P;
vector<P> polygonCut(const vector<P>& poly, P s, P e) {
	vector<P> res;
	rep(i,0,sz(poly)) {
		P cur = poly[i], prev = i ? poly[i-1] : poly.back();
		bool side = s.cross(e, cur) < 0;
		if (side != (s.cross(e, prev) < 0)) {
			res.emplace_back();
			lineIntersection(s, e, cur, prev, res.back());
		}
		if (side)
			res.push_back(cur);
	}
	return res;
}

template <class T>
T polygonArea2(vector<Point<T>>& v) {
	T a = v.back().cross(v[0]);
	rep(i,0,sz(v)-1) a += v[i].cross(v[i+1]);
	return a;
}

double mocha(vector <P> pts, vector< pair<P, P> > &lads, int ini, int K) {
    int N = sz(lads);
    // printf("--------\n");
    for(int i=0; i<K && sz(pts) > 2; i++) {
        vector <P> reso = polygonCut(pts, lads[(i+ini)%N].first, lads[(i+ini)%N].second);
        pts = reso;
    }
    // printf("El polígono recortado es:\n");
    // for(P &p : pts)
    //     printf("%.2lf|%.2lf ", p.x, p.y);
    // printf("\n");
    return fabs(polygonArea2(pts)) / 2;
}

double dp[1<<20];
bool usd[1<<20];

double mochaRec(vector <P> pts, vector< pair<P, P> > &lads, int msk, int rem) {
    if(usd[msk])
        return dp[msk];
    usd[msk] = true;
    if(sz(pts) <= 2)
        return dp[msk] = 0.0;
    double &ans = dp[msk];
    ans = fabs(polygonArea2(pts)) / 2;
    if(rem==0)
        return ans;
    for(int i=sz(lads)-1; i>=0; i--) {
        if((1<<i) & msk)
            ans = min(ans, mochaRec(
                      polygonCut(pts, lads[i].first, lads[i].second),
                      lads,
                      msk - (1<<i),
                      rem-1));
    }
    return ans;
}

void testCase(int N, int K, int H) {
    memset(usd, 0, sizeof(usd));
	vector <P> pts(N);
    vector < pair<P, P> > lads;
    for(int i=0; i<N; i++) {
        scanf("%lf%lf", &pts[i].x, &pts[i].y);        
    }
    for(int i=0; i<N; i++) {
        P dir = (pts[(i+1)%N] - pts[i]).perp().unit();
        P a = pts[(i+1)%N] + dir*H;
        P b = pts[i] + dir*H;
        // if( !(a == b) )
            lads.push_back({a,  b});
        // printf("%.2lf %.2lf || %.2lf %.2lf\n", a.x, a.y, b.x, b.y);
    }
    // N = sz(lads);
    K = min(K, N);
    // printf("El polígono org es:\n");
    // for(P &p : pts)
    //     printf("%.2lf|%.2lf ", p.x, p.y);
    // printf("\n");
    double ans = 1e9, orgo = fabs(polygonArea2(pts)) / 2;
    // for(int i=0; i<N; i++) {
    //     ans = min(ans, mocha(pts, lads, i, K));
    // }
    ans = min(ans, mochaRec(pts, lads, (1<<N)-1, K));
    printf("%.2lf\n", orgo - ans);
}

int main() {
    int N, K, H;
    while(scanf("%d%d%d", &N, &K, &H) != EOF && (N || K || H)) {
        testCase(N, K, H);
    }
}
