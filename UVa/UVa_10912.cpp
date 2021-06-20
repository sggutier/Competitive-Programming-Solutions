#include <bits/stdc++.h>
using namespace std;
const int limN = 1e4 + 3;

int waysMemo[27][limN][27];
bool usd[27][limN][27];

int ways(int len, int sum, int ult=0) {
    if(usd[len][sum][ult])
        return waysMemo[len][sum][ult];
    usd[len][sum][ult] = true;
    if(len==0) {
        return waysMemo[len][sum][ult] = (sum==0);
    }
    int ans = 0;
    for(int i=min(26, sum); i>ult; i--) {
        ans += ways(len-1, sum-i, i);
    }
    return waysMemo[len][sum][ult] = ans;
}

int testCase(int maxN, int maxK) {
    if(maxN>26)
        return 0;
    return ways(maxN, maxK);
}

int main() {
    int maxN, maxK;
    int tc = 0;
    while(scanf("%d%d", &maxN, &maxK)!=EOF && (maxN || maxK))
        printf("Case %d: %d\n", ++tc, testCase(maxN, maxK));
    
    return 0;
}
