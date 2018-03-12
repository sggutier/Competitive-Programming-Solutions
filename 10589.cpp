#include <bits/stdc++.h>
using namespace std;
const double INF = 1e9 ;
const double EPS = 1e-6;
const double PI = acos(-1.0);
const long long mo = 1e7;

double DEG_to_RAD(double d) { return d * PI / 180.0; }

double RAD_to_DEG(double r) { return r * 180.0 / PI; }

struct point_i { long long x, y;     // whenever possible, work with point_i
  point_i() { x = y = 0; }                      // default constructor
  point_i(long long _x, long long _y) : x(_x), y(_y) {} };          // constructor

struct point { double x, y;   // only used if more precision is needed
  point() { x = y = 0.0; }                      // default constructor
  point(double _x, double _y) : x(_x), y(_y) {} };      // constructor

int insideCircle(point_i p, point_i c, double r) { // all integer version
  long long dx = p.x - c.x, dy = p.y - c.y;
  long long Euc = dx * dx + dy * dy, rSq = r * r;             // all integer
  return Euc < rSq ? 0 : Euc == rSq ? 1 : 2; } //inside/border/outside

bool circle2PtsRad(point p1, point p2, double r, point &c) {
  double d2 = (p1.x - p2.x) * (p1.x - p2.x) + 
              (p1.y - p2.y) * (p1.y - p2.y);
  double det = r * r / d2 - 0.25;
  if (det < 0.0) return false;
  double h = sqrt(det);
  c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
  c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
  return true; }         // to get the other center, reverse p1 and p2

void testCase(int N, long long a) {
    a *= mo;
    point_i pts[] = {point_i(0, 0), point_i(0, a), point_i(a, 0), point_i(a, a)};
    int M = 0;
    point_i W;
    for(int i=0; i<N; i++) {
        int p, q;
        scanf("%d.%d", &p, &q);
        W.x = p*mo + q;
        scanf("%d.%d", &p, &q);
        W.y = p*mo + q;
        printf("%lld %lld\n", W.x, W.y);
        bool works = true;
        for(int j=0; j<4; j++) {
            if(insideCircle(W, pts[j], a)) {
                works = false;
                break;
            }
        }
        if(works)
            M ++;
    }
    a /= mo;
    printf("%lld\n", a*a*M);
}

int main() {
    int a, b;
    while(scanf("%d%d", &a, &b)!=EOF && (a || b))
        testCase(a, b);
}
