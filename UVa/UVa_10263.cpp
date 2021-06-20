#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;

struct point {
    double x, y;
    point() {
        x = y = 0.0;
    }
    point(double _x, double _y) : x(_x), y(_y) {}
    bool operator < (point other) const {
        if (fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y;
    }
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS  && (fabs(y - other.y) < EPS));
    }
};

struct line {
    double a, b, c;
};

double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

point rotate(point p, double theta) {
    return point(p.x * cos(theta) - p.y * sin(theta),
                 p.x * sin(theta) + p.y * cos(theta));
}

void pointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS) {
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x;
    }
    else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}

bool areParallel(line l1, line l2) {
    return (fabs(l1.a - l2.a)<EPS) && (fabs(l1.b - l2.b)<EPS);    
}

bool areSame(line l1, line l2) {
    return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}

bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false;
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if(fabs(l1.b) > EPS)
        p.y = -(l1.a * p.x + l1.c);
    else
        p.y = -(l2.a * p.x + l2.c);
    return true;
}

struct vec {
    double x, y;
    vec(double _x, double _y): x(_x), y(_y) {}
};

vec toVec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y);
}

vec scale(vec v, double s) {
    return vec(v.x * s, v.y * s);
}

point translate(point p, vec v) {
    return point(p.x + v.x, p.y + v.y);
}

double dot(vec a, vec b) {
    return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v) {
    return v.x*v.x + v.y*v.y;
}

double distToLine(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    return dist(p, c);
}

double distToLineSegment(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) {
        c = point(a.x, a.y);
        return dist(p, a);
    }
    if (u > 1.0) {
        c = point(b.x, b.y);
        return dist(p, b);
    }
    return distToLine(p, a, b, c);
}

void testCase(point M) {
    int n;
    pair <double, point> ans = make_pair((1<<30)*1.0, point());
    point A;

    scanf("%d", &n);
    scanf("%lf%lf", &A.x, &A.y);
    for(int i=0; i<n; i++) {
        point B, C;
        double dst;
        scanf("%lf%lf", &B.x, &B.y);
        dst = distToLineSegment(M, A, B, C);
        ans = min(ans, make_pair(dst, C));
        A = B;
    }

    printf("%.4lf\n%.4lf\n", ans.second.x, ans.second.y);
}


int main() {
    point M;
    while(scanf("%lf%lf", &M.x, &M.y)!=EOF)
        testCase(M);
    return 0;
}
