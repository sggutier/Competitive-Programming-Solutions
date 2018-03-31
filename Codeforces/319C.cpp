#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
typedef long long ll;

int N ;
ll A[limN], B[limN], dp[limN];

long double pend(int p, int q) {
    return ((long double) (dp[p] - dp[q]) ) / (B[p] - B[q]) ; 
}

int main() {
    deque <int> Q;

    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%lld", &A[i]);
    for(int i=0; i<N; i++)
        scanf("%lld", &B[i]);

    dp[0] = 0;
    Q.push_back(0);
    for(int i=1; i<N; i++) {
        while(Q.size() >= 2) {
            int p = Q.back(); Q.pop_back();
            int q = Q.back();
            if(dp[p] + B[p]*A[i] < dp[q] + B[q]*A[i]) {
            // if( pend(p, q)  < -A[i]) {
                Q.push_back(p);
                break;
            }
        }
        int w = Q.back();
        dp[i] = dp[w] + B[w]*A[i];
        while(Q.size() >= 2) {
            int p = Q.front(); Q.pop_front();
            int q = Q.front();
            // if( pend(q, p) >= pend(p, i) ) {
            if( (dp[q] - dp[p]) * (B[p] - B[i]) >= (dp[p] - dp[i]) * (B[q] - B[p]) ) {
                Q.push_front(p);
                break;
            }
        }
        Q.push_front(i);
    }

    printf("%lld\n", dp[N-1]);
}
