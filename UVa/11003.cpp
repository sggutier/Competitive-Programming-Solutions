#include <bits/stdc++.h>
using namespace std;
const int limN = 1e3 + 5;
#define par pair<int,int>
#define f first
#define s second

int cajCnt;
par cajas[limN];
short maxCajasMemo[limN][6*limN];
bool usd[limN][6*limN];

int maxCajas(int pos, int crg) {
    if(pos==cajCnt)
        return 0;
    if(usd[pos][crg])
        return maxCajasMemo[pos][crg];
    usd[pos][crg] = true ;
    maxCajasMemo[pos][crg] = maxCajas(pos+1, crg);
    if(cajas[pos].f <= crg) {
        maxCajasMemo[pos][crg] = max((int) maxCajasMemo[pos][crg],
                                     maxCajas(pos+1, min(cajas[pos].s, crg-cajas[pos].f))+1 );
    }
    return maxCajasMemo[pos][crg];
}

void testCase() {
    for(int i=0; i<cajCnt; i++)
        scanf("%d%d", &cajas[i].f, &cajas[i].s);

    memset(usd, 0, sizeof(usd));

    printf("%d\n", maxCajas(0, 6000));
}

int main() {
    while(scanf("%d", &cajCnt)!=EOF && cajCnt!=0)
        testCase();
    
    return 0;
}
