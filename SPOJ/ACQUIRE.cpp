#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
typedef long long ll;
typedef pair<int, int> pii;
#define f first
#define s second

int N ;
ll A[limN], B[limN], dp[limN];

long double pend(int p, int q) {
    return ((long double) (dp[p] - dp[q]) ) / (B[p] - B[q]) ; 
}

int main() {
    deque <int> Q;
    int W ;
    pii ters[limN];

    scanf("%d", &W);
    for(int i=0; i<W; i++) {
        scanf("%d%d", &ters[i].f, &ters[i].s);
    }

    sort(ters, ters+W);
    for(int i=0; i<W; i++) {
        while(N > 0 && B[N-1] <= ters[i].s)
            N --;
        N++;
        A[N] = ters[i].f, B[N-1] = ters[i].s;
    }

    dp[0] = 0;
    Q.push_back(0);
    for(int i=1; i<=N; i++) {
        while(Q.size() >= 2) {
            int p = Q.back(); Q.pop_back();
            int q = Q.back();
            if(dp[p] + B[p]*A[i] < dp[q] + B[q]*A[i]) {
            // if( pend(p, q)  < -A[i]) {
                Q.push_back(p);
                break;
            }
        }
        // printf("Antes => ");
        // for(int i=0; i<(int) Q.size(); i++) {
        //     printf("[%lld %lld] ", A[Q[i]], B[Q[i]]);
        // }
        // printf("\n");
        int w = Q.back();
        dp[i] = dp[w] + B[w]*A[i];
        // printf("=> %lld (%d)\n", dp[i], w);
        while(Q.size() >= 2) {
            int p = Q.front(); Q.pop_front();
            int q = Q.front();
            // if( pend(q, p) >= pend(p, i) ) {
            ll X = (dp[q] - dp[p]), Y = (dp[p] - dp[i]);
            if( X * (B[p] - B[i]) > Y * (B[q] - B[p]) ) {
                // printf("Inter %lld %lld | %lld %lld | %lld %lld\n", dp[q], B[q], dp[p], B[p], dp[i], B[i]);
                Q.push_front(p);
                break;
            }
        }
        Q.push_front(i);
    }

    printf("%lld\n", dp[N]);
}
