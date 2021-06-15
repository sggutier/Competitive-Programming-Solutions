#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int g[limN];

int main() {
    int _N ;

    scanf("%d", &_N);

    for(int n=1; n<=_N; n++) {
        set <int> ats;
        for(int s=3, s2, k=2; s<=n; k++, s=s2) {
            s2 = s + (k+1);
            if((n-s)%k)
                continue;
            int b = (n-s)/k;
            // printf("%d checando %d %d [%d %d] => %d\n", n, k, s, b+1, b+k, g[b+k] ^ g[b]);
            ats.insert(g[b+k] ^ g[b]);
        }
        if(!ats.empty()) {
            auto it = ats.begin();
            if(*it==0) {
                int u = *it;
                it++;
                for(; it!=ats.end(); it++) {
                    if(*it != u+1)
                        break;
                    u = *it;
                }
                g[n] ^= u+1;
            }
        }
        // printf("%d => %d\n", n, g[n]);
        g[n] ^= g[n-1];
    }
    
    if((g[_N]^g[_N-1])==0) {
        printf("-1\n");
        return 0;
    }

    for(int s=3, s2, k=2; s<=_N; k++, s=s2) {
        s2 = s + (k+1);
        if((_N-s)%k)
            continue;
        int b = (_N-s)/k;
        if((g[b+k] ^ g[b]) == 0) {
            printf("%d\n", k);
            return 0;
        }
    }
}
