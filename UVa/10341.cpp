#include <bits/stdc++.h>
using namespace std;
const double epsA = 1e-9;
const double epsB = 1e-4;

void testCase(int p, int q, int r, int s, int t, int u) {
    double ini=0.0, fin=1.0;
    while(ini+epsA<fin) {
        double x = (ini+fin)/2.0;
        // printf("%.4lf => %.4lf\n", x, (p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u));
        if((p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u)>=0.0)
            ini = x;
        else
            fin = x;
    }

    double  x = ini;
    if(fabs(p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u)<=epsB)
        printf("%.4lf\n", x);
    else
        printf("No solution\n");
}

int main() {
    int p,  q,  r,  s,  t,  u;

    while(scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &t, &u)!=EOF)
        testCase(p, q, r, s, t, u);
    
    return 0;
}
