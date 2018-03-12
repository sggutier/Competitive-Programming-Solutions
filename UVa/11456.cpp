#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;
const int limN = 2e4 ;
const int inf = (1<<30);

int numCnt;
int nums[limN];
int lis[limN], lds[limN];
int smallCnt ;
int smalls[limN];

void calcLIS(int *ans) {
    smalls[0] = -inf;
    smallCnt = 1;
    for(int i=0; i<numCnt; i++) {
        int pos = upper_bound(smalls, smalls+smallCnt, nums[i]) - smalls;
        ans[i] = pos;
        smalls[pos] = nums[i];
        smallCnt = max(smallCnt, pos+1);
    }
}

void testCase() {
    scanf("%d", &numCnt);
    for(int i=0; i<numCnt; i++)
        scanf("%d", &nums[numCnt-1-i]);
    //  << "hiar" << endl;
    // printf("hira\n");
    calcLIS(lis);
    for(int i=0; i<numCnt; i++)
        nums[i] *= -1;
    calcLIS(lds);
    int ans = 0;
    for(int i=0; i<numCnt; i++)
        ans = max(ans, lis[i] + lds[i] - 1);
    printf("%d\n", ans);
}

int main() {
    int tc;

    scanf("%d", &tc);
    while(tc--)
        testCase();
    
    return 0;
}
