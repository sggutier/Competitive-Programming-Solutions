#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef pair<ll, int> pli;
const ll inf = 1e18;
const pli nv = {-inf, -3};
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi;
    ll madd = 0;
    pli mset = nv, val = {inf, -1};
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of inf
    Node(vector<ll>& v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo)/2;
            l = new Node(v, lo, mid); r = new Node(v, mid, hi);
            val = min(l->val, r->val);
        }
        else val = {v[lo], -1};
    }
    pli query(int L, int R) {
        if (R <= lo || hi <= L) return {inf, -2};
        if (L <= lo && hi <= R) return val;
        push();
        return min(l->query(L, R), r->query(L, R));
    }
    void set(int L, int R, pli x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) mset = val = min(x, val), madd = 0;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = min(l->val, r->val);
        }
    }
    void add(int L, int R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != nv) mset.first += x;
            else madd += x;
            val.first += x;
        }
        else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = min(l->val, r->val);
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if (mset != nv)
            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = nv;
        else if (madd)
            l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
    }
};

struct Ramp {
    int l, r, ft, orgId;
    bool operator<(const Ramp &otr) const {
        if(this->l != otr.l)
            return this->l < otr.l;
        if(this->r != otr.r)
            return this->r < otr.r;
        return this->ft < otr.ft;
    }
};

vector <Ramp> rs;
map <int, int> eps;
Node* st;
vector <pli> prevAns ;
vector <ll> orgV ;

void updateP(const int lastP, const int x, const int curL) {
    // printf("PRE:\n");
    // auto it = eps.begin();
    // for(int i=0; i < (int) eps.size(); i++, it++) {
    //     auto v = st->query(i, i+1);
    //     printf("\t%2d => %lld %d\n", it->first, v.first, v.second);
    // }
    // printf("Update: %d %d %d\n", lastP, x, curL);
    st->add(0, curL + 1, x - lastP);
    st->add(curL+1, eps.size(), -(x - lastP));
    // it = eps.begin();
    // for(int i=0; i < (int) eps.size(); i++, it++) {
    //     auto v = st->query(i, i+1);
    //     printf("\t%2d => %lld %d\n", it->first, v.first, v.second);
    // }
}

int main() {
    int N, L ;
    scanf("%d%d", &N, &L);
    for(int i=0, x, d, t, p; i < N; i++) {
        scanf("%d%d%d%d", &x, &d, &t, &p);
        if(x < p || L < (x + d)) continue;
        rs.push_back({x - p, x + d, t + p, i});
    }
    rs.push_back({L, L, 0, -1});
    N = rs.size();
    prevAns.resize(N);
    sort(rs.begin(), rs.end());

    eps[0];
    for(const auto &r : rs) {
        eps[r.r];
    }
    int eCnt = 0 ;
    for(auto &ep : eps) {
        ep.second = eCnt++;
    }
    orgV = vector<ll>(eps.size(), inf);
    orgV[0] = 0;
    st = new Node(orgV, 0, eps.size());

    auto it = eps.begin();
    int lastP = 0 ;
    int cntP = 0 ;
    for(int i=0; i < N; i++) {
        auto &r = rs[i];
        while(it != eps.end() && it->first <= r.l) {
            updateP(lastP, it->first, cntP - 1);
            lastP = it->first;
            it ++ ;
            cntP ++;
        }
        updateP(lastP, r.l, cntP - 1);
        lastP = r.l;
        auto v = st->query(0, eps.size());
        // printf("%d %d (%d) => %lld %d\n", r.l, r.r, r.orgId, v.first, v.second);
        v.first += r.ft;
        prevAns[i] = v;
        // printf("\t(%lld %d)\n", v.first, v.second);
        int x = eps[r.r];
        st->set(x, x+1, {v.first + r.r - r.l, i});
    }

    printf("%lld\n", prevAns[N-1].first);
    vector <int> ans ;
    for(int pos=N-1; pos != -1; pos = prevAns[pos].second) {
        ans.push_back(pos);
    }
    reverse(ans.begin(), ans.end());
    printf("%d\n", (int) ans.size() - 1);
    for(const int x : ans)
        if(rs[x].orgId != -1)
            printf("%d ", rs[x].orgId + 1);
    printf("\n");
}
