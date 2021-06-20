#include <bits/stdc++.h>
using namespace std;
const int limB = 17;
const int limN = 1e4 + 5;

int mrkCnt = 0;
int bitCnt[1<<limB];
int lstMrk[1<<limB];

void cuentaBits(int pos=0, int msk=0, int on=0) {
    if(pos==limB) {
        bitCnt[msk] = on;
        return;
    }
    cuentaBits(pos+1, msk, on);
    cuentaBits(pos+1, msk | (1<<pos), on + 1);
}

void testCase() {
    int ledCnt, simbCnt;
    int simbs[limN];
    scanf("%d%d", &ledCnt, &simbCnt);
    for(int i=0; i<simbCnt; i++) {
        int a=0, b;
        lstMrk[i] = -1;
        for(int j=0; j<ledCnt; j++) {
            scanf("%d", &b);
            a |= (b<<j);
        }
        simbs[i] = a;
    }
    int ans = ledCnt;
    for(int b=(1<<ledCnt)-2; b>=0; b--) {
        bool itWorks = true;
        mrkCnt++;
        for(int i=0; i<simbCnt; i++) {
            if(lstMrk[simbs[i] & b]==mrkCnt) {
                itWorks = false;
                break;
            }
            lstMrk[simbs[i] & b] = mrkCnt;
        }
        if(itWorks)
            ans = min(ans, bitCnt[b]);
    }
    printf("%d\n", ans);
}

int main() {
    cuentaBits();
    int tc;

    for(scanf("%d", &tc); tc; tc--)
        testCase();
    
    return 0;
}
