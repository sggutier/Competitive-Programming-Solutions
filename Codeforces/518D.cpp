#include <bits/stdc++.h>
using namespace std;
const int limN = 2e3 + 5;

double tab[limN][limN];

int main() {
    int N, T;
    double p, p2;
    scanf("%d%lf%d", &N, &p, &T);
    p2 = 1 - p;

    tab[0][0] = 1.0;
    for(int t=1; t<=T; t++) {
        for(int i=0; i<N; i++) {
            tab[t][i] += tab[t-1][i]*p2;
            tab[t][i+1] += tab[t-1][i]*p;
        }
        tab[t][N] += tab[t-1][N];
    }

    double ans = 0;
    for(int i=0; i<=N; i++)
        ans += tab[T][i]*i;

    printf("%.9lf\n", ans);
}
