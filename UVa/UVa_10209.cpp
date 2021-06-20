#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);

int main() {
    double a;
    double x, y, z;
    double n = (2.0 - sqrt(3.0)/2.0 - PI/3.0)*2.0;
    double m = PI-3.0;
    while(scanf("%lf", &a)!=EOF) {
        a *= a;
        x = a*n;
        z = x + a*m;
        y = a - x - z;
        printf("%.3lf %.3lf %.3lf\n", z, y, x);
    }
}
