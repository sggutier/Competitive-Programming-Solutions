#include <bits/stdc++.h>
using namespace std;
const int limB = 12;
const int limMsk = (1<<limB);

bool usd[limMsk];
int minRemMemo[limMsk];

inline bool on(const int &num, const int &msk) {
    return ((1<<num) & msk)!=0;
}

int minRem(int msk) {
    if(usd[msk])
        return minRemMemo[msk];
    usd[msk] = true;
    int cnt = (msk&1), ans = (1<<30);
    if(on(11, msk))
        cnt ++;
    for(int i=1; i<11; i++) {
        if(!on(i, msk))
            continue;
        cnt ++;
        if((on(i-1, msk) != on(i+1, msk)))
            ans = min(ans, minRem(((msk ^ (1<<(i-1)))^(1<<i))^(1<<(i+1))));
    }
    return minRemMemo[msk] = min(ans, cnt);
}

void testCase() {
    char str[50];
    scanf("%s", str);
    int msk = 0;
    for(int i=0; i<limB; i++)
        if(str[i]=='o')
            msk += (1<<i);
    printf("%d\n", minRem(msk));
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
}
