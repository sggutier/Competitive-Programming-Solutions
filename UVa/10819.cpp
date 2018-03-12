#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int testCase(int pMon, vector <pii> &clothes) {
    vector <int> dp(pMon+201, -1);
    int n = pMon + 200;
    dp[0] = 0;
    for(const auto &c:clothes) {
        for(int i=n; i>=c.first; i--) {
            if(dp[i-c.first] >= 0)
                dp[i] = max(dp[i], dp[i-c.first] + c.second);
        }
    }
    int ans = 0;
    for(int i=0; i<=pMon; i++)
        ans = max(ans, dp[i]);
    for(int i=2001; i<=n; i++)
        ans = max(ans, dp[i]);
    return ans;
}

int main() {
    int a, b;
    while(scanf("%d%d", &a, &b)!=EOF && (a || b)) {
        vector <pii> clothes(b);
        for(int i=0; i<b; i++)
            scanf("%d%d", &clothes[i].first, &clothes[i].second);
        printf("%d\n", testCase(a, clothes));
    }            
}
