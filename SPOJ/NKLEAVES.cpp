#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
const int limK = 11;
typedef long long ll;

int N, K ;
int nums[limN];
ll acum[limN], tot[limN];
ll dp[limK][limN];
ll m[limN];
deque <int> Q ;

int main() {
    scanf("%d%d", &N, &K);
    for(int i=0; i<N; i++)
        scanf("%d", &nums[i]);

    for(int i=N-1; i>=0; i--) {
        acum[i] = acum[i+1] + tot[i+1];
        tot[i] = nums[i] + tot[i+1];
        dp[0][i] = m[i] = (1LL<<61);
    }

    Q.push_back(N);
    for(int k=1; k<=K; k++) {
        for(int i=0; i<N; i++) {
            // dp[k][i] = (1LL<<62);
            // for(int j=i+1; j<=N; j++) {
            //     dp[k][i] = min(dp[k][i], m[j]  + i * tot[j]);
            // }
            while(Q.size() >= 2) {
                int p = Q.back(); Q.pop_back();
                int q = Q.back();
                if(m[p] + tot[p] * i < m[q] + tot[q] * i) {
                    Q.push_back(p);
                    break;
                }
            }
            int w = Q.back();
            dp[k][i] = m[w] + tot[w] * i;
            dp[k][i] += acum[i];
        }
        Q.clear();
        for(int i=0; i<N; i++)
            m[i] = dp[k][i] - tot[i]*i - acum[i];
        for(int i=0; i<=N; i++) {
            while(Q.size() >= 2) {
                int p = Q.front(); Q.pop_front();
                int q = Q.front();
                if( (m[q] - m[p]) * (tot[p] - tot[i]) >= (m[p] - m[i]) * (tot[q] - tot[p]) ) {
                    Q.push_front(p);
                    break;
                }
            }
            Q.push_front(i);
        }
    }

    printf("%lld\n", dp[K][0]);
}
