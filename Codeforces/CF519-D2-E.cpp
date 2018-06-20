#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
const int limB = 17;

int N;
vector <int> adj[limN];
int ancs[limN][limB];
int W = 0;
int dep[limN], aprIni[limN], aprFin[limN];

void marca(int pos=1, int prev=0, int d=0) {
    if(prev) {
        int *ans = ancs[pos];
        int p = prev;
        ans[0] = prev;
        
        // printf("%d =>", pos);
        for(int i=1; i<limB; i++) {            
            p = ancs[p][i-1];
            if(!p) break;
            ans[i] = p;
        }
        
        // for(int i=0; i<limB; i++)
        //     printf(" %2d", ans[i]);
        // printf("\n");
    }
    dep[pos] = d;
    aprFin[pos] = aprIni[pos] = W++;
    for(const int &sig : adj[pos]) {
        if(sig == prev) continue;
        marca(sig, pos, d+1);
        aprFin[pos] = max(aprFin[pos], aprFin[sig]);
    }
    // printf("%d appears firts at %d and lastly at %d\n", pos, aprIni[pos], aprFin[pos]);
}

int kanc(int pos, int k) {
    for(int i=limB-1; i>=0; i--) {
        if(!ancs[pos][i] || ((1<<i) & k)==0)
            continue;
        pos = ancs[pos][i];
    }
    return pos;
}

bool contains(int padr, int hij) {
    return aprIni[padr] <= aprIni[hij] && aprIni[hij] <= aprFin[padr];
}

int sizeTree(int pos) {
    return aprFin[pos] - aprIni[pos] + 1;
}

int query(int x, int y) {
    if(x==y) return N;
    if(dep[x] > dep[y])
        swap(x, y);
    int ini = 0, fin = dep[x];
    while(ini < fin) {
        int piv = (ini+fin)/2 + 1;
        int pos = kanc(y, dep[y] - piv);
        // printf("\t at dep %d there is %d\n", piv, pos);
        if(!contains(pos, x))
            fin = piv-1;
        else
            ini = piv;
    }
    int dst = (dep[x] - ini) + (dep[y] - ini);
    if( dst % 2)
        return 0;
    int z = kanc(y, dst / 2);
    // printf("%d %d >> %d %d | %d\n", x, y, ini, dst, z);
    int ans = dep[x] == dep[y]? N : sizeTree(z);
    if(contains(z, x))
        ans -= sizeTree( kanc(x, dst/2 - 1));
    if(contains(z, y))
        ans -= sizeTree( kanc(y, dst/2 - 1));
    return ans;
}

int main() {
    int Q ;
    scanf("%d", &N);
    for(int i=1; i<N; i++) {
        int a, b ;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    marca();

    scanf("%d", &Q);
    while(Q--) {
        int a, b ;
        scanf("%d%d", &a, &b);
        printf("%d\n", query(a, b));
    }
    
}
