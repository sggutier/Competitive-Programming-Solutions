// - There are two cases: the non-intersections form either four triangles or two trapeziums.
// - If the trapeziums case happens, the intersection area is a parallelogram. The
//   intersections are calculated and so the base of the parallelogram.  Then multiply by
//   its height.
// - In the case of the four triangles, notice the two similar triangles like in the example
//   pic.  Calculate the top intersection point of the two rectangles, then the basis of
//   the intersection triangle is the distance between that point and the upper left corner 
//   of the original rectangle.  The height can be calculated using trigonometry. 
//   The small intersection triangle is calculated similarly.  Then the areas of the four are
//   added.
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const double pi = acos(-1);

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
    string toStr();
};

template <class P>
int segmentIntersection(const P& s1, const P& e1,
		const P& s2, const P& e2, P& r1, P& r2) {
	if (e1==s1) {
		if (e2==s2) {
			if (e1==e2) { r1 = e1; return 1; } //all equal
			else return 0; //different point segments
		} else return segmentIntersection(s2,e2,s1,e1,r1,r2);//swap
	}
	//segment directions and separation
	P v1 = e1-s1, v2 = e2-s2, d = s2-s1;
	auto a = v1.cross(v2), a1 = v1.cross(d), a2 = v2.cross(d);
	if (a == 0) { //if parallel
		auto b1=s1.dot(v1), c1=e1.dot(v1),
		     b2=s2.dot(v1), c2=e2.dot(v1);
		if (a1 || a2 || max(b1,min(b2,c2))>min(c1,max(b2,c2)))
			return 0;
		r1 = min(b2,c2)<b1 ? s1 : (b2<c2 ? s2 : e2);
		r2 = max(b2,c2)>c1 ? e1 : (b2>c2 ? s2 : e2);
		return 2-(r1==r2);
	}
	if (a < 0) { a = -a; a1 = -a1; a2 = -a2; }
	if (0<a1 || a<-a1 || 0<a2 || a<-a2)
		return 0;
	r1 = s1-v1*a2/a;
	return 1;
}

typedef Point<double> P;

template <class T>
string Point<T>::toStr() {
    char ans[500];
    sprintf(ans, "(%.2lf , %.2lf)", x, y);
    return ans;
}

double calcArea(P a, P b, P q, P r, double ang) {
    P dummy, mt ;
    segmentIntersection(a, b, q, r, mt, dummy);

    // printf("%s %s | %s %s => %s\n", a.toStr().c_str(), b.toStr().c_str(), q.toStr().c_str(), r.toStr().c_str(), mt.toStr().c_str());
    
    double bt = (mt-r).dist();
    double at = bt*tan(ang);
    // printf("a = %.2lf, b = %.2lf\n", at, bt);
    return at*bt;
}

int main() {
    double w, h;
    int ang ;
    scanf("%lf%lf%d", &w, &h, &ang);
    ang = min(ang, 180 - ang);
    if(ang==0 || (ang==90 && w==h)) {
        printf("%.9lf\n", w*h);
        return 0;
    }
    if(w < h)
        swap(w, h);
    P ur (w/2, h/2);
    P ul (-w/2, h/2), dr(w/2, -h/2), dl(-w/2, -h/2);
    P urRot = ur.rotate(ang*(pi/180)), drRot = dr.rotate(ang*(pi/180));
    P ulRot = ul.rotate(ang*(pi/180));

    if(drRot.y >= ur.y) {
        P dummy, l, r ;
        P dlRot = dl.rotate(ang*(pi/180));
        segmentIntersection(ul, ur, ulRot, urRot, l, dummy);
        segmentIntersection(ul, ur, dlRot, drRot, r, dummy);
        // printf("\t %s | %s | %s\n", ulRot.toStr().c_str(), urRot.toStr().c_str(), drRot.toStr().c_str());
        // printf("%s | %s\n", l.toStr().c_str(), r.toStr().c_str());
        printf("%.9lf\n", abs(r.x - l.x) * h);
    }
    else {
        printf("%.9lf\n", w*h - (calcArea(ul, ur, ulRot, urRot, ang*(pi/180))
                                 + calcArea(ur, dr, urRot, drRot, ang*(pi/180))) );
    }
    
}
