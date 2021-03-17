#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int LIM_N = 1e5 + 5;
const int LIM_C = 26;
const int BAS_C = 'a';

typedef priority_queue<int> pq;

struct Nod {
    Nod* nxt[LIM_C] = {NULL} ;
    bool isEnd = false;
    pq* q = NULL;
    void insert(char *c) {
        if(*c == 0) {
            isEnd = true;
            return;
        }
        if(!nxt[*c - BAS_C])
            nxt[*c - BAS_C] = new Nod();
        nxt[*c - BAS_C]->insert(c+1);
    }
};

void dfs(Nod* pos, int dep = 0) {
    pii maxL = {0, -1};
    auto &ans = pos->q;
    for(int i=0; i < LIM_C; i++)
        if(pos->nxt[i]) {
            dfs(pos->nxt[i], dep + 1);
            maxL = max(maxL, {pos->nxt[i]->q->size(), i});
        }
    if(maxL.second != -1)
        ans = pos->nxt[maxL.second]->q;
    else
        ans = new pq();
    for(int i=0; i < LIM_C; i++)
        if(i != maxL.second && pos->nxt[i]) {
            auto r = pos->nxt[i]->q;
            while(!r->empty()) {
                ans->push(r->top());
                r->pop();
            }
        }
    if(!ans->empty() && !pos->isEnd) {
        ans->pop();
    }
    ans->push(dep);
}

int main() {
    int N ;
    Nod* arb = new Nod();
    ll ans = 0 ;
    char tmp[LIM_N];
    scanf("%d", &N);
    for(int i=0; i < N; i++) {
        scanf("%s", tmp);
        arb->insert(tmp);
    }
    arb->isEnd = true;
    dfs(arb);
    auto &q = arb->q;
    while(!q->empty()) {
        ans += q->top();
        q->pop();
    }
    printf("%lld\n", ans);
}
