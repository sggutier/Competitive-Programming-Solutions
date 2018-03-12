#include <bits/stdc++.h>
using namespace std;

int main() {
    int l, w, h, thet2;
    double theta, alpha, d;
    double ans;

    while(scanf("%d%d%d%d", &l, &w, &h, &thet2)!=EOF) {
        theta = M_PI*thet2/180.0;
        alpha = atan((1.0*h)/l);
        if(theta<=alpha) {
            d = l*tan(theta);
            ans = (l*h) - l*(d/2.0);
        }
        else {
            d = h*tan(M_PI/2.0 - theta);
            ans = h*d/2.0;
        }
        printf("%.3lf mL\n", ans*w);
    }
    
    return 0;
}
