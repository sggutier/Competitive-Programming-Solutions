#include <bits/stdc++.h>
using namespace std;
const int limN = 105;
const int limK = 1e4 + 5;
const double inf = 1e9;

void testCase(int N) {
    int D=0;
    int pos[limN];
    double ans[limN];
    double dsts[limK];
    ans[0] = pos[0] = 0.0;
    for(int i=1; i<=N; i++) {
        scanf("%d", &pos[i]);
    }
    D = pos[N];
    double b, e, v, f;
    int r;
    scanf("%lf%d%lf%lf%lf", &b, &r, &v, &e, &f);

    dsts[0] = 0.0;
    for(int x=0; x<r; x++) {
        dsts[x+1] = 1.0/(v - f*(r-x)) + dsts[x];
    }
    for(int x=r; x<D; x++) {
        dsts[x+1] = 1.0/(v - e*(x-r)) + dsts[x];
    }

    for(int i=1; i<=N; i++) {
        double A = inf;
        int p = pos[i];
        for(int j=0; j<i; j++) {
            A = min(A, dsts[p-pos[j]] + ans[j]);
        }
        ans[i] = A + b;
    }
    
    printf("%.4lf\n", ans[N] - b);
}

int main() {
    int n;

    while(scanf("%d", &n)!=EOF && n)
        testCase(n);
    
    return 0;
}
