#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);

double testCase(int D, int C) {
    double R = D/2.0;
    double V = 2*PI*R*R*R-C;
    return 2.0*pow(((3.0/(2.0*PI))*V - R*R*R) / 2.0, 1.0/3.0);
}

int main() {
    int a, b;
    while(scanf("%d%d", &a, &b)!=EOF && (a || b))
        printf("%.3lf\n", testCase(a, b));
}
