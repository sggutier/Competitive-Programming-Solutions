#include <bits/stdc++.h>
using namespace std;
const int limN = 5e5 + 5;
const int limC = 26;

int N ;
vector <int> adj[limN];
int aprIni[limN], aprFin[limN];
char lets[limN];
vector <int> acums[limN];
vector <int> idfs[limN];
int depo[limN];

void dfs(const int pos = 0, const int dep = 0) {
    static int w = 0;
    aprFin[pos] = aprIni[pos] = w++;
    depo[pos] = dep;
    acums[dep].push_back( (1<<(lets[pos]-'a')) ^ acums[dep][ acums[dep].size()-1 ] );
    idfs[dep].push_back( aprIni[pos] );
    for(const int &sig:adj[pos]) {
        dfs(sig, dep+1);
        aprFin[pos] = w++;
    }
}

bool query(const int nd, const int d) {
    if(d >= N) return true;
    if(depo[nd] > d) return true;
    int l = aprIni[nd], r = aprFin[nd];
    int f = upper_bound(idfs[d].begin(), idfs[d].end(), r) - idfs[d].begin() - 1;
    int i = lower_bound(idfs[d].begin(), idfs[d].end(), l) - idfs[d].begin() - 1;
    int w = acums[d][f] ^ acums[d][i];
    return w==0 || w == (w & -w);
}

int main() {
    int Q ;
    
    scanf("%d%d", &N, &Q);
    for(int i=1, p; i<N; i++) {
        scanf("%d", &p);
        adj[p-1].push_back(i);
    }
    scanf("%s", lets);
    
    for(int dep=0; dep<N; dep++) {
        idfs[dep].push_back(-1);
        acums[dep].push_back(0);
    }
    dfs();

    for(int i=0; i<Q; i++) {
        int v, d;
        scanf("%d%d", &v, &d);
        printf("%s\n", query(v-1, d-1)? "Yes" : "No");
    }
}
