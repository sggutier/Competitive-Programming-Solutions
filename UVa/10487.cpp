#include <bits/stdc++.h>
using namespace std;
const int limN = 1002;
const int inf = (1<<30);

int combCnt;
int combs[limN*limN];

int masCercano(int k) {
    int pos = lower_bound(combs, combs+combCnt, k) - combs;
    pair<int,int> ans = make_pair(inf, 0);
    if(pos < combCnt)
        ans = make_pair(abs(k-combs[pos]), combs[pos]);
    if(pos)
        ans = min(ans, make_pair(abs(k-combs[pos-1]), combs[pos-1]));
    return ans.second;
}

void testCase(int numCnt) {
    int queryCnt;
    int nums[limN];
    combCnt = 0;

    for(int i=0; i<numCnt; i++) {
        scanf("%d", &nums[i]);
        for(int j=i-1; j>=0; j--)
            combs[combCnt++] = nums[i] + nums[j];
    }
    sort(combs, combs+combCnt);
    scanf("%d", &queryCnt);
    while(queryCnt--) {
        int k;
        scanf("%d", &k);
        printf("Closest sum to %d is %d.\n", k, masCercano(k));
    }
}

int main() {
    int tc=0;
    int a;

    while(scanf("%d", &a)!=EOF && a) {
        printf("Case %d:\n", ++tc);
        testCase(a);
    }
    
    return 0;
}
