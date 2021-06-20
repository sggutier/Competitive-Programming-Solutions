#include <bits/stdc++.h>
using namespace std;
const int limN = 12;
const int limB = 1<<limN;
const int INF = (1<<30);
const int sev = 7;

int N, NB;
int mapa[limN];

int calcNmo(int upo) {
    //int orgo = upo;
    int msk, ant = 0 ;
    int ans = 0;
    for(int i=1; i<=N; i++) {
        msk = ant ^ mapa[i];
        ant = 0;
        for(int b=1; b<=N; b++) {
            if(!((1<<b) & upo))
                continue;
            ant |= (1<<b);
            msk ^= 7<<(b-1);
            ans ++;
        }
        upo = msk;
    }
    if(upo & NB)
        return INF;
    else
        return ans;
}

void testCase() {
    int ans = INF;
    char lin[15];
    for(int i=1; i<=10; i++) {
        gets(lin);
        mapa[i] = 0;
        for(int b=1; b<=10; b++) {
            if(lin[b-1]=='O')
                mapa[i] |= (1<<b);
        }
    }
    for(int i=NB; i; i--)
        ans = min(ans, calcNmo(i));
    printf("%d\n", ans);
}

int main() {
    N = 10;
    NB = ((1<<10)-1)<<1;
    char nam[15];
    while(gets(nam) && strcmp(nam, "end")) {
        printf("%s ", nam);
        testCase();
    }
}
