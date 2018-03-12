#include <bits/stdc++.h>
using namespace std;

void printAns(const int &stNode, const int &ttl, const vector<int> &minP) {
    static int caseN = 1;
    int ans = 0;
    for(const int &p:minP)
        if(p>ttl || p==-1)
            ans ++;
    printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", caseN++, ans, stNode, ttl);
}

void bfs(const vector<list<int>> &edges, vector<int> &minP, int pos) {
    queue <int> Q;
    minP[pos] = 0;
    Q.push(pos);
    while(!Q.empty()) {
        pos = Q.front(); Q.pop();
        for(const int &sig: edges[pos]) {
            if(minP[sig]==-1) {
                Q.push(sig);
                minP[sig] = minP[pos]+1;
            }
        }
    }
}

void testCase(int edgeCnt) {
    map <int, int> dict;
    vector <list<int>> edges ;
    vector <int> minP;

    for(int i=0; i<edgeCnt; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(dict.count(a)==0) {
            dict[a] = edges.size();
            edges.push_back(list<int>());
        }
        if(dict.count(b)==0) {
            dict[b] = edges.size();
            edges.push_back(list<int>());
        }
        a = dict[a], b = dict[b];
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    int st, ttl;
    while(scanf("%d%d", &st, &ttl)!=EOF && (st || ttl)) {
        minP = vector<int>(edges.size(), -1);
        if(dict.count(st))
            bfs(edges, minP, dict[st]);
        printAns(st, ttl, minP);
    }
}

int main() {
    int n;

    while(scanf("%d", &n)!=EOF && n)
        testCase(n);
    
    return 0;
}
