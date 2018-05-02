#include <bits/stdc++.h>
using namespace std;

tuple <double, double> case1(double u, double v, double t) {
    return { ((u+v)/2.0)*t, (v-u)/t };
}

tuple <double, double> case2(double u, double v, double a) {
    double t = (v-u)/a;
    return { ((u+v)/2.0)*t, t };
}

tuple <double, double> case3(double u, double a, double s) {
    double t = (-u + sqrt(u*u + 2*a*s) ) / a;
    return { u + a*t, t };
}

tuple <double, double> case4(double v, double a, double s) {
    return case3(v, -a, s);
}

int main() {
    int t;
    double a, b, c;
    function< tuple<double, double>(double, double, double) > tc[4] = {case1, case2, case3, case4};
    int i = 0;
    while(scanf("%d", &t) != EOF && t) {
        scanf("%lf%lf%lf", &a, &b, &c);
        double x, y ;
        tie(x, y) = tc[t-1](a, b, c);
        printf("Case %d: %.3lf %.3lf\n", ++i, x, y);
    }
}
