#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> par;
const double inf = 1e9 ;
#define x first
#define y second
const int limN = 1005;
const double PI = acos(-1.0);

double solvEq(double a, double b, double c) {
    // printf("%.3lf %.3lf %.3lf\n", a, b, c);
    double det = b*b - 4*a*c;
    if(det < 0)
        return inf;
    det = sqrt(det);
    double s1 = (-b-det)/(2*a);
    double s2 = (-b+det)/(2*a);
    if(s1 > s2)
        swap(s1, s2);
    if(s1 > 0)
        return s1;
    else if(s2 > 0)
        return s2;
    return inf;
}

double dst2(const par &p1, const par &p2) {
    double dx = p1.x - p2.x, dy = p1.y - p2.y;
    return dx*dx + dy*dy;
}

double colis(const par &p1, const par &v1, const par &p2, const par &v2, const double D) {
    if(dst2(p1, p2) <= D)
        return 0.0;
    double x = p1.x-p2.x, y = p1.y-p2.y;
    double v = v1.x-v2.x, u = v1.y-v2.y;
    // printf("%.3lf %.3lf => %d\n", x, v1, d1);
    // printf("%.3lf %.3lf => %d\n", y, v2, d2);
    return solvEq(v*v + u*u,
                  2*(x*v + y*u),
                  x*x + y*y - D);
}

void testCase() {
    int N ;
    par poss[limN];
    par vels[limN];
    double D;
    double ans = inf;

    scanf("%d%lf", &N, &D);
    D *= D;
    for(int i=0; i<N; i++) {
        double v ;
        int d ;
        scanf("%lf%lf%d%lf", &poss[i].x, &poss[i].y, &d, &v);
        d = (360 + 90 - d) % 360;
        vels[i] = {v*cos(PI*(d/180.0)), v*sin(PI*(d/180.0))};
        // printf("%.3lf %.3lf => [%d] %.3lf %.3lf\n", poss[i].x, poss[i].y, d, vels[i].x, vels[i].y);
    }

    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            ans = min(ans, colis(poss[i], vels[i],
                                 poss[j], vels[j],
                                 D));
        }
    }

    if(ans==inf)
        printf("No collision.\n");
    else
        printf("%d\n", (int) round(ans));
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
}
