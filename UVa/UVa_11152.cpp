#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;

inline double perimeter(double a, double b, double c) {
    return a + b + c;
}

inline double area(double a, double b, double c) {
    double s = 0.5 * perimeter(a, b, c);
    return sqrt(s * (s-a) * (s-b) * (s-c));
}

double rInCircle(double ab, double bc, double ca) {
    return area(ab, bc, ca) / (0.5 * perimeter(ab, bc, ca));
}

double aInCircle(double a, double b, double c) {
    double r = rInCircle(a, b, c);
    return r*r*M_PI;
}

double rCircumCircle(double ab, double bc, double ca) {
    return ab * bc * ca / (4.0 * area(ab, bc, ca));
}

double aCircumCircle(double a, double b, double c) {
    double r = rCircumCircle(a, b, c);
    return r*r*M_PI;
}

void testCase(double a, double b, double c) {
    double trian = area(a, b, c);
    double inscr = aInCircle(a, b, c);
    double circum = aCircumCircle(a, b, c);

    circum -= trian;
    trian -= inscr;

    printf("%.4f %.4f %.4f\n", circum, trian, inscr);
}

int main() {
    int a, b, c;

    while(scanf("%d%d%d", &a, &b, &c)!=EOF)
        testCase(a, b, c);
    
    return 0;
}
