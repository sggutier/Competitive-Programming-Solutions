#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int prices[25];
    int reqCnt, money;
    scanf("%d%d", &money, &reqCnt);
    bool posb[money+1], posbB[money+1];
    memset(posb, 0, sizeof(posb));
    posb[0] = 1;
    bool *act=&posb[0], *sig=&posbB[0];

    while(reqCnt--) {
        memset(sig, 0, sizeof(posb));
        int pCnt;
        scanf("%d", &pCnt);
        for(int i=0; i<pCnt; i++)
            scanf("%d", &prices[i]);
        for(int i=money; i>0; i--) {
            for(int j=0; j<pCnt; j++) {
                if(i-prices[j]>=0 && act[i-prices[j]]) {
                    sig[i] = true;
                    break;
                }
            }
        }
        swap(act, sig);
    }

    for(int i=money; i>=0; i--) {
        if(act[i]) {
            printf("%d\n", i);
            return ;
        }
    }
    printf("no solution\n");
}

int main() {
    int tc;
    scanf("%d", &tc);

    while(tc--)
        testCase();
    
    return 0;
}
