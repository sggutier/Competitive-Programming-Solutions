#include <bits/stdc++.h>
using namespace std;
typedef pair<double,double> par;
#define f first
#define s second
const double ER = 6378;
const double PI = acos(-1);

double gcDistance(double pLat, double pLong,
                  double qLat, double qLong, const double radius) {
    pLat *= PI / 180; pLong *= PI / 180;
    qLat *= PI / 180; qLong *= PI / 180;
    return radius * acos(cos(pLat)*cos(pLong)*cos(qLat)*cos(qLong) +
                         cos(pLat)*sin(pLong)*cos(qLat)*sin(qLong) +
                         sin(pLat)*sin(qLat)); }

int main() {
    char A[500], B[500];
    map <string, par> cords;
    
    while(scanf("%s", A)!=EOF && A[0]!='#') {
        double a, b;
        scanf("%lf%lf", &a, &b);
        cords[A] = par(a, b);
    }

    while(scanf("%s%s", A, B)!=EOF && ((A[0]!='#' || A[1]!=0) || (B[0]!='#' || B[1]!=0))) {
        auto x = cords.find(A);
        auto y = cords.find(B);
        printf("%s - %s\n", A, B);
        if(x != cords.end() && y != cords.end())
            printf("%.0lf km\n", x==y? 0.0 : round(gcDistance(x->s.f, x->s.s, y->s.f, y->s.s, ER)));
        else
            printf("Unknown\n");
    }
}
