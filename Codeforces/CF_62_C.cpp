#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;
const int LIM_N = 105 ;

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

typedef Point<ld> P ;

struct Trian {
    P pts[3];
    Trian(const P &a = P(), const P &b = P(), const P &c = P()) {
        pts[0] = a;
        pts[1] = b;
        pts[2] = c;
    }
    string toString() {
        char ans[300];
        sprintf(ans, "Polygon({(%.4Lf, %.4Lf), (%.4Lf, %.4Lf), (%.4Lf, %.4Lf)})", pts[0].x, pts[0].y, pts[1].x, pts[1].y, pts[2].x, pts[2].y);
        return ans;
    }
    bool operator<(const Trian &otr) const {
        if(!(this->pts[0] == otr.pts[0]))
            return this->pts[0] < otr.pts[0];
        if(!(this->pts[1] == otr.pts[1]))
            return this->pts[1] < otr.pts[1];
        return this->pts[2] < otr.pts[2];
    }
};

template <class P>
int segmentIntersection(const P& s1, const P& e1,
        const P& s2, const P& e2, P& r1, P& r2) {
    if (e1==s1) {
        if (e2==s2) {
            if (e1==e2) { r1 = e1; return 1; } //all equal
            else return 0; //different point segments
        } else return segmentIntersection(s2,e2,s1,e1,r1,r2);//swap
    }
    //segment directions and separation
    P v1 = e1-s1, v2 = e2-s2, d = s2-s1;
    auto a = v1.cross(v2), a1 = v1.cross(d), a2 = v2.cross(d);
    if (a == 0) { //if parallel
        auto b1=s1.dot(v1), c1=e1.dot(v1),
             b2=s2.dot(v1), c2=e2.dot(v1);
        if (a1 || a2 || max(b1,min(b2,c2))>min(c1,max(b2,c2)))
            return 0;
        r1 = min(b2,c2)<b1 ? s1 : (b2<c2 ? s2 : e2);
        r2 = max(b2,c2)>c1 ? e1 : (b2>c2 ? s2 : e2);
        return 2-(r1==r2);
    }
    if (a < 0) { a = -a; a1 = -a1; a2 = -a2; }
    if (0<a1 || a<-a1 || 0<a2 || a<-a2)
        return 0;
    r1 = s1-v1*a2/a;
    return 1;
}

template <class P>
bool onSegment(const P& s, const P& e, const P& p) {
    P ds = p-s, de = p-e;
    return ds.cross(de) == 0 && ds.dot(de) <= 0;
}

template <class It, class P>
bool insidePolygon(It begin, It end, const P& p,
        bool strict = true) {
    int n = 0; //number of isects with line from p to (inf,p.y)
    for (It i = begin, j = end-1; i != end; j = i++) {
        //if p is on edge of polygon
        if (onSegment(*i, *j, p)) return !strict;
        //or: if (segDist(*i, *j, p) <= epsilon) return !strict;
        //increment n if segment intersects line from p
        n += (max(i->y,j->y) > p.y && min(i->y,j->y) <= p.y &&
                ((*j-*i).cross(p-*i) > 0) == (i->y <= p.y));
    }
    return n&1; //inside if odd number of intersections
}


int N ;
vector<P> trians[LIM_N];
set <P> isecs[LIM_N][3];

int main() {
    scanf("%d", &N);
    for(int i=0; i < N; i++) {
        trians[i].resize(4);
        for(int j=0; j < 3; j++)
            scanf("%Lf%Lf", &trians[i][j].x, &trians[i][j].y);
        trians[i][3] = trians[i][0];
        for(int j=0; j < 3; j++) {
            isecs[i][j].insert(trians[i][j]);
            isecs[i][j].insert(trians[i][j+1]);
        }
    }

    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            if(i == j) continue;
            for(int x=0; x < 3; x++) {
                for(int y=0; y < 3; y++) {
                    P c1, c2;
                    if(!segmentIntersection(trians[i][x], trians[i][x+1], trians[j][y], trians[j][y+1], c1, c2))
                        continue;
                    isecs[i][x].insert(c1);
                }
            }
        }
    }

    ld ans = 0 ;
    for(int i=0; i < N; i++) {
        for(int d=0; d < 3; d++) {
            auto cur = isecs[i][d].begin(), nxt = isecs[i][d].begin();
            for(nxt ++; nxt != isecs[i][d].end(); cur++, nxt++) {
                P mit = (*cur + *nxt) / 2 ;
                bool wks = true;
                for(int j=0; j < N; j++) {
                    if(i == j) continue;
                    if(insidePolygon(trians[j].begin(), trians[j].end(), mit)) {
                        wks = false;
                        break;
                    }
                }
                if(wks)
                    ans += (*nxt - *cur).dist();
            }
        }
    }

    printf("%.10Lf\n", ans);
}
