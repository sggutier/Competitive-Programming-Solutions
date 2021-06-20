#include <bits/stdc++.h>
using namespace std;
const int limN = 1e4 + 5;
typedef pair<int, int> par;
#define f first
#define s second
const int inf = 1e9;

int N, E;
vector <par> adj[limN];
int minP[limN];
int prevo[limN];

void dijkstra(int ini, int fin) {
    priority_queue <par> Q;
    for(int i=0; i<limN; i++)
        minP[i] = inf;
    minP[ini] = 1;
    prevo[ini] = -1;
    Q.push(par(-1, ini));
    //printf("%d === %d\n", ini, fin);
    while(!Q.empty()) {
        int pos = Q.top().s, dst = -Q.top().f;
        Q.pop();
        if(dst!=minP[pos])
            continue;
        //printf("%d => %d %d\n", pos, dst, minP[pos]);
        if(pos==fin) {
            return ;
        }
        for(const par &sig:adj[pos]) {
            int dst2 = sig.f + dst;
            //printf("(%d %d) ", sig.s, dst2);
            if(dst2 < minP[sig.s]) {
                Q.push(par(-dst2, sig.s));
                minP[sig.s] = dst2;
                prevo[sig.s] = pos;
            }
        }
        //printf("\n");
    }
    return ;
}

void testCase() {
    for(int i=0; i<N; i++) {
        adj[i].clear();
        int cnt ;
        scanf("%d", &cnt);
        for(int j=0; j<cnt; j++) {
            int a, b;
            scanf("%d%d", &a, &b);
            a--;
            adj[i].push_back(par(b, a));
        }
    }
    int ini, fin;
    scanf("%d%d", &ini, &fin);
    ini--, fin--;

    dijkstra(ini, fin);

    stack <int> path;
    for(int pos=fin; pos!=-1; pos=prevo[pos]) {
        path.push(pos);
    }

    printf("Path =");
    while(!path.empty()) {
        printf(" %d", path.top()+1);
        path.pop();
    }
    printf("; %d second delay\n", minP[fin]-1);
}


int main() {
    int tc=0;

    while(scanf("%d", &N)!=EOF && N) {
        printf("Case %d: ", ++tc);
        testCase();
    }
    
    return 0;
}
