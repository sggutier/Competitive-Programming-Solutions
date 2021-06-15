#include <bits/stdc++.h>
using namespace std;
const int limN = 13;
const int limB = 1<<limN;
typedef long long ll;

int N ;
int bitCnt[limB], bitId[limB];
bool forbSet[limB];
int nbGps[limB];
int nbrs[limN], chld[limN];

bool usdUn[limB], usdRt[limN][limB];
ll memoUn[limB], memoRt[limN][limB];

void markBts(int pos=limN-1, int msk=0, int acum=0);
ll waysRt(int rt, int msk) ;
ll waysUn(int msk) ;

ll recursa(int rt, int msk, int ult=0) {
    if(msk==0)
        return 1;
    ll ans = 0;
    for(int s=msk, w; s>ult; s=(s-1)&msk) {
        if(forbSet[s] || (nbGps[s] & (s|(1<<rt))) != nbGps[s]  )
            continue;
        w = nbrs[rt] & s;
        if(bitCnt[w] == 0)
            ans += waysUn(s) * recursa(rt, msk-s, s);
        else if(bitCnt[w]==1)
            ans += waysRt(bitId[w], s-(1<<bitId[w])) * recursa(rt, msk-s, s);
    }
    return ans;
}

ll waysRt(int rt, int msk) {
    if(usdRt[rt][msk])
        return memoRt[rt][msk];
    usdRt[rt][msk] = true;
    if( (chld[rt] & msk) != chld[rt] )
        return 0;
    if(msk==0) {
        // printf("RT: %d %d => %lld [%d %d]\n", rt, msk, 1LL, chld[rt], nbrs[rt]);
        return memoRt[rt][msk] = 1;
    }
    return memoRt[rt][msk] = recursa(rt, msk);
    // memoRt[rt][msk] = recursa(rt, msk);
    // printf("RT: %d %d => %lld [%d %d]\n", rt, msk, memoRt[rt][msk], chld[rt], nbrs[rt]);
    // return memoRt[rt][msk];
}

ll waysUn(int msk) {
    if(msk==0)
        return 1;
    if(usdUn[msk])
        return memoUn[msk];
    usdUn[msk] = true;
    for(int i=0; i<N; i++)
        if((1<<i) & msk)
            memoUn[msk] += waysRt(i, msk - (1<<i));
    // printf("URT: %d => %lld\n", msk, memoUn[msk]);
    return memoUn[msk];
}

int main() {
    markBts();
    for(int i=0; i<limN; i++)
        bitId[1<<i] = i;
    
    int E, Q ;

    scanf("%d%d%d", &N, &E, &Q);
    for(int i=0; i<E; i++) {
        int a, b ;
        scanf("%d%d", &a, &b);
        a--, b--;
        nbrs[a] |= 1<<b;
        nbrs[b] |= 1<<a;
    }
    for(int i=0; i<Q; i++) {
        int a, b, c ;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--, c--;
        if(a==b && a==c) continue;
        if(a==b && a!=c) {
            printf("0\n");
            return 0;
        }
        if(a==c || b==c) {
            if(a!=c) swap(a, b);
            chld[c] |= 1<<b;
        }
        else {
            // printf("anadiendo %d y %d a %d\n", 1<<b, 1<<a, c);
            chld[c] |= 1<<b;
            chld[c] |= 1<<a;
            for(int j=(1<<N)-1; j>=0; j--) 
                if( (j&(1<<a)) && (j&(1<<b)) && !(j&(1<<c)) ) {
                    forbSet[j] = true;
                    // printf("\t %d prohibido\n", i);
                }
        }
    }

    for(int b=(1<<N)-1; b>=0; b--) {
        int s = 0;
        for(int i=0; i<N; i++)
            if((1<<i) & b)
                s |= nbrs[i];
        nbGps[b] = s;
    }

    printf("%lld\n", waysRt(0, (1<<N)-2));
}

void markBts(int pos, int msk, int acum) {
    if(pos==-1) {
        bitCnt[msk] = acum;
        return;
    }
    markBts(pos-1, msk, acum);
    markBts(pos-1, msk | (1<<pos), acum + 1);
}
