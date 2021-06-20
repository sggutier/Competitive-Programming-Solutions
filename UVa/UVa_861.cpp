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

void testCase() {
    int pointN;
    double ans = 0.0;
    scanf("%d", &pointN);
    point points[pointN];
    point lastPnt;
    
    for(int i=0; i<pointN; i++) {
        scanf("%lf%lf", &points[i].x, &points[i].y);
    }
    sort(points, points+pointN);

    lastPnt = points[pointN-1];
    for(int i=pointN-2; i>=0; i--) {
        if(points[i].y - lastPnt.y <= -EPS)
            continue;
        line slop, strt;
        point isec ;
        pointsToLine(points[i], points[i+1], slop);
        pointsToLine(point(lastPnt.x-1, lastPnt.y), lastPnt, strt);
        if(areIntersect(slop, strt, isec))       
            ans += dist(points[i], isec);
        lastPnt = points[i];
    }

    printf("%.2lf\n", ans);
}


int main() {
    int tc;

    for(scanf("%d", &tc); tc; tc--)
        testCase();
    
    return 0;
}
