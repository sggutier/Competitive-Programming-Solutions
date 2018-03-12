#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const double EPS = 1e-3;
const double PI = acos(-1.0);

double DEG_to_RAD(double d) { return d * PI / 180.0; }

double RAD_to_DEG(double r) { return r * 180.0 / PI; }

struct point { double x, y;  
  point() { x = y = 0.0; } 
  point(double _x, double _y) : x(_x), y(_y) {}       
    void printo() {
        printf("(%.3lf, %.3lf ) ", x, y);
    }
  bool operator == (point other) const {
   return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); } };

struct vec { double x, y;  
  vec(double _x, double _y) : x(_x), y(_y) {} };

vec toVec(point a, point b) {
  return vec(b.x - a.x, b.y - a.y); }

double dist(point p1, point p2) {   
  return hypot(p1.x - p2.x, p1.y - p2.y); }  


double perimeter(const vector<point> &P) {
  double result = 0.0;
  for (int i = 0; i < (int)P.size()-1; i++) 
    result += dist(P[i], P[i+1]);
  return result; }

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double angle(point a, point o, point b) { 
  vec oa = toVec(o, a), ob = toVec(o, b);
  double ro = sqrt(max(0.0, norm_sq(oa) * norm_sq(ob)));
  while(fabs(ro)<EPS);
  double wo = dot(oa, ob) / ro;
  if(wo>1.0)
      wo = 1.0;
  else if(wo<-1.0)
      wo = -1.0;
  return acos(wo); }

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }


bool ccw(point p, point q, point r) {
  return cross(toVec(p, q), toVec(p, r)) > 0; }

// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r) {
  return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; }

point pivot;
bool angleCmp(point a, point b) {            
  if (collinear(pivot, a, b))                 
    return dist(pivot, a) < dist(pivot, b);   
  double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
  double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
  return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0; }  

vector<point> CH(vector<point> P) {   
  int i, j, n = (int)P.size();
  if (n <= 3) {
    if (!(P[0] == P[n-1])) P.push_back(P[0]);
    return P;                           
  }


  int P0 = 0;
  for (i = 1; i < n; i++)
    if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
      P0 = i;

  point temp = P[0]; P[0] = P[P0]; P[P0] = temp;


  pivot = P[0];                   
  sort(++P.begin(), P.end(), angleCmp); 


  vector<point> S;
  S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]);   
  i = 2;                                         
  while (i < n) {           
    j = (int)S.size()-1;
    if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]); 
    else S.pop_back(); }  
  return S; }                                        

int main() {
    int N ;
    vector <point> P;
    set <pair<long long, long long>> pts;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        //double a, b;
        long long a, b;
        //scanf("%lf%lf", &a, &b);
        scanf("
        pts.insert(make_pair(a, b));
    }

    for(const auto &p:pts) {
        P.push_back(point(p.first, p.second));
    }
    P = CH(P);
    N = P.size()-1;

    double ans = 1e9;
    for(int i=0; i<N; i++) {
        ans = min(ans, angle(P[(i+N-1)%N], P[i], P[(i+1)%N]));
    }

    if(N==0)
        ans = 0.0;

    printf("%.9lf\n", RAD_to_DEG(ans));

    return 0;
}
