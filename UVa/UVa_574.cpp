#include <bits/stdc++.h>
using namespace std;

int numCnt ;
int ans[15];
int numRem[15], numVals[15];
bool posb ;

void bruta(int sum, int pos=0, int ansCnt=0) {
    if(sum==0) {
        posb = true;
        for(int i=0; i<ansCnt; i++)
            printf("%d%c", ans[i], i==ansCnt-1? '\n' : '+');
        return;
    }
    if(sum<0 || pos>=numCnt)
        return;
    if(numRem[pos]) {
        ans[ansCnt] = numVals[pos];
        numRem[pos] --;
        bruta(sum-numVals[pos], pos, ansCnt+1);
        numRem[pos] ++;
    }    
    bruta(sum, pos+1, ansCnt);
}

void testCase(int sum, int b) {
    numCnt = 0;
    posb = false;
    int nums[15];
    for(int i=0; i<b; i++)
        scanf("%d", &nums[i]);
    sort(nums, nums+b);
    reverse(nums, nums+b);

    numCnt = 0;
    memset(numRem, 0, sizeof(numRem));
    for(int i=0; i<b; i++) {
        if(!i || nums[i]!=nums[i-1])
            numVals[numCnt++] = nums[i];
        numRem[numCnt-1] ++;
    }

    printf("Sums of %d:\n", sum);
    bruta(sum);    
    if(!posb)
        printf("NONE\n");
}

int main() {
    int a, b;

    while(scanf("%d%d", &a, &b)!=EOF && (a || b))
        testCase(a, b);
    
    return 0;
}
