#include <bits/stdc++.h>
using namespace std;
typedef pair<double,int> par;
#define f first
#define s second
const double ER = 1;
const double PI = acos(-1);

double gcDistance(double pLat, double pLong,
                  double qLat, double qLong, const double radius) {
    pLat *= PI / 180; pLong *= PI / 180;
    qLat *= PI / 180; qLong *= PI / 180;
    return radius * acos(cos(pLat)*cos(pLong)*cos(qLat)*cos(qLong) +
                         cos(pLat)*sin(pLong)*cos(qLat)*sin(qLong) +
                         sin(pLat)*sin(qLat)); }

void testCase(int N) {
    double x[1005], y[1005];
    par ans(1e9, 1);

    for(int i=0; i<N; i++) {
        scanf("%lf%lf", &x[i], &y[i]);
    }

    for(int i=0; i<N; i++) {
        double s = 0;
        for(int j=0; j<N; j++) {
            if(i==j)
                continue;
            s = max(s, gcDistance(x[i], y[i], x[j], y[j], ER));
        }
        if(s - 1e-5 < ans.f)
            ans = par(s, -i);
        //printf("<== %.2lf\n", s);
    }

    

    printf("%.2lf %.2lf\n", x[-ans.s], y[-ans.s]);
    //printf("=> %.2lf\n", ans.f);
}

int main() {
    int N;
    while(scanf("%d", &N)!=EOF)
        testCase(N);
}
