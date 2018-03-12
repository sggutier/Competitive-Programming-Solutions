#include <bits/stdc++.h>
using namespace std;
const int limP = 15;
const int limMsk = 1<<limP;
const int limS = 115;
typedef int ll;

bool usd[limMsk + 15][limS];
bool dpMemo[limMsk + 15][limS];
int areas[limMsk + 15];
int bitCnt[limMsk + 15];
bool sePuede(int msk, const int &w);
bool cualcSig(int msk, const int &w, const int &h, int a, int b) ;

bool cualcSig(int msk, const int &w, const int &h, int a, int b) {
    if( msk ) {
        int ub = msk & (-msk);
        return cualcSig(msk - ub, w, h, a | ub, b) ||
               cualcSig(msk - ub, w, h, a, b | ub);
    }
    else if(a && b) {
        if(areas[a]%w==0) {
            if(sePuede(a, w) && sePuede(b, w))
                return true;
        }
        if(areas[a]%h==0) {
            if(sePuede(a, h) && sePuede(b, h))
                return true;
        }
    }
    return false;
}

bool sePuede(int msk, const int &w) {
    if(usd[msk][w])
        return dpMemo[msk][w];
    int h = areas[msk]/w;
    usd[msk][w] = (usd[msk][h] = true);
    if(bitCnt[msk]==1) {        
        return dpMemo[msk][w] = (dpMemo[msk][h] = true);
    }    
    return dpMemo[msk][w] = (dpMemo[msk][h] = cualcSig(msk, w, h, 0, 0));
}

void precarga(const ll *pcs, int pos, int msk=0, int sum=0) {
    if(pos==-1) {
        areas[msk] = sum;
        return;
    }
    precarga(pcs, pos-1, msk, sum);
    precarga(pcs, pos-1, msk | (1<<pos), sum + pcs[pos]);
}

void precargaBts(int pos, int msk=0, int cnt=0) {
    if(pos==-1) {
        bitCnt[msk] = cnt;
        return;
    }
    precargaBts(pos-1, msk, cnt);
    precargaBts(pos-1, msk | (1<<pos), cnt + 1);
}

void testCase(int N) {
    memset(usd, 0, sizeof(usd));
    ll tams[limP];
    int w, h;
    ll suma = 0;

    scanf("%d%d", &w, &h);
    for(int i=0; i<N; i++) {
        // scanf("%lld", &tams[i]);
        scanf("%d", &tams[i]);
        suma += tams[i];
    }

    //cout << suma << endl;
    if(suma!=w*h || suma%w!=0LL) {
        printf("No\n");
        return;
    }

    precarga(tams, N-1);
    
    // for(int i=0; i<(1<<N); i++) {
    //     for(int b=N-1; b>=0; b--) 
    //         printf("%d", (1<<b & i)? 1 : 0);
    //     printf(" %d => %d\n", bitCnt[i], areas[i]);
    // }
    
    if(sePuede((1<<N)-1, w))
        printf("Yes\n");
    else
        printf("No\n");
}

int main() {
    precargaBts(limP-1);
    int tc = 0;
    int n;

    while(scanf("%d", &n)!=EOF && n) {
        printf("Case %d: ", ++tc);
        testCase(n);
    }
    
    return 0;
}
