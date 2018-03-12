#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
#define f first
#define s second
const int limN = 1e5 + 5;
const int inf = (1<<30) + ((1<<30) - 5);

class SegmTree {
private:
    int n;
    vector <int> vals;
    int _get(int l, int r) {
        int ans = inf;
        l += n, r += n;
        for(; l<r; l>>=1, r>>=1) {
            if(l & 1)
                ans = min(ans, vals[l++]);
            if(r & 1)
                ans = min(ans, vals[--r]);
        }
        return ans;
    }
public:
    SegmTree(vector <int> &cpy) {
        n = cpy.size();
        vals.resize(2*n);
        for(int i=0; i<n; i++) {
            vals[i+n] = cpy[i];
        }
        for(int i=n-1; i>0; i--) {
            vals[i] = min(vals[i<<1], vals[(i<<1)|1]);
        }
    }
    void upd(int a, int p) {
        a += n;
        vals[a] = p;
        for(int i = a>>1; i; i>>=1) {
            vals[i] = min(vals[i<<1], vals[(i<<1)|1]);
        }
    }
    int get(int a, int b) {
        return this -> _get(a, b+1);
    }
};

int main() {
    int N, S, L;
    int nums[limN];
    int A, B ;
    int as[limN], aps[limN];
    int bs[limN], bps[limN];
    int limR[limN];

    scanf("%d%d%d", &N, &S, &L);
    for(int i=0; i<N; i++)
        scanf("%d", &nums[i]);
    vector<int> tmp(N+1, inf);
    SegmTree st(tmp);
    S++;
    st.upd(N, 0);
    // printf("%d %d\n", st.get(0, N), st.get(N, N));

    as[0] = bs[0] = -inf;
    aps[0] = bps[0] = N;
    A = B = 1;
    limR[N] = N;
    for(int i=N-1; i>=0; i--) {
        int w = lower_bound(as, as+A, nums[i]) - as;
        as[w] = nums[i], aps[w] = i;
        A = w+1;
        w = lower_bound(bs, bs+B, -nums[i]) - bs;
        bs[w] = -nums[i], bps[w] = i;
        B = w+1;
        // for(int j=0; j<A; j++)
        //     printf("[%d %d] ", as[j], aps[j]);
        // printf("\n");
        // for(int j=0; j<B; j++)
        //     printf("[%d %d] ", bs[j], bps[j]);
        // printf("\n");
        int x = upper_bound(bs, bs+B, -nums[i]-S) - bs;
        int y = upper_bound(as, as+A, nums[i]-S) - as;
        // printf("%d %d\n", x, y);
        int l = i + L, r = min(min(bps[x-1], aps[y-1]), limR[i+1]) ;
        // printf("%d (%d) => %d %d\n", nums[i], i, l, r);
        limR[i] = r;
        if(l > r)
            continue;
        int so = st.get(l, r) ;
        if(so != inf)
            st.upd(i, so+1);
        // printf("\t%d %d\n", st.get(0, N), st.get(N, N));
    }

    int ans = st.get(0, 0);
    if(ans==inf)
        printf("%d\n", -1);
    else
        printf("%d\n", ans);
}
