#include <bits/stdc++.h>
using namespace std;
typedef pair<double,double> par;
typedef pair<double, par> tri;
#define f first
#define s second
const double ER = 6371009;
const double PI = acos(-1);

double gcDistance(double pLat, double pLong,
                  double qLat, double qLong, const double radius) {
    pLat *= PI / 180; pLong *= PI / 180;
    qLat *= PI / 180; qLong *= PI / 180;
    return radius * acos(cos(pLat)*cos(pLong)*cos(qLat)*cos(qLong) +
                         cos(pLat)*sin(pLong)*cos(qLat)*sin(qLong) +
                         sin(pLat)*sin(qLat)); }

tri toCords(double lat, double lng) {
    lat *= PI/180, lng *= PI/180;
    return tri(sin(lat), par(sin(lng)*cos(lat), cos(lng)*cos(lat)));
}

double dst(tri A, tri B) {
    double dx = A.f-B.f, dy = A.s.f - B.s.f, dz = A.s.s - B.s.s;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

int main() {
    int N;
    double a, b, c, d;

    scanf("%d", &N);
    while(N--) {
        scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
        printf("%.0lf\n", round(ER * fabs(gcDistance(a, b, c, d, 1.0) -
                                          dst(toCords(a, b), toCords(c, d))) ));
    }
}
