#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
#define f first
#define s second
const int limN = 405;

int N, N2 ;
bool adj[limN][limN];
vector <int> hig[limN];
vector <int> rai[limN];
int minP[2][limN][limN];
bool usd[limN];

int calcMP(par ini=par(0, 0)) {
    queue <par> Q[2];
    Q[0].push(ini) ;
    minP[0][ini.f][ini.s] = 1;
    Q[1].push(par(N-1, N-1)) ;
    minP[1][N-1][N-1] = 1;
    while(!Q[0].empty() || !Q[1].empty()) {
        for(int dir=0; dir<2; dir++) {
            if(Q[dir].empty())
                continue;
            par poso = Q[dir].front();
            int tpo =  minP[dir][poso.f][poso.s]+1;
            if(tpo >= N2) {
                return -1;
            }
            while(!Q[dir].empty()) {
                par pos = Q[dir].front(); Q[dir].pop();
                if(minP[dir][pos.f][pos.s]+1 != tpo)
                    break;
                //printf("%d %d %d => %d\n", dir, pos.f+1, pos.s+1, tpo-2);
                if(pos.f == N-1) {
                    for(const int &sig:rai[pos.s]) {
                        if(minP[dir][pos.f][sig])
                            continue;
                        if(minP[1-dir][pos.f][sig]) {
                            //printf("\t=> fino en %d %d\n", pos.f+1, sig+1);
                            return tpo + minP[1-dir][pos.f][sig] - 2;
                        }
                        //printf("\t=> %d %d\n", pos.f+1, sig+1);
                        minP[dir][pos.f][sig] = tpo;
                        Q[dir].push(par(pos.f, sig));
                    }
                }
                if(pos.s == N-1) {            
                    for(const int &sig:hig[pos.f]) {
                        if(minP[dir][sig][pos.s])
                            continue;
                        if(minP[1-dir][sig][pos.s]) {
                            //printf("\t=> fino en %d %d\n", sig+1, pos.s+1);
                            return tpo + minP[1-dir][sig][pos.s] - 2;
                        }
                        //printf("\t=> %d %d\n", sig+1, pos.s+1);
                        minP[dir][sig][pos.s] = tpo;
                        Q[dir].push(par(sig, pos.s));
                    }
                }            
                for(const int &f:hig[pos.f]) {
                    for(const int &s:rai[pos.s]) {
                        if(minP[dir][f][s])
                            continue;
                        if(minP[1-dir][f][s]) {
                            //printf("\t=>fino en %d %d\n", f+1, s+1);
                            return tpo + minP[1-dir][f][s] - 2;
                        }
                        if(f==s)
                            continue;
                        //printf("\t=> %d %d\n", f+1, s+1);
                        minP[dir][f][s] = tpo;
                        Q[dir].push(par(f, s));
                    }
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
    N2 = N/2 + 3;
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
    //printf("%d\n", calcMP());
    printf("%d\n", richabl(hig) && richabl(rai)? calcMP() : -1);
}
