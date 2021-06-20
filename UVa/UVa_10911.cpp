#include <bits/stdc++.h>
using namespace std;
#define par pair<int, int>
#define x first
#define y second
const int limN = 16;
const int limB = (1<<16);

int contCnt;
double minDstMemo[limB];
double dst[limN][limN];

double minDst(int msk, int pos) {
    if(minDstMemo[msk]!=-1.0)
        return minDstMemo[msk];
    minDstMemo[msk] = (1<<30)*1.0;
    for(; (1<<pos)&msk; pos++);
    for(int i=pos+1; i<contCnt; i++) {
        if((1<<i) & msk)
            continue;
        minDstMemo[msk] = min(minDstMemo[msk], dst[pos][i] + minDst(((msk ^ (1<<pos)) ^ (1<<i)), pos+1));
    }
    return minDstMemo[msk];
}

void testCase() {
    pair <string, par> contestants[limN];
    
    contCnt *= 2;
    for(int i=(1<<contCnt)-1; i>=0; i--) {
        minDstMemo[i] = -1.0;
    }
    minDstMemo[(1<<contCnt)-1] = 0.0;

    for(int i=0; i<contCnt; i++) {
        char tmp[30];
        scanf("%s", tmp);
        contestants[i].x = tmp;
        scanf("%d%d", &contestants[i].y.x, &contestants[i].y.y);
        for(int j=0; j<=i; j++) {
            double difX = contestants[i].y.x - contestants[j].y.x;
            double difY = contestants[i].y.y - contestants[j].y.y;
            dst[i][j] = dst[j][i] = sqrt(difX*difX + difY*difY);
        }
    }

    printf("%.2lf\n", minDst(0, 0));
}

int main() {
    for(int tc=1; scanf("%d", &contCnt)!=EOF && contCnt; tc++) {
        printf("Case %d: ", tc);
        testCase();
    }
    
    return 0;
}
