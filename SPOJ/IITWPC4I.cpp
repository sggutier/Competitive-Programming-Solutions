#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define f first
#define s second

void testCase() {
    int N, E ;
    priority_queue <pii> Q ;

    scanf("%d%d", &N, &E);
    for(int i=0, a; i<N; i++) {
        scanf("%d", &a);
        if(a)
            Q.push({0, i});
    }

    vector<vector <pii> > adj(N);
    vector <bool> usd(N);
    for(int i=0, a, b, c; i<E; i++) {
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        adj[a].push_back({-c, b});
        adj[b].push_back({-c, a});
    }

    long long ans = 0;
    int cnt = 0;
    while(!Q.empty()) {
        int pos = Q.top().s, d = -Q.top().f;
        Q.pop();
        if(usd[pos])
            continue;
        usd[pos] = true;
        cnt ++;
        ans += d;
        for(const pii e : adj[pos])
            Q.push(e); 
    }

    if(cnt != N)
        printf("impossible\n");
    else
        printf("%lld\n", ans);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(; tc; tc--)
        testCase();
}
