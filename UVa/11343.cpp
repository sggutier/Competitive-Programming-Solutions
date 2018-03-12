#include <bits/stdc++.h>
using namespace std;
#define point pair<double, double>
#define x first
#define y second
const double EPS = 1e-9;

bool entre(double a, double b, double c) {
    if(a>b)
        swap(a, b);
    return a-EPS <= c && c <= b + EPS;
}

struct line {
    double a, b, c;
    point p1, p2;
    line() {
    }
    line(point p1, point p2) {
        this->p1 = p1;
        this->p2 = p2;
        if (fabs(p1.x - p2.x) < EPS) {
            a = 1.0;
            b = 0.0;
            c = -p1.x;
        }
        else {
            a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
            b = 1.0;
            c = -(double)(a * p1.x) - p1.y;
        }
    }
    bool areParallel(line *l2) {
        return (fabs(this->a-l2->a) < EPS) && (fabs(this->b-l2->b) < EPS);
    }
    bool areSame(line *l2) {
        return areParallel(l2) && (fabs(this->c - l2->c) < EPS);
    }
    point* intersect(line *l2) {
        point *p = NULL;
        p = new point();
        if (this->areParallel(l2))
            return p;
        p->x = (l2->b * this->c - this->b * l2->c) / (l2->a * this->b - this->a * l2->b);
        // special case: test for vertical line to avoid division by zero
        if (fabs(this->b) > EPS)
            p->y = -(this->a * p->x + this->c);
        else
            p->y = -(l2->a * p->x + l2->c);
        return p;
    }
    bool contains(point p) {
        return entre(p1.x, p2.x, p.x) && entre(p1.y, p2.y, p.y);
    }
};

void testCase() {
    int lineCnt, ans=0;
    scanf("%d", &lineCnt);
    vector<line> lines(lineCnt);
    for(int i=0; i<lineCnt; i++) {
        point p1, p2;
        scanf("%lf%lf", &p1.x, &p1.y);
        scanf("%lf%lf", &p2.x, &p2.y);
        lines[i] = line(p1, p2);
    }
    for(int i=0; i<lineCnt; i++) {
        bool works = true;
        for(int j=0; j<lineCnt; j++) {
            if(i==j)
                continue;
            if(lines[i].areSame(&lines[j])) {
                if(lines[i].contains(lines[j].p1) || lines[i].contains(lines[j].p2)
                   || lines[j].contains(lines[i].p1) || lines[j].contains(lines[i].p2)) {
                    works = false;
                    break;
                }
            }
            point *p = lines[i].intersect(&lines[j]);
            if(p==NULL)
                continue;
            if(lines[i].contains(*p) && lines[j].contains(*p)) {
                works = false;
                // printf("%d and %d collided at %lf %lf\n", i, j, p->x, p->y);
            }
            delete p;
            if(!works)
                break;
        }
        if(works)
            ans ++;
    }
    printf("%d\n", ans);
}

int main() {
    int tc;

    scanf("%d", &tc);
    while(tc--)
        testCase();
    
    return 0;
}
