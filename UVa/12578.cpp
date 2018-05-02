#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);

void testCase(double l) {
    double h = l*0.6;
    double g = l*h;
    double r = (l/5.0);
    r = r*r*PI;
    g -= r;
    printf("%.2lf %.2lf\n", r, g);
}

int main() {
    int n, t;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &t);
        testCase(t);
    }
}
