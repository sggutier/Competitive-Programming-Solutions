#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int numCnt, sumTot=0;
    scanf("%d", &numCnt);
    int nums[numCnt];
    int ans[numCnt];
    memset(ans, 0, sizeof(ans));
    for(int i=0; i<numCnt; i++) {
        scanf("%d", &nums[i]);
        sumTot += nums[i];
    }
    for(int b=(1<<numCnt)-1; b>0; b--) {
        int sum = 0, bCnt = 0;
        for(int i=0; i<numCnt; i++) {
            if((1<<i) & b) {
                sum += nums[i];
                bCnt ++;
            }
        }
        if(sum*2<=sumTot || bCnt<2)
            continue;
        for(int i=0; i<numCnt; i++) {
            if((1<<i) & b) {
                if((sum - nums[i])*2 <= sumTot)
                    ans[i] ++;
            }
        }
    }
    for(int i=0; i<numCnt; i++) {
        printf("party %d has power index %d\n", i+1, ans[i]);
    }
}

int main() {
    int tc;

    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        testCase();
        printf("\n");
    }
    
    return 0;
}
