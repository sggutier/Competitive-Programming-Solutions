#include <bits/stdc++.h>
using namespace std;
const int limN = 105;
typedef pair<int,int> par;
#define f first
#define s second
const int inf = 1<<29;

int nodCnt, edgCnt;
vector <par> adj[limN];
int maxC[limN];

int dijkstraish(int ini, int fin) {
    memset(maxC, 0, sizeof(maxC));
    maxC[ini] = inf;
    priority_queue <par> Q;
    Q.push(par(inf, ini));

    while(!Q.empty()) {
        int pos = Q.top().second, cap = Q.top().first;
        Q.pop();
        if(maxC[pos]>cap)
            continue;
        if(pos==fin)
            return maxC[pos];
        for(const par &edg:adj[pos]) {
            int sig = edg.second, d = min(cap, edg.first);
            if(maxC[sig] < d) {
                maxC[sig] = d;
                Q.push(par(d, sig));
            }
        }
    }

    return 0;
}

void testCase() {
    for(int i=0; i<nodCnt; i++)
        adj[i].clear();

    for(int i=0; i<edgCnt; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--, c--;
        adj[a].push_back(par(c, b));
        adj[b].push_back(par(c, a));
    }
    int ini, fin, p;

    scanf("%d%d%d", &ini, &fin, &p);

    // printf("%d\n", dijkstraish(ini-1, fin-1));
    printf("Minimum Number of Trips = %d\n", (int) ceil((p*1.0)/dijkstraish(ini-1, fin-1)) );
}

int main() {
    int tc = 0;
    
    while(scanf("%d%d", &nodCnt, &edgCnt)!=EOF && (nodCnt || edgCnt)) {
        printf("Scenario #%d\n", ++tc);
        testCase();
        printf("\n");
    }
}
