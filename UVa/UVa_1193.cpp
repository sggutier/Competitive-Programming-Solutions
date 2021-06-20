#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;
#define par pair<double, double>
#define x first
#define y second
double const eps = 1e-9;

par calcRang(par pto, int D) {
    double dx = sqrt(D*D - pto.y*pto.y);
    return par(pto.x -dx, pto.x + dx);
}

void testCase(int N, int D) {
    static par rangs[limN];
    static par pts[limN];

    int ans = 0;
    
    for(int i=0; i<N; i++) {
        scanf("%lf%lf", &pts[i].x, &pts[i].y);
        if(pts[i].y > D)
            ans = -1;
    }
    if(ans==-1) {
        printf("-1\n");
        return ;
    }
    for(int i=0; i<N; i++) {
        rangs[i] = calcRang(pts[i], D);
        // printf("%lf %lf => %lf %lf\n", pts[i].x, pts[i].y, rangs[i].x, rangs[i].y);
    }
    sort(rangs, rangs+N);

    double ult = -1e15;
    for(int i=0; i<N; i++) {
        if(rangs[i].x > ult) {
            ans ++;
            ult = rangs[i].y;
        }
        else
            ult = min(ult, rangs[i].y);
    }

    printf("%d\n", ans);
}

int main() {
    int a, b;
    int tc = 0;

    while(scanf("%d%d", &a, &b)!=EOF && (a || b)) {
        printf("Case %d: ", ++tc);
        testCase(a, b);
    }
    
    return 0;
}
