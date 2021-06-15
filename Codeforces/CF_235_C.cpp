#include <bits/stdc++.h>
using namespace std;

int main() {
    int N ;
    double ans = 0, x = 0, z = 0, r = 0, p ;

    scanf("%d", &N);
    for(int i=0; i < N; i++) {
        scanf("%lf", &p);
        x = (1-r) + (x + z) * r ;
        z = 2*(1-r) + z*r;
        ans += p*x;
        r = p ;
    }

    printf("%.9lf\n", ans);
}
