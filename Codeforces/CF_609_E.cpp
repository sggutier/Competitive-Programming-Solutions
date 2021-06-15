#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int LIM_N = 2e5 + 5;
const int LIM_B = 18;
const int INF = numeric_limits<int>::max() / 4;

struct Nod {
    int dep;
    Nod* ancs[LIM_B];
    int maxWt[LIM_B];
    Nod() : dep(0) {
        for(int i=0; i < LIM_B; i++) {
            ancs[i] = this;
            maxWt[i] = INF;
        }
    }
    Nod(Nod* prev, int W) : dep(prev->dep + 1) {
        ancs[0] = prev;
        maxWt[0] = W;
        for(int i=1; i < LIM_B; i++) {
            maxWt[i] = W = max(W, prev->maxWt[i-1]);
            ancs[i] = prev = prev->ancs[i-1];
        }
    }
    Nod* getAnc(const int k) {
        Nod* pos = this;
        for(int i=LIM_B-1; i >= 0; i--) {
            if((1 << i) & k) {
                pos = pos->ancs[i];
            }
        }
        return pos;
    }
    int getMaxWt(const int k) {
        int ans = 0 ;
        Nod* pos = this;
        for(int i=LIM_B-1; i >= 0; i--) {
            if((1 << i) & k) {
                ans = max(ans, pos->maxWt[i]);
                pos = pos->ancs[i];
            }
        }
        return ans;
    }
};

Nod* nods[LIM_N];
vector <pii> adj[LIM_N];
pii prevos[LIM_N];
ll totWt = 0;

void prim() {
    prevos[1] = {0, 0};
    priority_queue <pii> Q ;
    Q.push({0, 1});
    prevos[1].second = -1;
    while(!Q.empty()) {
        int pos = Q.top().second; Q.pop();
        if(nods[pos]) continue;
        if(prevos[pos].second != -1) {
            totWt += prevos[pos].first;
            nods[pos] = new Nod(nods[prevos[pos].second], prevos[pos].first);
        }
        else
            nods[pos] = new Nod();
        for(const auto &edg : adj[pos]) {
            if(!prevos[edg.second].second)
                prevos[edg.second] = {edg.first, pos};
            prevos[edg.second] = min(prevos[edg.second], {edg.first, pos});
            Q.push({-edg.first, edg.second});
        }
    }
}

int query(int a, int b) {
    if(nods[b]->dep < nods[a]->dep)
        swap(a, b);
    Nod *A = nods[a];
    Nod *B = nods[b];
    int dif = B->dep - A->dep;
    int ini = 0, fin = A->dep;
    while(ini < fin) {
        int piv = (ini + fin) / 2 ;
        if(A->getAnc(piv) == B->getAnc(dif + piv))
            fin = piv;
        else
            ini = piv + 1;
    }
    return max(A->getMaxWt(ini), B->getMaxWt(ini + dif));
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int N, E ;
    int as[LIM_N], bs[LIM_N], cs[LIM_N];
    cin >> N >> E ;
    for(int i=0; i < E; i++) {
        cin >> as[i] >> bs[i] >> cs[i];
        adj[as[i]].push_back({cs[i], bs[i]});
        adj[bs[i]].push_back({cs[i], as[i]});
    }
    prim();
    for(int i=0; i < E; i++) {
        cout << totWt - query(as[i], bs[i]) + cs[i] << endl;
    }
}
