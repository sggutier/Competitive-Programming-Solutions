#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const int LIM_N = 1e5 + 5;
const ld EPS = 0;


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
    T dist() const { return sqrtl((T)dist2()); }
    // angle to x-axis in interval [-pi, pi]
    T angle() const { return atan2l(y, x); }
    P unit() const { return *this/dist(); } // makes dist()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated 'a' radians ccw around the origin
    P rotate(double a) const {
        return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
};


typedef Point <ld> P;

int N ;
P pts[LIM_N];

inline ld solveEq(const ld a, const ld b, const ld c) {
    return (-b + sqrtl(b*b - 4*a*c)) / (2*a);
}

ld getX(const ld R, const P &p) {
    auto x = solveEq(1, -2 * p.x, p.x*p.x + p.y*p.y -2*R*p.y);
    // cout << R << " => " << p.x << " " << p.y << " = " << x << "  ||  " << (p - P(x, R)).dist() << endl;
    return x;
}

bool works(const ld R) {
    // dist((a, b), (x, R)) = R
    // (a-x)^2 + (b-R)^2 = R^2
    // a^2 - 2ax + x^2 + b^2 - 2Rb + R^2 = R^2
    // x^2 - 2ax + (a^2 + b^2 - 2Rb) = 0
    pair<ld, int> minX = {getX(R, pts[0]), 0};
    for(int i=1; i < N; i++)
        minX = min(minX, {getX(R, pts[i]), i});
    // ld R2 = R*R;
    // printf("%.9Lf => %.9Lf\n", R, minX.first);
    P cent(minX.first, R);
    for(int i=0; i < N; i++) {
        if(i != minX.second && (pts[i] - cent).dist() - EPS > R)
            return false;
    }
    return true;
}

int main() {
    int negCnt = 0, posCnt = 0;
    scanf("%d", &N);
    for(int i=0; i < N; i++) {
        int a, b ;
        scanf("%d%d", &a, &b);
        pts[i] = P(a, b);
        if(pts[i].y < 0)
            negCnt ++;
        else if(pts[i].y > 0)
            posCnt ++;
    }
    if(negCnt > 0 && posCnt > 0) {
        printf("-1\n");
        return 0 ;
    }
    if(negCnt > 0) {
        for(int i=0; i < N; i++)
            pts[i].y *= -1;
    }
    ld maxY = 0;
    for(int i=0; i < N; i++)
        maxY = max(maxY, pts[i].y);
    ld ini = maxY / 2, fin = 1e15;
    for(int i=0; i < 100; i++) {
        ld piv = (ini + fin) / 2;
        if(works(piv))
            fin = piv;
        else
            ini = piv;
    }
    printf("%.9Lf\n", ini);
    //printf("%.9lf\n", ini);
}
