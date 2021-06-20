#include <bits/stdc++.h>
using namespace std;

vector <list<int>> adj;
vector<int> queries;

void bfs(int pos, vector<bool> &usd) {
    queue <int> Q;
    // usd[pos] = true;
    Q.push(pos);
    while(!Q.empty()) {
        pos = Q.front(); Q.pop();
        for(const int &sig:adj[pos]) {
            if(usd[sig])
                continue;
            usd[sig] = true;
            Q.push(sig);
        }
    }
}

void testCase() {
    for(const int &q: queries) {
        vector<bool> usd(adj.size());
        bfs(q, usd);
        int ans = 0;
        for(const int &u: usd)
            if(!u)
                ans ++;
        printf("%d", ans-1);
        for(int i=1; i<(int) adj.size(); i++)
            if(!usd[i])
                printf(" %d", i);
        printf("\n");
    }
}

void getInput(int n) {
    adj = vector<list<int>>(n+1);
    int pos, Q;
    while(scanf("%d", &pos)!=EOF && pos>0) {
        int sig ;
        while(scanf("%d", &sig)!=EOF && sig>0) {
            adj[pos].push_back(sig);
        }
    }
    scanf("%d", &Q);
    queries = vector<int>(Q);
    for(int i=0; i<Q; i++)
        scanf("%d", &queries[i]);

    // printf("%d\n", n);
    // for(int i=1; i<=n; i++) {
    //     printf("%d ---> ", i);
    //     for(const auto &sig:adj[i])
    //         printf("%d ", sig);
    //     printf("\n");
    // }
}

int main() {
    int n;

    while(scanf("%d", &n)!=EOF && n!=0) {
        getInput(n);
        testCase();
    }

    return 0;
}
