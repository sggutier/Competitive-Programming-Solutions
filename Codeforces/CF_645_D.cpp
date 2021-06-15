#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define f first
#define s second
const int limN = 1e5 + 5;

int N, E;
int crgs[limN];
int As[limN], Bs[limN];
vector <pii> adj[limN];

bool funca(int k) {
    for(int i=1; i<=N; i++)
        crgs[i] = 0;
    for(int i=0; i<k; i++)
        crgs[As[i]]++;
    int pos = -1;
    for(int i=1; i<=N; i++) {
        if(crgs[i])
            continue;
        if(pos==-1)
            pos = i;
        else
            return false;
    }
    for(int w=N-1; w; w--) {
        int sp = -1;
        for(const auto &e : adj[pos]) {
            if(e.s >= k) continue;
            crgs[e.f] --;
            if(crgs[e.f]) continue;
            if(sp==-1)
                sp = e.f;
            else
                return false;
        }
        pos = sp;
    }
    return true;
}

int main() {
    scanf("%d%d", &N, &E);
    for(int i=0; i<E; i++) {
        scanf("%d%d", &As[i], &Bs[i]);
        adj[Bs[i]].push_back({As[i], i});
    }

    int ini = 1, fin=E;
    while(ini < fin) {
        int piv = (ini+fin)/2;
        if(funca(piv))
            fin = piv;
        else
            ini = piv+1;
    }

    if(funca(ini))
        printf("%d\n", ini);
    else
        printf("-1\n");
}
