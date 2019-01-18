#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i=a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

template <class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x, p.y); }
	bool operator==(P p) const { return tie(x,y) == tie(p.x, p.y); }
	P operator+(P p) const { return P(x+p.x, y + p.y); }
	P operator-(P p) const { return P(x-p.x, y - p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x * p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double) dist2()); }
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); }
	P perp() const { return P(-y, x); }
	P normal() const { return perp().unit(); }
	P rotate(double a) const {
		return P(x*cos(a) - y*sin(a), x * sin(a) + y*cos(a)); }
};

template <class P>
double lineDist(const P& a, const P& b, const P& p) {
	return (double)(b-a).cross(p-a)/(b-a).dist();
}


typedef Point<double> P;
double segDist(P& s, P& e, P& p) {
	if (s==e) return (p-s).dist();
	auto d = (e-s).dist2(), t = min(d, max(.0,(p-s).dot(e-s)));
	return ((p-s)*d - (e-s)*t).dist() / d;
}


int N, M, K;
Point<double> L[105];

int main() {
	scanf("%d %d %d", &N, &M, &K);
	
	for(int i=0,x,y;i<N;i++) {
		scanf("%d %d", &x, &y);
		L[i] = Point<double>(x, y);
	}
	
	if (M + K == N + 2) {
		double ANS = 1e18;
		for(int i=0;i<N;i++) {
			int j = (i + M - 1) % N;
			
			double cdst = (L[i] - L[j]).dist(); 
			ANS = min(ANS, cdst);
		}
		
		printf("%.3f\n", ANS);
	} else if(M + K == N + 3) {
		
	} else if(M + K == N + 4) {
	} else {
		printf("-1\n");
	}
	
}

