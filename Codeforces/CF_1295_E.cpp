#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int LIM_N = 2e5 + 5;

const ll inf = 1e18;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi;
    ll mset = inf, madd = 0, val = -inf;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
    Node(vector<ll>& v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo)/2;
            l = new Node(v, lo, mid); r = new Node(v, mid, hi);
            val = max(l->val, r->val);
        }
        else val = v[lo];
    }
    ll query(int L, int R) {
        if (R <= lo || hi <= L) return -inf;
        if (L <= lo && hi <= R) return val;
        push();
        return max(l->query(L, R), r->query(L, R));
    }
    void set(int L, int R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) mset = val = x, madd = 0;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = max(l->val, r->val);
        }
    }
    void add(int L, int R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != inf) mset += x;
            else madd += x;
            val += x;
        }
        else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = max(l->val, r->val);
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if (mset != inf)
            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
        else if (madd)
            l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
    }
};


int N ;
int poss[LIM_N], revs[LIM_N];
ll vals[LIM_N];
ll totSum = 0 ;
ll acmSum[LIM_N];

ll calcNs() {
    ll ans = INF;
    vector <ll> a (N+1);

    for(int i=1; i <= N; i++) {
        a[i] = a[i-1] - vals[poss[i]];
    }
    Node st(a, 0, N+1);
    ans = -st.query(1, N);

    for(int i=1; i <= N; i++) {
        int pos = revs[i];
        st.add(pos, N + 1, vals[i]);
        st.add(1, pos, -vals[i]);
        ans = min(ans, -st.query(1, N));
    }

    return ans ;
}

int main() {
    ll ans = INF ;
    scanf("%d", &N);
    for(int i=1; i <= N; i++) {
        scanf("%d", &poss[i]);
        revs[poss[i]] = i;
    }
    for(int i=1; i <= N; i++) {
        ll a ;
        scanf("%lld", &a);
        vals[poss[i]] = a;
    }
    for(int i=1; i <= N; i++) {
        acmSum[i] += acmSum[i-1] + vals[i];
        totSum += vals[i];
    }
    ans = min(ans, calcNs());
    printf("%lld\n", ans);
}
