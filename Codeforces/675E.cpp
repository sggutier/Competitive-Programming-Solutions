#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
const int LIM_N = 1e5 + 5 ;

struct Tree {
    typedef pii T;
    const T LOW = {-1234567890, -1};
    T f(T a, T b) { return max(a, b); }

    int n;
    vector<T> s;
    Tree() {}
    Tree(int m, T def={0, 0}) { init(m, def); }
    void init(int m, T def) {
        n = 1; while (n < m) n *= 2;
        s.assign(n + m, def);
        s.resize(2 * n, LOW);
        for (int i = n; i --> 1; )
            s[i] = f(s[i * 2], s[i*2 + 1]);
    }
    void update(int pos, T val) {
        pos += n;
        s[pos] = val;
        for (pos /= 2; pos >= 1; pos /= 2)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int l, int r) { return que(1, l, r, 0, n); }
    T que(int pos, int l, int r, int lo, int hi) {
        if (r <= lo || hi <= l) return LOW;
        if (l <= lo && hi <= r) return s[pos];
        int m = (lo + hi) / 2;
        return f(que(2 * pos, l, r, lo, m),
                que(2 * pos + 1, l, r, m, hi));
    }
};


ll anss[LIM_N];
int rs[LIM_N];

int main() {
    int N ;
    ll ans = 0 ;

    scanf("%d", &N);
    Tree st(N);
    for(int i=0; i+1 < N; i++) {
        scanf("%d", &rs[i]);
        rs[i] --;
        st.update(i, {rs[i], i});
    }
    st.update(N-1, {N-1, N-1});
    for(int i=N-2; i >= 0; i--) {
        pii maxR = st.query(i+1, rs[i] + 1);
        anss[i] = (N-1 - i) + anss[maxR.second] - (rs[i] - maxR.second);
        ans += anss[i];
        // printf("At %d to %d: maxR => %d %d\n", i+1, rs[i] + 1, maxR.first + 1, maxR.second + 1);
        // printf("\t%lld\n", anss[i]);
    }

    printf("%lld\n", ans);
}
