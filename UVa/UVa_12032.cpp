#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5 ;

bool itWorks(int numCnt, int *nums, int st) {
    for(int i=0, lst=0; i<numCnt; i++) {
        if(nums[i]-lst>st)
            return false;
        if(st==nums[i]-lst)
            st --;
        lst = nums[i];
    }
    return true;
}

void testCase() {
    int numCnt;
    int nums[limN];
    int ini=0, fin = 1e7;

    scanf("%d", &numCnt);
    for(int i=0; i<numCnt; i++)
        scanf("%d", &nums[i]);

    while(ini<fin) {
        int piv = (ini+fin)/2;
        if(itWorks(numCnt, nums, piv))
            fin = piv;
        else
            ini = piv+1;
    }
    printf("%d\n", ini);    
}

int main() {
    int tc;

    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("Case %d: ", i);
        testCase();
    }

    return 0;
}
