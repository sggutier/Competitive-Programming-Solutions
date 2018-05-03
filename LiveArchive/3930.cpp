#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define f first
#define s second
const int limN = 13;
const int limP = 1594323;

int maxBajMemo[limP];
bool usd[limP];
int pots3[limN];

int maxBaj(int msk, int crgs[limN]) {
    if(usd[msk])
        return maxBajMemo[msk];
    // printf("Max baj: %d => ", msk);
    // for(int i=0; i<limN; i++)
    //     printf("%d ", crgs[i]);
    // printf("\n");
    usd[msk] = true;
    int &ans = maxBajMemo[msk];
    for(int i=0; i<limN; i++) {
        if(!crgs[i]) continue;
        crgs[i] --;
        msk -= pots3[i];
        for(int j=i; j<limN; j++) {
            if(!crgs[j]) continue;
            msk -= pots3[j];
            crgs[j] --;
            for(int k=min(limN-1, i+j); k>=j; k--) {
                if(!crgs[k]) continue;
                msk -= pots3[k];
                crgs[k] --;
                ans = max(ans, 1 + maxBaj(msk, crgs));
                crgs[k] ++;
                msk += pots3[k];
            }
            crgs[j] ++;
            msk += pots3[j];
        }
        crgs[i] ++;
        msk += pots3[i];
    }
    return ans;
}

pii calcPts(int crg[limN]) {
    int gd = 0;
    int msk = 0;
    for(int i=0; i<limN; i++) {
        gd += crg[i] / 3;
        crg[i] %= 3;
        msk += crg[i]*pots3[i];
        // printf("%d ", crg[i]);
    }
    // printf(" => %d\n", msk);
    return {gd, maxBaj(msk, crg)};
}

int testCase(int N) {
    int crg[2][limN];
    memset(crg, 0, sizeof(crg));
    for(int i=0, a; i<N; i++) {
        scanf("%d", &a);
        crg[i%2][a-1]++;
    }
    pii A, B ;
    A = calcPts(crg[0]);
    B = calcPts(crg[1]);
    return (A>B? 1 : (B>A? 2 : 0));
}

int main() {
    pots3[0] = 1;
    for(int i=1; i<limN; i++)
        pots3[i] = 3*pots3[i-1];
    int N ;
    while(scanf("%d", &N)!=EOF && N)
        printf("%d\n", testCase(N));
}
