#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int d, v, u;
    scanf("%d%d%d", &d, &v, &u);
    if(v>=u || v==0)
        printf("can't determine\n");
    else
        printf("%.3lf\n", d/sqrt(u*u - v*v) - d/(u*1.0));
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        printf("Case %d: ", i+1);
        testCase();
    }
}
