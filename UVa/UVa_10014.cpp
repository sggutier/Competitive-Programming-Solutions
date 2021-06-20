#include <bits/stdc++.h>
using namespace std;

void testCase() {
    vector <double> c;
    double crg, u;
    int N ;
    double x, y;
    
    scanf("%d", &N);
    scanf("%lf%lf", &x, &y);
    c.resize(N);
    for(int i=0; i<N; i++) {
        scanf("%lf", &c[i]);
    }
    c[0] -= x/2;
    c[N-1] -= y/2;
    reverse(c.begin(), c.end());

    crg = 0.5, u = c[0];
    for(int i=1; i<N; i++) {
        double d ;
        crg *= 0.5;
        u = u*0.5 + c[i];
        d = 1.0-crg;
        crg = 0.5 / d;
        u /= d;
    }

    printf("%.2lf\n", -u);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        if(i)
            printf("\n");
        testCase();
    }
}
