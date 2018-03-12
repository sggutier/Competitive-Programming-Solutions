#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);

void testCase(double a, double b, double v, double ang, double t) {
    ang = (ang/180.0)*PI;
    double d = v*t*0.5;
    int hor = floor((d*cos(ang))/(a/2.0));
    int ver = floor((d*sin(ang))/(b/2.0));
    printf("%d %d\n", (hor+1)/2, (ver+1)/2);
}

int main() {
    int a, b, v, ang, t;
    while(scanf("%d%d%d%d%d", &a, &b, &v, &ang, &t)!=EOF && (a || b || v || ang || t))
        testCase(a,b,v,ang,t);
}
