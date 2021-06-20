#include <bits/stdc++.h>
using namespace std;

void testCase(int N) {
    vector <int> deg(N);
    vector <vector<int>> adj(N);
    vector <int> ways(N);

    int ans = 0;

    for(int i=0; i<N; i++) {
        int K;
        scanf("%d", &K);
        adj[i].resize(K);
        for(int j=0; j<K; j++) {
            scanf("%d", &adj[i][j]);
            deg[adj[i][j]] ++;
        }
    }

    queue <int> Q;
    Q.push(0);
    ways[0] = 1;
    while(!Q.empty()) {
        int pos = Q.front(); Q.pop();
        int k = ways[pos];
        for(const int &sig:adj[pos]) {
            ways[sig] += k;
            if((--deg[sig])==0)
                Q.push(sig);
        }
        if(!adj[pos].size())
            ans += k;
    }

    printf("%d\n", ans);
}

int main() {
    int n;
    int tc = 0;
    while(scanf("%d", &n)!=EOF) {
        if(tc++)
            printf("\n");
        testCase(n);
    }
}


