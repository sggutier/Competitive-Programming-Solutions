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

struct vec { double x, y; // name: ‘vec’ is different from STL vector
    vec(double _x, double _y) : x(_x), y(_y) {} };

vec toVec(point a, point b) {
    // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y); }

vec scale(vec v, double s) {
    return vec(v.x * s, v.y * s); }

point translate(point p, vec v) {
    return point(p.x + v.x , p.y + v.y); }

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }
double distToLine(point p, point a, point b, point &c) {
    // formula: c = a + u * ab
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    // translate a to c
    return dist(p, c); }

double area(point a, point b, point c) {
    return ((a.x * b.y) + (b.x * c.y) + (c.x * a.y) -
            ((a.y * b.x) + (b.y * c.x) + (c.y * a.x)))/2.0;
}

double area(double a, double b, double c) {
    double s = (a + b + c)/2.0;
    return sqrt(s * (s-a) * (s-b) * (s-c));
}

double rCircumCircle(double ab, double bc, double ca) {
    return ab * bc * ca / (4.0 * area(ab, bc, ca)); }

double rCircumCircle(point a, point b, point c) {
    return rCircumCircle(dist(a, b), dist(b, c), dist(c, a)); }

int circumCircle(point p1, point p2, point p3, point &ctr, double &r) {
    r = rCircumCircle(p1, p2, p3);
    if(fabs(r) < EPS)
        return 0;

    point m1, m2, n1, n2;
    vec v1 = toVec(p1, p2), v2 = toVec(p2, p3);
    line l1, l2;
    
    m1 = translate(p1, scale(v1, 0.5));
    m2 = translate(p2, scale(v2, 0.5));
    n1 = translate(m1, vec(-v1.y, v1.x));
    n2 = translate(m2, vec(-v2.y, v2.x));
    pointsToLine(m1, n1, l1);
    pointsToLine(m2, n2, l2);

    areIntersect(l1, l2, ctr);

    return 1;
}

void testCase(int sideCnt) {
    point p, q, r, c;
    double minX, minY, maxX, maxY;
    double rad;

    minX = minY = (1<<30)*1.0;
    maxX = maxY = -minX;
    
    scanf("%lf%lf", &p.x, &p.y);
    scanf("%lf%lf", &q.x, &q.y);
    scanf("%lf%lf", &r.x, &r.y);

    circumCircle(p, q, r, c, rad);

    for(int i=0; i<sideCnt; i++) {
        vec dir = toVec(c, point(0.0, 0.0));
        point v = translate(rotate(translate(p, dir), 2*M_PI*(i/(sideCnt*1.0))),
                            scale(dir, -1.0));
        minX = min(minX, v.x);
        maxX = max(maxX, v.x);
        minY = min(minY, v.y);
        maxY = max(maxY, v.y);
    }

    printf("%.3lf\n", (maxX - minX)*(maxY - minY));
}

int main() {
    int tc = 1;
    int n;

    while(scanf("%d", &n)!=EOF && n) {
        printf("Polygon %d: ", tc);
        testCase(n);
        tc ++;
    }
    
    return 0;
}
