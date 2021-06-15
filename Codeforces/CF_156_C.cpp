#include <bits/stdc++.h>
using namespace std;
const int limN = 105;
const int limC = 26*limN;
const int mod = 1e9 + 7;

int dp[limN][limC];
bool usd[limN][limC];

int ways(int rem, int k) {
    if(rem == 0)
        return k==0? 1 : 0;
    if(usd[rem][k])
        return dp[rem][k];
    usd[rem][k] = true;
    if(k > 25*rem)
        return 0;
    int &ans = dp[rem][k];
    for(int i=min(25, k); i>=0; i--)
        ans = (ans + ways(rem-1, k-i)) % mod;
    return ans ;
}

void testCase() {
    char S[limN];
    int sum = 0;
    int N ;
    scanf("%s", S);
    N = strlen(S);
    for(int i=0; i<N; i++)
        sum += S[i]-'a';
            
    int ans = (ways(N, sum) + mod - 1) % mod;
    printf("%d\n", ans);
}

int main() {
    int tc;
    for(scanf("%d", &tc); tc; tc--)
        testCase();
}
