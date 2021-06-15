#include <bits/stdc++.h>
using namespace std;

int main() {
    string S ;
    cin >> S ;
    int n = S.size();
    int ans = 26;
    vector <int> dp(n, 0);
    for(int i=0; i<n; i++) {
        dp[i] = 1;
        for(int j=i-1; j>=0; j--)
            if(S[j] < S[i])
                dp[i] = max(dp[i], dp[j]+1);
        ans = min(ans, 26-dp[i]);
    }
    printf("%d\n", ans);
}
