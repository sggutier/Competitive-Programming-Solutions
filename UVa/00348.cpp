#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 15;

int N ;
int dims[MAX_N][2];
int minMultMemo[MAX_N][MAX_N];
int sigMemo[MAX_N][MAX_N];
int abrCnt[MAX_N], cloCnt[MAX_N];

int minMult(int ini=0, int fin=N-1) {
    if(ini==fin)
        return 0;
    if(sigMemo[ini][fin])
        return minMultMemo[ini][fin];
    int ans = (1<<30), s = ini+1;
    for(int k=ini+1; k<=fin; k++) {
        int d = minMult(ini, k-1) + minMult(k, fin) + dims[ini][0]*dims[k][0]*dims[fin][1];
        if(d < ans) {
            ans = d;
            s = k;
        }
    }
    sigMemo[ini][fin] = s;
    return minMultMemo[ini][fin] = ans;
}

void reconst(int ini=0, int fin=N-1) {
    if(ini==fin)
        return;
    int k = sigMemo[ini][fin];
    if(k!=ini+1) {
        abrCnt[ini]++;
        cloCnt[k-1]++;
    }
    if(k!=fin) {
        abrCnt[k]++;
        cloCnt[fin]++;
    }
    reconst(ini, k-1);
    reconst(k, fin);
}

void testCase() {
    memset(sigMemo, 0, sizeof(sigMemo));
    memset(abrCnt, 0, sizeof(abrCnt));
    memset(cloCnt, 0, sizeof(cloCnt));

    for(int i=0; i<N; i++)
        scanf("%d%d", &dims[i][0], &dims[i][1]);

    minMult();
    reconst();
    printf("(");
    for(int i=0; i<N; i++) {
        if(i)
            printf(" x ");
        for(int j=0; j<abrCnt[i]; j++)
            printf("(");
        printf("A%d", i+1);
        for(int j=0; j<cloCnt[i]; j++)
            printf(")");
    }
    printf(")\n");
}

int main() {
    int tc = 0;
    while(scanf("%d", &N)!=EOF && N) {
        printf("Case %d: ", ++tc);
        testCase();
    }
}
