#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 1e5 + 5;

struct Nodo {
    int cnt ;
    Nodo *L, *R ;
    Nodo(): cnt(0), L(this), R(this) {}
    Nodo(const Nodo* otr): cnt(otr->cnt), L(otr->L), R(otr->R) {}
    Nodo* add(const int pos, const int L, const int R) const;
    int query(const int maxR, const int rngL, const int rngR) const ;
};

Nodo* Nodo::add(const int pos, const int rngL = 0, const int rngR = LIM_N - 1) const {
    Nodo* ans = new Nodo(this);
    ans->cnt ++;
    // printf("At %d %d %d => %d\n", rngL, rngR, pos, ans->cnt);
    if(rngL == rngR)
        return ans;
    int piv = (rngL + rngR) / 2;
    if(pos <= piv)
        ans->L = ans->L->add(pos, rngL, piv);
    else
        ans->R = ans->R->add(pos, piv + 1, rngR);
    return ans;
}

int Nodo::query(const int maxR, const int rngL = 0, const int rngR = LIM_N - 1) const {
    if(rngR <= maxR) {
        return this->cnt;
    }
    int piv = (rngL + rngR) / 2;
    int ans = this->L->query(maxR, rngL, piv);
    if(piv + 1 <= maxR)
        ans += this->R->query(maxR, piv + 1, rngR);
    return ans;
}

vector <int> poss[LIM_N];
Nodo* nods[LIM_N];

int main() {
    nods[0] = new Nodo();
    int N, K ;
    scanf("%d%d", &N, &K);
    for(int i=1; i <= N; i++) {
        int a ;
        scanf("%d", &a);
        auto &p = poss[a];
        p.push_back(i);
        nods[i] = nods[i-1]->add((int) p.size() <= K? 0 : p[p.size() - K - 1]);
        // printf("%d %d\n", i, ((int) p.size() <= K? 0 : p[p.size() - K - 1]));
    }

    int Q ;
    int ans = 0 ;
    scanf("%d", &Q);
    for(int i=0; i < Q; i++) {
        int x, y ;
        scanf("%d%d", &x, &y);
        int l = ((x + ans) % N) + 1;
        int r = ((y + ans) % N) + 1;
        if(r < l)
            swap(l, r);
        // printf("Query: %d %d => ", l, r);
        ans = nods[r]->query(l-1) - nods[l-1]->query(l-1);
        printf("%d\n", ans);
    }
}
