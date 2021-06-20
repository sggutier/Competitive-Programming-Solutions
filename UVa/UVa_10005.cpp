#include <bits/stdc++.h>
using namespace std;
const double INF = 1e9 ;
const double EPS = 1e-6;
const double PI = acos(-1.0);

double DEG_to_RAD(double d) { return d * PI / 180.0; }

double RAD_to_DEG(double r) { return r * 180.0 / PI; }

struct point_i { int x, y;     // whenever possible, work with point_i
  point_i() { x = y = 0; }                      // default constructor
  point_i(int _x, int _y) : x(_x), y(_y) {} };          // constructor

struct point { double x, y;   // only used if more precision is needed
  point() { x = y = 0.0; }                      // default constructor
  point(double _x, double _y) : x(_x), y(_y) {} };      // constructor

int insideCircle(point p, point c, double r) { // all integer version
  double dx = p.x - c.x, dy = p.y - c.y;
  double Euc = dx * dx + dy * dy, rSq = r * r;             // all integer
  return Euc - EPS < rSq ? 0 : Euc == rSq ? 1 : 2; } //inside/border/outside

bool circle2PtsRad(point p1, point p2, double r, point &c) {
  double d2 = (p1.x - p2.x) * (p1.x - p2.x) + 
              (p1.y - p2.y) * (p1.y - p2.y);
  double det = r * r / d2 - 0.25;
  if (det < 0.0) return false;
  double h = sqrt(det);
  c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
  c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
  return true; }         // to get the other center, reverse p1 and p2

void testCase(int N) {
    vector <point> poly(N);
    for(int i=0; i<N; i++)
        scanf("%lf%lf", &poly[i].x, &poly[i].y);
    double r;
    point c;
    scanf("%lf", &r);

    if(N==1) {
        printf("The polygon can be packed in the circle.\n");
        return;
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(i==j || !circle2PtsRad(poly[i], poly[j], r, c))
                continue;
            bool works = true;
            for(int k=0; k<N; k++) {
                if(insideCircle(poly[k], c, r)!=0) {
                    works = false;
                    break;
                }
            }
            if(works) {
                printf("The polygon can be packed in the circle.\n");
                return;
            }
        }
    }

    printf("There is no way of packing that polygon.\n");
}

int main() {
    int n;
    while(scanf("%d", &n)!=EOF && n)
        testCase(n);
}
