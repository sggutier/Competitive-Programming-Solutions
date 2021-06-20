#include <bits/stdc++.h>
using namespace std;

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

typedef Point<double> Pt;
const double eps = 0.0;

char sgo(double a) {
    return a <= 0? '-' : '+';
}

void printPar(char c, double a) {
    if(abs(a) > eps)
        printf("(%c %c %.3lf)^2", c, sgo(-a), abs(a));
    else
        printf("%c^2", c);
}

void printSol(double x, char c) {
    if(abs(x) <= eps)
        return;
    printf(" %c %.3lf", sgo(-x), abs(x));
    if(c != 'w')
        printf("%c", c);
}

void testCase(Pt ptos[3]) {
    Pt mits[2], otrs[2] ;
    Pt cent ;
    double rd ;

    for(int i=0; i<2; i++) {
        mits[i] = (ptos[i] + ptos[i+1])/2.0;
        otrs[i] = mits[i] + (ptos[i+1] - ptos[i]).perp();
    }
    lineIntersection(mits[0], otrs[0], mits[1], otrs[1], cent);

    rd = (cent-ptos[0]).dist();
    printPar('x', cent.x);
    printf(" + ");
    printPar('y', cent.y);
    printf(" = %.3lf^2\n", rd);
    rd = (cent-ptos[0]).dist2();
    rd -= cent.x*cent.x + cent.y*cent.y;
    cent.x *= 2;
    cent.y *= 2;
    printf("x^2 + y^2");
    printSol(cent.x, 'x');
    printSol(cent.y, 'y');
    printSol(rd, 'w');
    printf(" = 0\n");
    printf("\n");
}

int main() {
    Pt ptos[3];
    while(scanf("%lf%lf%lf%lf%lf%lf", &ptos[0].x, &ptos[0].y, &ptos[1].x, &ptos[1].y, &ptos[2].x, &ptos[2].y) != EOF)
        testCase(ptos);
}
