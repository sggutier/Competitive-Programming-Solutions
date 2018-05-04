/*
- The problem has to be solved for every set of "connected" nodes, as if it was a forest.
- If a component has no SCCs, the nodes can be arranged in a big linear chain,
  in such way that they are ordered by topological sort.  This takes n-1 teleporters,
  and keeps all the desired orders.
- If a component has at least a SCC, it requires w edges, where w is the amount of nodes in
  the SCC.  This altogether makes the set of nodes require at least n teleporters.  Since
  n edges are already going to be used (because of the extra edge of the SCC), all the nodes
  in the set can be arranged in a big cycle requiring n edges.  This has to be the
  least amount of edges because n-1 edges cannot be reached because of the SCC.
- For programming it each set can be kept together with a DSU, and Tarjan's algorithm for
  SCC would be used for finding SCCs.
- This has a complexity of about O((E + N) log N), because each query of the DSU takes about 
  O(log N) operations and it is going to be queried for each edge and node at the end.
  Tarjan is linear so it would not affect the complexity.
 */

#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

struct Nodo {
    Nodo* padr = NULL;
    int cnt = 1;
    int id;
    Nodo(int id) : id(id) {}
    Nodo* raiz() {
        Nodo* pos = this;
        while(pos->padr)
            pos = pos->padr;
        return pos;
    }
    void une(Nodo *B) {
        Nodo *A = this->raiz();
        B = B->raiz();
        if(A==B) return;
        if(A->cnt < B->cnt)
            swap(A, B);
        B->padr = A;
        A->cnt += B->cnt;
    }
};

bool usd[limN], actv[limN];
Nodo* nodos[limN];
int minDep[limN], dfsId[limN];
int compPad[limN];
int W = 0;
stack <int> S;
vector <int> adj[limN];

void tarjan(int pos) {
    if(usd[pos])
        return;
    actv[pos] = usd[pos] = true;
    minDep[pos] = dfsId[pos] = ++W;
    S.push(pos);
    for(const int &sig: adj[pos]) {
        nodos[pos]->une(nodos[sig]);
        tarjan(sig);
        if(actv[sig]) {
            minDep[pos] = min(minDep[pos], minDep[sig]);
            // printf("%d con %d considerando %d con %d\n", pos+1, minDep[pos], sig+1, minDep[sig]);
        }
    }
    if(minDep[pos] < dfsId[pos])
        return;
    int ult;
    // printf("%d padre de\n", pos+1);
    do {
        ult = S.top(); S.pop();
        compPad[ult] = pos;
        actv[ult] = false;
        // printf("\t%d\n", ult+1);
    } while( ult != pos) ;
}

int main() {
    int N, E;
    int ans = 0 ;
    scanf("%d%d", &N, &E);
    for(int i=0; i<N; i++) {
        nodos[i] = new Nodo(i);
    }
    for(int i=0, a, b; i<E; i++)  {
        scanf("%d%d", &a, &b);
        adj[a-1].push_back(b-1);
    }
    for(int i=0; i<N; i++)
        tarjan(i);
    memset(usd, 0, sizeof(usd));
    memset(actv, 0, sizeof(actv));
    for(int i=0; i<N; i++) {
        // printf("%d => %d (%d)\n", i+1, nodos[i]->raiz()->id+1, compPad[i]+1);
        if(compPad[i] != i)
            actv[nodos[i]->raiz()->id] = true;
    }
    for(int i=0; i<N; i++) {
        Nodo *rt = nodos[i]->raiz();
        if(usd[rt->id]) continue;
        ans += rt->cnt + (actv[rt->id]? 0 : -1);
        usd[rt->id] = true;
    }
    printf("%d\n", ans);
}
