#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> edg;
const int limN = 1e5 + 5;

vector <edg> adj[limN];
int tip[limN];
bool usd[limN];

int main() {
    priority_queue <edg> Q ;
    int N, E;

    scanf("%d%d", &N, &E);
    for(int i=0, a, b, c; i<E; i++) {
        scanf("%d%d%d", &a, &b, &c);
        adj[a].emplace_back(-c, b, i);
        adj[b].emplace_back(-c, a, i);
    }

    Q.emplace(0, 1, E);
    while(!Q.empty()) {
        int cst, pos, id;
        tie(cst, pos, id) = Q.top(); Q.pop();
        if(usd[pos]) continue;
        printf("=> %d %d %d\n", -cst, pos, id);
        while(!Q.empty()) {
            int cstS, sig, idS;
            tie(cstS, sig, idS) = Q.top(); Q.pop();
            printf("\t=> %d %d %d\n", -cstS, sig, idS);
            if(usd[sig])
                continue;
            printf("\t se conserva\n");
            Q.emplace(cstS, sig, idS);
            if(cstS == cst)
                tip[id] = tip[idS] = 1;
            break;
        }
        usd[pos] = true;
        if(tip[id]==0)
            tip[id] = 2;
        for(const auto &sig : adj[pos])
            Q.push(sig);
    }

    for(int i=0; i<E; i++)
        printf("%s\n", tip[i]==0? "none" : (tip[i]==1? "at least one" : "any"));
}
