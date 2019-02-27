#include <bits/stdc++.h>
using namespace std;
const int limN = 1003;
const int limK = 7;

int N, K;
int nms[limK][limN];
vector <int> adj[limN];

int dp[limN];

int memo(int pos) {
    if(dp[pos] != -1)
        return dp[pos];
    int &ans = dp[pos] ;
    ans = 0;
    for(const int sg : adj[pos])
        ans = max(ans, memo(sg));
    ans ++;
    return ans;
}

int main() {
    scanf("%d%d", &N, &K);
    for(int i=0; i<K; i++) {
        for(int a, j=0; j<N; j++) {
            scanf("%d", &a);
            nms[i][a] = j;
        }
    }

    for(int i=1; i<=N; i++) {
        dp[i] = -1;
        for(int j=1; j<=N; j++) {
            if(i==j) continue;
            bool fca = true;
            for(int w=0; w<K; w++) {
                if(nms[w][j] < nms[w][i])
                    fca = false;
            }
            if(fca)
                adj[i].push_back(j);
        }
    }

    int ans = 0;

    for(int i=1; i<=N; i++)
        ans = max(ans, memo(i));

    printf("%d\n", ans);
}
