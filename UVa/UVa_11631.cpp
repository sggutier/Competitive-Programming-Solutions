#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
#define f first
#define s second

int primo(vector <list<par>> &adj) {
    priority_queue <par> Q ;
    int ans = 0;
    vector <bool> usd((int) adj.size());
    Q.push(par(0, 0));
    while(!Q.empty()) {
        par act = Q.top(); Q.pop();
        if(usd[act.s])
            continue;
        usd[act.s] = true ;
        ans -= act.f ;
        for(auto &e: adj[act.s]) {
            Q.push(e);
        }
    }
    return ans;
}

void testCase(int nodeCnt, int edjCnt) {
    vector <list<par>> adj(nodeCnt);
    int sum = 0 ;
    for(int i=0; i<edjCnt; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back(par(-c, b));
        adj[b].push_back(par(-c, a));
        sum += c;
    }
    printf("%d\n", sum - primo(adj));
}

int main() {
    int a, b;

    while(scanf("%d%d", &a, &b)!=EOF && (a || b)) {
        testCase(a, b);
    }
    
    return 0;
}
