#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;
const int limW = 1005;

bool usd[limN+1][limW+1];
int maxValMemo[limN+1][limW+1];

int objCnt;
int vals[limN], weighs[limN];

int maxVal(int w, int pos=0) {
    if(usd[pos][w])
        return maxValMemo[pos][w];
    usd[pos][w] = true;
    if(pos==objCnt || w==0) {
        return maxValMemo[pos][w] = 0;
    }
    if(weighs[pos]>w)
        return maxValMemo[pos][w] = maxVal(w, pos+1);
    return maxValMemo[pos][w] = max(maxVal(w, pos+1), maxVal(w-weighs[pos], pos+1) + vals[pos]);
}

void testCase() {
    memset(usd, 0, sizeof(usd));
    // scanf("%d", &objCnt);
    for(int i=0; i<objCnt; i++) {
        scanf("%d%d", &vals[i], &weighs[i]);
    }
    int querCnt;
    scanf("%d", &querCnt);
    int ans = 0;
    int a;
    while(querCnt--) {
        scanf("%d", &a);
        ans += maxVal(a);
    }
    printf("%d\n", ans);
}

int main() {
    int tc;

    while(scanf("%d", &objCnt) != EOF)
        testCase();
    
    return 0;
}
