#include <bits/stdc++.h>
using namespace std;
const int inf = (1<<29);
const int limN = 30;

int N, E;
vector <int> adj[limN];

int calcMaxDst(int pos, int pos2) {
    queue <int> Q;
    vector <int> minP(N, 0);
    minP[pos] = 1;
    minP[pos2] = 1;
    int ans = 0, d;
    Q.push(pos);
    Q.push(pos2);
    //printf("Starting at %d %d\n", pos, pos2);
    while(!Q.empty()) {
        pos = Q.front(); Q.pop();
        d = minP[pos]+1;
        //printf("%d %d\n", pos, d-2);
        ans = max(ans, d-2);
        for(const int &sig:adj[pos]) {
            if(minP[sig])
                continue;
            minP[sig] = d;
            Q.push(sig);
        }
    }
    //printf("Min dst is %d\n", ans);
    return ans;
}

void testCase() {
    scanf("%d%d", &N, &E);
    for(int i=0; i<N; i++) {
        adj[i].clear();
    }
    for(int i=0; i<E; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        //printf("join %d %d\n", a, b);
    }

    int ans = (1<<30);
    for(int i=0; i<N; i++) {
        ans = min(ans, 2*calcMaxDst(i, i));
        for(const int &j:adj[i])
            ans = min(ans, 2*calcMaxDst(i, j) + 1);
    }
    printf("%d\n", ans);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("Case #%d:\n", i);
        testCase();
        printf("\n");
    }
    
    return 0;
}
