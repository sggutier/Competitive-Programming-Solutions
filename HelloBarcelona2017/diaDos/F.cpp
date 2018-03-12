#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8

using namespace std;

struct point { double x, y;   // only used if more precision is needed
  point() { x = y = 0.0; }                      // default constructor
  point(double _x, double _y) : x(_x), y(_y) {}        // user-defined
  bool operator < (point other) const { // override less than operator
    if (fabs(x - other.x) > EPS)                 // useful for sorting
      return x < other.x;          // first criteria , by x-coordinate
    return y < other.y; }          // second criteria, by y-coordinate
  // use EPS (1e-9) when testing equality of two floating points
  bool operator == (point other) const {
   return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); } };

double dist(point p1, point p2) {                // Euclidean distance
                      // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
  return hypot(p1.x - p2.x, p1.y - p2.y); }           // return double


typedef vector <point> bd;
typedef pair <int,int> pii;

struct line { double a, b, c; };          // a way to represent a line

// the answer is stored in the third parameter (pass by reference)
void pointsToLine(point p1, point p2, line &l) {
  if (fabs(p1.x - p2.x) < EPS) {              // vertical line is fine
    l.a = 1.0;   l.b = 0.0;   l.c = -p1.x;           // default values
  } else {
    l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
    l.b = 1.0;              // IMPORTANT: we fix the value of b to 1.0
    l.c = -(double)(l.a * p1.x) - p1.y;
} }

void pointSlopeToLine(point p, double m, line &l) {
  l.a = -m;                                               // always -m
  l.b = 1;                                                 // always 1
  l.c = -((l.a * p.x) + (l.b * p.y)); }

bool areParallel(line l1, line l2) {       // check coefficients a & b
  return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); }

bool areIntersect(line l1, line l2, point &p) {
  if (areParallel(l1, l2)) return false;            // no intersection
  // solve system of 2 linear algebraic equations with 2 unknowns
  p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
  // special case: test for vertical line to avoid division by zero
  if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
  else                  p.y = -(l2.a * p.x + l2.c);
  return true; }

void closestPoint(line l, point p, point &ans) {
  line perpendicular;         // perpendicular to l and pass through p
  if (fabs(l.b) < EPS) {              // special case 1: vertical line
    ans.x = -(l.c);   ans.y = p.y;      return; }

  if (fabs(l.a) < EPS) {            // special case 2: horizontal line
    ans.x = p.x;      ans.y = -(l.c);   return; }

  pointSlopeToLine(p, 1 / l.a, perpendicular);          // normal line
  // intersect line l with this perpendicular line
  // the intersection point is the closest point
  areIntersect(l, perpendicular, ans); }

bd read_building() {
    int n; bd nv;

    scanf("%d", &n);
    nv.resize(n);

    for(int i=0;i<n;i++)
        scanf("%lf%lf", &nv[i].x, &nv[i].y);

    return nv;
}
double area(bd b) {
    double ans = 0.0;

    for(int i=0;i<b.size();i++) {
        ans += b[i].x * b[(i+1)%b.size()].y;
        ans -= b[i].y * b[(i+1)%b.size()].x;
    }

    return abs(ans * 0.5);
}
bool neighbors(bd a, bd b) {
    double mn = INF;

    // pt pt
    for(int i=0;i<a.size();i++) {
        for(int j=0;j<b.size();j++) {
            mn = min(mn, dist(a[i], b[j]));
        }
    }



    for(int i=0;i<a.size();i++) {
        for(int j=0;j<b.size();j++) {
            line l;
            pointsToLine(b[j], b[(j+1)%b.size()],l);

            point ans;
            closestPoint(l, a[i], ans);

            double mnx = min(b[j].x, b[(j+1)%b.size()].x);
            double mxx = max(b[j].x, b[(j+1)%b.size()].x);

            double mny = min(b[j].y, b[(j+1)%b.size()].y);
            double mxy = max(b[j].y, b[(j+1)%b.size()].y);

            if((mnx <= ans.x && ans.x <= mxx) && (mny <= ans.y && ans.y <= mxy)) {
                mn = min(mn, dist(a[i], ans));
            }
        }
    }

    for(int i=0;i<b.size();i++) {
        for(int j=0;j<a.size();j++) {
            line l;
            pointsToLine(a[j], a[(j+1)%a.size()],l);

            point ans;
            closestPoint(l, b[i], ans);

            double mnx = min(a[j].x, a[(j+1)%a.size()].x);
            double mxx = max(a[j].x, a[(j+1)%a.size()].x);

            double mny = min(a[j].y, a[(j+1)%a.size()].y);
            double mxy = max(a[j].y, a[(j+1)%a.size()].y);

            if((mnx <= ans.x && ans.x <= mxx) && (mny <= ans.y && ans.y <= mxy)) {
                mn = min(mn, dist(b[i], ans));
            }
        }
    }

    return mn + EPS < 30.0;
}


int M, P, C;
bd bd_l[105];
double a[105];
int ign[105];
vector <pii> adj[105];
queue <pii> cola;

int main() {
    scanf("%d", &M);

    for(int i=0;i<M;i++) {
        bd_l[i] = read_building();
        a[i] = area(bd_l[i]);
    }

    for(int i=0;i<M;i++) {
        for(int j=i+1;j<M;j++) {
            if(i == j) continue;

            if(neighbors(bd_l[i], bd_l[j])) {
                adj[i].push_back(make_pair(j, ceil(10.0 * a[j] / a[i])));
                adj[j].push_back(make_pair(i, ceil(10.0 * a[i] / a[j])));
            }
        }
    }

    scanf("%d %d", &P, &C);

    for(int i=0;i<M;i++)
        ign[i] = INF;

    ign[P] = 0;

    cola.push(make_pair(P, 0));

    while(!cola.empty()) {
        pii act = cola.front(); cola.pop();

        for(int i=0;i<adj[act.first].size();i++) {
            pii nv = make_pair(adj[act.first][i].first,
                               adj[act.first][i].second + act.second);

            if(nv.second <= C && nv.second < ign[nv.first]) {
                ign[nv.first] = nv.second;
                cola.push(nv);
            }
        }
    }

    bool fs = true;

    for(int i=0;i<M;i++) {
        if(ign[i] <= C) {
            if(!fs) printf(" ");
            printf("%d", i);
            fs = false;
        }
    }
    printf("\n");

    return 0;
}
