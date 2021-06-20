#include <bits/stdc++.h>
using namespace std;
const int limN = 1e4 + 5;

int L, gasCnt;
int gasIni[limN], gasFin[limN];
int minUseMemo[limN];

int calcMinUse(int pos, int n=gasCnt) {
    if(pos>=L) {
        return 0;
    }
    if(minUseMemo[n]!=-1) {
        return minUseMemo[n];
    }
    int ans = gasCnt+1;
    for(int i=0; i<gasCnt; i++)
        if(gasIni[i] <= pos && pos < gasFin[i]) 
            ans = min(ans, 1 + calcMinUse(gasFin[i], i));
    return minUseMemo[n] = ans;
}

void testCase() {
    memset(minUseMemo, -1, sizeof(minUseMemo));
    for(int i=0; i<gasCnt; i++) {
        int x, r;
        scanf("%d%d", &x, &r);
        gasIni[i] = x-r;
        gasFin[i] = x+r;
    }
    printf("%d\n", gasCnt - calcMinUse(0));
}

int main() {
    while(scanf("%d%d", &L, &gasCnt)!=EOF && (L || gasCnt))
        testCase();
    
    return 0;
}
