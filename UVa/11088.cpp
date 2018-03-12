#include <bits/stdc++.h>
using namespace std;
const int limN = 15;

int contCnt;
int cont[limN];
int mtnMemo[1<<limN];
bool usd[1<<limN];

int mtn(int msk=0, int pos=0) {
    if(usd[msk])
        return mtnMemo[msk];
    usd[msk] = true;
    int ans = 0;
    for(; msk&(1<<pos); pos++);
    if(pos<contCnt)
        ans = mtn(msk ^ (1<<pos), pos+1);
    for(int i=pos+1; i<contCnt; i++) {
        if((1<<i) & msk)
            continue;
        for(int j=i+1; j<contCnt; j++) {
            if((1<<j) & msk)
                continue;
            ans = max(ans, (cont[pos] + cont[i] + cont[j] >= 20)
                      + mtn((((msk ^ (1<<pos)) ^ (1<<i))^(1<<j)), pos+1));
        }
    }
    return mtnMemo[msk] = ans;
}

void testCase() {
    memset(usd, 0, sizeof(int)*(1<<contCnt));
    for(int i=0; i<contCnt; i++)
        scanf("%d", &cont[i]);
    printf("%d\n", mtn());
}

int main() {
    for(int i=1; scanf("%d", &contCnt)!=EOF && contCnt; i++) {
        printf("Case %d: ", i);
        testCase();
    }
}
