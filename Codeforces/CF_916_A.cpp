#include <bits/stdc++.h>
using namespace std;

int main() {
    int x ;
    int h, t;
    int ftim;
    int ans = (1<<30);

    scanf("%d", &x);
    scanf("%d%d", &h, &t);
    ftim = h*60 + t;

    for(h=0; h<24; h++) {
        for(int m=0; m<60; m++) {
            if(h%10 != 7  && (h/10) != 7 && (m%10) != 7 && (m/10) != 7)
                continue;
            int c = 0;
            bool fca = true;
            // printf("Calando %d %d\n", h, m);
            bitset <24*60> usd;
            for(t=h*60 + m; t != ftim; t = (t+x) % (24*60) ) {
                if(usd[t]) { fca = false; break; }
                usd[t] = true;
                c++;
            }
            if(fca)
                ans = min(ans, c);
        }
    }

    printf("%d\n", ans);
}
