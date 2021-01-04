#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int LIM_N = 1e5 + 5;
const int LIM_B = 17 ;

struct Nodo {
    Nodo* ancs[LIM_B] ;
    int id, age ;
    Nodo(const int id, const int age) : id(id), age(age) {
        for(int i=0; i < LIM_B; i++) ancs[i] = this;
    }
    void setParent(Nodo* p) {
        for(int i=0; i < LIM_B; i++) {
            ancs[i] = p ;
            p = p->ancs[i];
        }
    }
};

int cntT[LIM_N];

void mete(int pos, const int nov) {
    for(; pos < LIM_N; pos += pos & -pos)
        cntT[pos] += nov;
}

int saca(int pos) {
    int ans = 0 ;
    for(; pos; pos -= pos & -pos)
        ans += cntT[pos];
    return ans;
}

Nodo* nds[LIM_N] ;
int ages[LIM_N];
vector <int> adj[LIM_N];
vector <int> decs[LIM_N];
int partyN[LIM_N];

void dfsAncs(const int pos, const int pv = 1) {
    nds[pos] = new Nodo(pos, ages[pos]);
    nds[pos]->setParent(nds[pv]);
    for(const int sig : adj[pos]) {
        dfsAncs(sig, pos);
    }
}

Nodo* miniRt(const int pos, const int maxAge) {
    Nodo* p = nds[pos];
    for(int i=LIM_B-1; i >= 0; i--) {
        if(p->ancs[i]->age <= maxAge)
            p = p->ancs[i];
    }
    return p ;
}

void dfsReps(const int pos) {
    for(const int d : decs[pos]) mete(d, 1);
    partyN[pos] = saca(ages[pos]);
    for(const int sig : adj[pos]) {
        dfsReps(sig);
    }
    for(const int d : decs[pos]) mete(d, -1);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int N, Q ;

    scanf("%d%d", &N, &Q);
    for(int i=1, j; i <= N; i++) {
        scanf("%d%d", &ages[i], &j);
        if(j != i)
            adj[j].push_back(i);
    }
    dfsAncs(1);
    for(int i=0, e, l, r; i < Q; i++) {
        scanf("%d%d%d", &e, &l, &r);
        auto p = miniRt(e, r);
        decs[p->id].push_back(l);
        // printf("%d -> %d\n", p->id, p->age);
    }
    dfsReps(1);
    printf("%d", partyN[1]);
    for(int i=2; i <= N; i++)
        printf(" %d", partyN[i]);
    printf("\n");
    return 0 ;
}
