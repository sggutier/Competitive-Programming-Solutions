#include <bits/stdc++.h>
using namespace std;
#define par pair<double,double>
#define x first
#define y second

inline double dist(par A, par B) {
    return hypot(A.x - B.x, A.y - B.y);
}

inline double dot(par A, par B) {
    return A.x * B.x + A.y * B.y ;
}

double distToLine(par p, par a, par b) {
    par ap, ab, ansP;
    double tr;
    ap = par(p.x - a.x, p.y - a.y);
    ab = par(b.x - a.x, b.y - a.y);
    tr = dot(ap, ab) / dot(ab, ab) ;
    ansP = par(a.x + ab.x*tr, a.y + ab.y*tr);
    return dist(p, ansP);
}

int main() {
    int n;
    vector <par> pts;
    double ans = 1e9;

    scanf("%d", &n);
    pts = vector<par>(n);
    for(int i=0; i<n; i++)
        scanf("%lf%lf", &pts[i].x, &pts[i].y);

    for(int i=0; i<n; i++) {
        ans = min(ans, dist(pts[i], pts[(i+1)%n]));
    }

    for(int i=0; i<n; i++) {
        int a=i, b=(a+1)%n, c=(b+1)%n;
        if(n>3)
            ans = min(ans, distToLine(pts[b], pts[a], pts[c])/2.0);
        for(int j=0; j<n; j++) {
            if(j==a || j==b || j==c)
                continue ;
            ans = min(ans, distToLine(pts[j], pts[a], pts[b])/2.0);
            ans = min(ans, distToLine(pts[j], pts[a], pts[c])/2.0);
            ans = min(ans, distToLine(pts[j], pts[c], pts[b])/2.0);
        }
    }

    printf("%.9lf\n", ans);
    
    return 0 ;
}
