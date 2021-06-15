#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
const int limN = 1e5 + 5;
const int limK = 1e3 + 5;

double pa[limK], pb[limK];
double fa[limK], fb[limK];
double probs[limN];

int main() {
    int K, Q;
    int T ;
    double *cur = pa, *prev = pb;
    
    scanf("%d%d", &K, &Q);

    prev[0] = 1.0;
    double dv = 1.0 / K;
    for(int b=1; b<=K; b++) {
        fa[b] = ((b*1.0) * dv) ;
        fb[b] = ((K-b+1.0) * dv) ;
    }
    for(T = 1; prev[K] < (1000 - eps) / 2000; T++) {
        double s = 0;
        cur[0] = 0.0;
        for(int b=1; b<=K; b++)
            cur[b] = fa[b] * prev[b] + fb[b] * prev[b-1];
        for(int b=1; b<=K; b++)
            s += cur[b];
        probs[T] = cur[K];
        // printf("%d => %.9lf con prob %.9lf\n", T, probs[T], s);
        // for(int b=1; b<=K; b++)
        //     printf("\tcon %d => %.9lf\n", b, cur[b]);
        swap(cur, prev);
    }
    // printf("%d\n", T);

    for(int i=0, a, p; i<Q; i++) {
        scanf("%d", &a);
        p = lower_bound(probs, probs+T, (a-eps) / 2000) - probs;
        printf("%d\n", p);
    }
}
