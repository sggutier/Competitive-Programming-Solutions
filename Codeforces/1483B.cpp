#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define REP(i, b) for(int i = 0; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Nodo {
    Nodo *nxt = NULL, *prv = NULL;
    int id;
    Nodo(int id) : id(id) {}
    ~Nodo() {
        if(nxt == this) return;
        prv->nxt = nxt;
        nxt->prv = prv;
    }
};

void testCase(int N) {
    Nodo *nods[N];
    int vals[N];
    vector <int> ans;
    queue <int> da;
    for(int i=0; i < N; i++) {
        scanf("%d", &vals[i]);
        nods[i] = new Nodo(i);
    }

    for(int i=0; i < N; i++) {
        nods[i]->nxt = nods[(i+1)%N];
        nods[(i+1)%N]->prv = nods[i];
        if(__gcd(vals[i], vals[(i+1) % N]) == 1) {
            da.push(i);
        }
    }

    while(!da.empty()) {
        int pos = da.front(); da.pop();
        if(nods[pos] == NULL)
            continue;
        Nodo *nd = nods[pos]->nxt;
        // printf("Deleting %d %d from %d\n", nd->id, vals[nd->id], pos);
        ans.push_back(nd->id);
        if(__gcd(vals[nd->nxt->id], vals[nd->prv->id]) == 1)
            da.push(nd->prv->id);
        nods[nd->id] = NULL;
        delete nd;
    }

    printf("%d", (int) ans.size());
    for(const int x : ans)
        printf(" %d", x + 1);
    printf("\n");
}

int main() {
    int tc;
    for(scanf("%d", &tc); tc; tc--) {
        int n;
        scanf("%d", &n);
        testCase(n);
    }
}
