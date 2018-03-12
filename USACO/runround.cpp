/*
ID: me60
LANG: C++11
TASK: runround
*/
#include <bits/stdc++.h>
using namespace std;

int num;
int ans = (1<<30);
int digs;
int pows[9];
bool posb[1<<10][1<<9];

bool tryAll(int usdDigs, int usdPos, int sum, int pos) {
    if(usdPos==(1<<digs)-1) {
        if(sum>num) {
            ans = min(ans, sum);
        }
        return false;
    }
    if(posb[usdDigs][usdPos]) {
        return true;
    }
    posb[usdDigs][usdPos] = true;
    int nextPos = usdPos ^ (1<<pos);
    if(nextPos==(1<<digs)-1) {
        for(int i=1; i<10; i++) {
            if(((1<<i) & usdDigs) || (pos+i)%digs!=0 )
                continue;
            posb[usdDigs][usdPos] &= tryAll(usdDigs^(1<<i), nextPos, sum + i*pows[pos], (pos+i)%digs);
        }
    }
    else {
        for(int i=1; i<10; i++) {
            if(((1<<i) & usdDigs) || (1<<((pos+i)%digs) & nextPos) )
                continue;
            posb[usdDigs][usdPos] &= tryAll(usdDigs^(1<<i), nextPos, sum + i*pows[pos], (pos+i)%digs);
        }
    }
    return posb[usdDigs][usdPos];
}

int main() {
    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);
    
    scanf("%d", &num);

    pows[0] = 1;
    for(int i=1; i<9; i++)
        pows[i] = pows[i-1]*10;  
    for(digs=0; digs<9 && pows[digs]<=num; digs++);

    reverse(pows, pows+digs);
    tryAll(0, 0, 0, 0);

    if(ans!=(1<<30)) {
        printf("%d\n", ans);
        return 0;
    }
    
    reverse(pows, pows+digs);

    digs++;
    reverse(pows, pows+digs);
    memset(posb, 0, sizeof(posb));
    tryAll(0, 0, 0, 0);

    if(ans!=(1<<30)) {
        printf("%d\n", ans);
        return 0;
    }
   
    return 0;
}
