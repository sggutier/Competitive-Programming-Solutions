#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
#define f first
#define s second
const int limN = 405;

int N ;
bool adj[limN][limN];
vector <int> hig[limN];
vector <int> rai[limN];
int minP[limN][limN];
bool usd[limN];

int calcMP(par ini=par(0, 0)) {
    list <par> Q;
    Q.push_back(ini) ;
    minP[ini.f][ini.s] = 1;
    while(!Q.empty()) {
        par pos = Q.front(); Q.pop_front();
        int tpo =  minP[pos.f][pos.s]+1;
        printf("%d %d => %d\n", pos.f+1, pos.s+1, minP[pos.f][pos.s]-1);
        if(tpo >= N+5)
            break;
        if(pos.f == N-1 && pos.s == N-1) {
            return minP[pos.f][pos.s]-1;
        }
        else if(pos.f == N-1) {
            for(const int &sig:rai[pos.s]) {
                if(minP[pos.f][sig])
                    continue;
                printf("\t=> %d %d\n", pos.f+1, sig+1);
                minP[pos.f][sig] = tpo;
                Q.push_back(par(pos.f, sig));
            }
        }
        else if(pos.s == N-1) {            
            for(const int &sig:hig[pos.f]) {
                if(minP[sig][pos.s])
                    continue;
                printf("\t=> %d %d\n", sig+1, pos.s+1);
                minP[sig][pos.s] = tpo;
                Q.push_back(par(sig, pos.s));
            }
        }
        else {
            for(const int &f:hig[pos.f]) {
                for(const int &s:rai[pos.s]) {
                    if(minP[f][s] || (f==s && f!=N-1))
                        continue;
                    printf("\t=> %d %d\n", f+1, s+1);
                    minP[f][s] = tpo;
                    Q.push_back(par(f, s));
                }
            }
        }
    }
    return -1;
}

bool dfs(vector <int> *adj, int pos=0) {
    if(pos==N-1)
        return true;
    if(usd[pos])
        return false;
    usd[pos] = true;
    for(const int &sig:adj[pos]) {
        if(dfs(adj, sig))
            return true;
    }
    return false;
}

bool richabl(vector <int> *adj) {
    memset(usd, 0, sizeof(usd));
    return dfs(adj);
}

int main() {
    int E;
    scanf("%d%d", &N, &E);
    for(int i=0; i<E; i++) {
        int a, b ;
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a][b] = adj[b][a] = 1;
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(i==j)
                continue;
            if(adj[i][j]==0)
                hig[i].push_back(j);
            else
                rai[i].push_back(j);
        }
    }
    printf("%d\n", richabl(hig) && richabl(rai)? calcMP() : -1);
}

