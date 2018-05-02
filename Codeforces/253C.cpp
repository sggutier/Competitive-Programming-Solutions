#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int N ;
    int as[limN];
    int rini, cini, rfin, cfin;
    int ans = (1<<30);

    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &as[i]);
        as[i]++;
    }
    scanf("%d%d%d%d", &rini, &cini, &rfin, &cfin);

    for(int i=rini, mc=cini; i<=N; i++) {
        mc = min(mc, as[i]);
        if(abs(i-rfin) <= abs(i-rini) && (min(rini, rfin) >= i || max(rini, rfin) <= i) ) {
            // printf("A %d %d => %d %d %d => %d\n", i, mc, abs(i-rini), abs(i-rfin), abs(mc-cfin), abs(i-rini) + abs(i-rfin) + abs(mc-cfin));
            ans = min(ans, abs(i-rini) + abs(i-rfin) + abs(mc-cfin));
        }
    }
    for(int i=rini, mc=cini; i>=1; i--) {
        mc = min(mc, as[i]);
        if(abs(i-rfin) <= abs(i-rini) && (min(rini, rfin) >= i || max(rini, rfin) <= i) ) {
            // printf("B %d %d => %d %d %d => %d\n", i, mc, abs(i-rini), abs(i-rfin), abs(mc-cfin), abs(i-rini) + abs(i-rfin) + abs(mc-cfin));
            ans = min(ans, abs(i-rini) + abs(i-rfin) + abs(mc-cfin));
        }
    }

    int wc = cini;
    for(int i=min(rini, rfin); i<=max(rini, rfin); i++)
        wc = min(wc, as[i]);
    for(int i=rini, mc=wc; i<=N; i++) {
        mc = min(mc, as[i]);
        if(abs(i-rfin) >= abs(i-rini) && (min(rini, rfin) >= i || max(rini, rfin) <= i) ) {
            ans = min(ans, abs(i-rini) + abs(i-rfin) + abs(mc-cfin));
            // printf("C %d %d => %d %d %d => %d\n", i, mc, abs(i-rini), abs(i-rfin), abs(mc-cfin), abs(i-rini) + abs(i-rfin) + abs(mc-cfin));
        }
    }
    for(int i=rini, mc=wc; i>=1; i--) {
        mc = min(mc, as[i]);
        if(abs(i-rfin) >= abs(i-rini) && (min(rini, rfin) >= i || max(rini, rfin) <= i) ) {
            ans = min(ans, abs(i-rini) + abs(i-rfin) + abs(mc-cfin));
            // printf("D %d %d => %d %d %d => %d\n", i, mc, abs(i-rini), abs(i-rfin), abs(mc-cfin), abs(i-rini) + abs(i-rfin) + abs(mc-cfin));
        }
    }

    printf("%d\n", ans);
}
