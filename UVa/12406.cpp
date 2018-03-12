#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll minN, maxN;
int digs;
ll mult;

void bruta(int pos, ll pot, ll crg) {
    if(pos==digs) {
        if(crg%mult!=0)
            return;
        if(!minN)
            minN = crg;
        minN = min(minN, crg);
        if(!maxN)
            maxN = crg;
        maxN = max(maxN, crg);
        return;
    }
    bruta(pos+1, pot*10, crg + pot);
    bruta(pos+1, pot*10, crg + pot*2);
}

int main() {
    int tc;

    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        scanf("%d%lld", &digs, &mult);
        maxN = minN = 0;
        mult = (1LL<<mult);
        bruta(0, 1, 0);
        printf("Case %d: ", i);
        if(!minN) {
            printf("impossible\n");
        }
        else if(minN==maxN)
            printf("%lld\n", minN);
        else
            printf("%lld %lld\n", minN, maxN);
    }
}
