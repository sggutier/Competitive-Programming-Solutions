#include <bits/stdc++.h>
using namespace std;
typedef int ll;
const int limN = 16;
const int limB = (1<<16);

int nodCnt;
ll minDstMemo[limB];
ll dst[limN][limN];
int deg[limN];

ll minDst(int msk, int pos) {
    if(minDstMemo[msk] != -1)
        return minDstMemo[msk];
    minDstMemo[msk] = (1<<30);
    for(; (1<<pos)&msk; pos++);
    for(int i=pos+1; i<nodCnt; i++) {
        if(((1<<i) & msk) || dst[pos][i]==0)
            continue;
        minDstMemo[msk] = min(minDstMemo[msk], dst[pos][i] + minDst(((msk ^ (1<<pos)) ^ (1<<i)), pos+1));
    }
    return minDstMemo[msk];
}

void testCase() {
    memset(deg, 0, sizeof(deg));
    memset(dst, 0, sizeof(dst));
    for(int i=(1<<nodCnt)-1; i>=0; i--)
        minDstMemo[i] = -1;
    minDstMemo[(1<<nodCnt)-1] = 0;

    int edgCnt;
    int mskIni = 0, posIni = 0;
    ll ans = 0;

    scanf("%d", &edgCnt);
    for(int i=0; i<edgCnt; i++) {
        int a, b;
        ll c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        if(a!=b) {
            if(dst[a][b]==0) {
                dst[a][b] = c;
                dst[b][a] = c;
            }
            else if(dst[b][a] > c) {
                dst[a][b] = c;
                dst[b][a] = c;
            }
            deg[a] = 1-deg[a];
            deg[b] = 1-deg[b];
        }
        ans += c;
    }

    for(int i=nodCnt-1; i>=0; i--) {
        if(deg[i]==0)
            mskIni += (1<<i);
        else
            posIni = i;
    }

    // for(int i=0; i<nodCnt; i++) {
    //     for(int j=0; j<nodCnt; j++)
    //         printf("%d ", dst[i][j]);
    //     printf("\n");
    // }

    // printf("=> ");
    // for(int i=0; i<nodCnt; i++)
    //     printf("%d ", (1<<i) & mskIni? 1 : 0);
    // printf("\n");
    // printf("%d (%d)\n", posIni, ans);

    for(int k=0; k<nodCnt; k++)
        for(int i=0; i<nodCnt; i++)
            for(int j=0; j<nodCnt; j++)
                if(i!=j && dst[i][k] && dst[k][j])
                    dst[i][j] = dst[i][j]==0? dst[i][k] + dst[k][j] : min(dst[i][j], dst[i][k] + dst[k][j]);

    // for(int i=0; i<nodCnt; i++) {
    //     for(int j=0; j<nodCnt; j++)
    //         printf("%d ", dst[i][j]);
    //     printf("\n");
    // }

    ans += minDst(mskIni, posIni);

    printf("%d\n", ans);
}

int main() {
    while(scanf("%d", &nodCnt) && nodCnt)
        testCase();
}
