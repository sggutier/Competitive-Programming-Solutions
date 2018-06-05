#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
#define f first
#define s second

int main() {
    int N, K;
    ll sumo = 0;
    priority_queue <pli> Q;

    Q.push({0, 0});

    scanf("%d%d", &N, &K);
    K ++;
    for(int i=1, a; i<=N; i++) {
        scanf("%d", &a);
        sumo += a;
        while(Q.top().s < i-K)
            Q.pop();
        Q.push({Q.top().f - a, i});
    }
    while(Q.top().s < N+1-K)
        Q.pop();

    printf("%lld\n", sumo + Q.top().f);
}
