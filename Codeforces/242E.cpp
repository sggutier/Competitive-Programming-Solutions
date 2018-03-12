#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 1e5 + 5;
const int limB = 20;

struct Numo {
    int cnt ;
    int bts[limB];
    Numo() {
    }
    Numo(int n) {
        cnt = 1;
        for(int i=0; i<limB; i++)
            bts[i] = ((1<<i) & n)? 1 : 0;
    }
    void xora(int x) {
        for(int i=0; i<limB; i++)
            if((1<<i) & x)
                bts[i] = cnt-bts[i];
    }
    ll sum() {
        ll ans = 0;
        for(int i=0; i<limB; i++)
            ans += (1LL<<i)*bts[i];
        return ans;
    }
};

Numo operator+(const Numo &A, const Numo &B) {
    Numo ans;
    ans.cnt = A.cnt + B.cnt;
    for(int i=0; i<limB; i++)
        ans.bts[i] = A.bts[i] + B.bts[i];
    return ans;
}

class SegmentTree {
private:
    vector<Numo> st;
    vector<int> lazy;
    // int lazy[4*limN];
    vector<int> A;
    int n;
    inline int left (int p) { return p << 1; }
    inline int right(int p) { return (p << 1) + 1; }
    void build(int p, int L, int R) {
        if (L == R)
            st[p] = Numo(A[L]);
        else {
            build(left(p) , L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            // printf("A1\n");
            st[p] = st[left(p)] + st[right(p)];            
            // printf("B1\n");
        }
    }
    void lazyUpdate(int p, int L, int R) {
        if(!lazy[p])
            return;
        int x = lazy[p];
        st[p].xora(x);
        if(L!=R) {
            lazy[left(p)] ^= x;
            lazy[right(p)] ^= x;
        }
        lazy[p] = 0;
    }
    void rangeUpdate(int p, int L, int R, const int i, const int j, const int nov) {
        lazyUpdate(p, L, R);   
        if (i > R || j < L)
            return ;     
        if (i <= L && R <= j) {
            lazy[p] = nov;
            lazyUpdate(p, L, R);
            return ;
        }
        // lazyUpdate(p, L, R);
        rangeUpdate(left(p) , L, (L+R) / 2, i, j, nov);
        rangeUpdate(right(p), (L+R) / 2 + 1, R, i, j, nov);        
        // printf("A2\n");
        st[p] = st[left(p)] + st[right(p)];
        // printf("B2\n");
    }
    ll getSum(int p, int L, int R, int i, int j) {
        lazyUpdate(p, L, R);
        if (i > R || j < L)
            return 0;
        if (L >= i && R <= j) {
            return st[p].sum();
        }
        ll p1 = getSum(left(p) , L, (L+R) / 2, i, j);
        ll p2 = getSum(right(p), (L+R) / 2 + 1, R, i, j);
        return p1 + p2;
    }
public:
    void inita(const vector<int> &_A) {
        A = _A; n = (int)A.size();
        // st.assign(4 * n, tmp);
        st.resize(4*n);
        // lazy.assign(4 * n, 0);
        lazy.resize(4*n, 0);
        // printf("Todo asignado\n");
        build(1, 0, n - 1);
    }
    ll getSum(int i, int j) { return getSum(1, 0, n - 1, i, j); }
    void rangeUpdate(int i, int j, int nov) { rangeUpdate(1, 0, n - 1, i, j, nov); }
};

SegmentTree ST;

int main() {
    int N ;
    vector <int> nums;
    int Q ;

    scanf("%d", &N);
    nums.resize(N);
    for(int i=0; i<N; i++)
        scanf("%d", &nums[i]);
    ST.inita(nums);

    scanf("%d", &Q);
    for(int i=0; i<Q; i++) {
        int t, a, b, c;
        scanf("%d%d%d", &t, &a, &b);
        a--, b--;
        if(t==1) {
            printf("%lld\n", ST.getSum(a, b));
        }
        else if(t==2) {
            scanf("%d", &c);
            ST.rangeUpdate(a, b, c);
        }
    }
}
