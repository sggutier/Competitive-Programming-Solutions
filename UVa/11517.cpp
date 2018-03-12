#include <bits/stdc++.h>
using namespace std;
const int limC = 2e4 + 1;
const int inf = (1<<30);

void testCase() {
    int price;
    int coinCnt;
    vector <int> minReq(limC, inf);
    scanf("%d%d", &price, &coinCnt);
    minReq[0] = 0;
    while(coinCnt--) {
        int a;
        scanf("%d", &a);
        for(int i=limC-1; i>=a; i--) {
            minReq[i] = min(minReq[i], minReq[i-a]+1);
        }
    }
    for(int i=price; i<limC; i++) {
        if(minReq[i]!=inf) {
            printf("%d %d\n", i, minReq[i]);
            break;
        }
    }
}

int main() {
    int tc;

    scanf("%d", &tc);
    while(tc--) {
        testCase();
    }
    
    return 0;
}
