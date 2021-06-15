#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define f first
#define s second

const int limN = 2e5 + 5;
const int LE = 1e6 ;

vector <int> adj[limN];
int minP[limN][2];
pii ant[limN][2];
bool actv[limN], rch[limN];

bool dfs(int pos) {
    if(rch[pos])
        return actv[pos];
    rch[pos] = true;
    actv[pos] = true;
    for(const int &sig:adj[pos])
        if(dfs(sig))
            return true;
    actv[pos] = false;
    return false;
}

void printAns(const pii pos) {
    if(pos.f == 0)
        return;
    printAns(ant[pos.f][pos.s]);
    printf("%d ", pos.f);
}

int main() {
    bool hasCicl = false;
	int N, E;
    pii pos;
    int ini ;
    queue <pii> Q ;

    scanf("%d%d", &N, &E);
    for(int i=1; i<=N; i++) {
        int w ;
        scanf("%d", &w);
        adj[i].resize(w);
        for(int &s:adj[i])
            scanf("%d", &s);
    }
    scanf("%d", &pos.f);
    ini = pos.f;

    minP[pos.f][pos.s] = 1;
    Q.push(pos);
    while(!Q.empty()) {
        pos = Q.front(); Q.pop();
        // printf("%d %d viene de %d %d\n", pos.f, pos.s, ant[pos.f][pos.s].f, ant[pos.f][pos.s].s);
        if(adj[pos.f].empty() && pos.s==1 && minP[pos.f][pos.s] < LE) {
            // printf("La anso es de %d\n", minP[pos.f][pos.s]);
            printf("Win\n");
            printAns(pos) ;
            printf("\n");
            return 0;
        }
        if(minP[pos.f][pos.s] >= LE) {
            hasCicl = true;
            break;
        }
        int sp = 1-pos.s, d = minP[pos.f][pos.s]+1;
        for(const int &sig:adj[pos.f]) {
            if(minP[sig][sp])
                continue;
            Q.push({sig, sp});
            minP[sig][sp] = d;
            ant[sig][sp] = pos;
        }
    }

    if(!hasCicl)
        hasCicl |= dfs(ini);

    printf("%s\n", hasCicl? "Draw" : "Lose");
}
