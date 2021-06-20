#include <bits/stdc++.h>
using namespace std;
const int limN = 5e5 + 5;
const int inf = 2e9 + 15;

struct SegmTree {
    int N ;
    int vals[2*limN];

    void inita(int _N) {
        N = _N;
        for(int i=N-1; i; i--)
            vals[i] = min(vals[i<<1], vals[(i<<1)|1]);
    }

    void upd(int pos, int nv) {
        pos += N ;
        vals[pos] = nv;
        for(pos >>=1; pos; pos>>=1) {
            vals[pos] = min(vals[pos<<1], vals[(pos<<1)|1]);
        }
    }

    int saca(int l, int r) {
        int ans = inf;
        r++;
        for(l+=N, r+=N; l<r; l>>=1, r>>=1) {
            if(l & 1)
                ans = min(ans, vals[l++]);
            if(r & 1)
                ans = min(ans, vals[--r]);
        }
        return ans;
    }
};

struct SegmTreeS {
    int N ;
    long long vals[2*limN];

    void inita(int _N) {
        N = _N;
        for(int i=N-1; i; i--)
            vals[i] = vals[i<<1] + vals[(i<<1)|1];
    }

    void upd(int pos, int nv) {
        pos += N ;
        vals[pos] = nv;
        for(pos >>=1; pos; pos>>=1) {
            vals[pos] = vals[pos<<1] + vals[(pos<<1)|1];
        }
    }

    long long saca(int l, int r) {
        long long ans = 0;
        r++;
        for(l+=N, r+=N; l<r; l>>=1, r>>=1) {
            if(l & 1)
                ans += vals[l++];
            if(r & 1)
                ans += vals[--r];
        }
        return ans;
    }
};

int N ;
int nums[limN];
SegmTree stL, stR;
SegmTreeS stS;

long long gs(long long k) {
    return (k*(k+1))/2;
}

long long calco(int p, long long k) {
    long long neg = k*k;
    if(p - k + 1 < 0)
        neg -= gs(k-(p+1));
    if(p+k > N)
        neg -= gs(k-(N-p));
    // printf("=> %lld (%d) %lld %lld\n", k, p, max(0LL, p-k+1), min(N-1LL, p+k-1));
    return stS.saca(max(0LL, p-k+1), min(N-1LL, p+k-1)) - neg;
}

void queryG(int pos, int tip) {
    int dl = stL.saca(0, pos), dr = stR.saca(pos, N-1);
    int tl = dl + pos, tr = dr - pos;
    // printf("%d %d => %d %d\n", dl, dr, tl, tr);
    int ans = min(tl, tr);
    if(tip==1)
        ans = min(ans, min(pos+1, N-pos));
    printf("%d %lld\n", ans, calco(pos, ans));
}

void queryCng(int pos, int nv) {
    nums[pos] = nv;
    stL.upd(pos, nums[pos] - pos);
    stR.upd(pos, nums[pos] + pos);
    stS.upd(pos, nums[pos] );
}

void testCase() {
    int Q ;
    
    for(int i=0; i<N; i++) {
        scanf("%d", &nums[i]);
        stL.vals[i+N] = nums[i]-i;
        stR.vals[i+N] = nums[i]+i;
        stS.vals[i+N] = nums[i];
    }
    stL.inita(N);
    stR.inita(N);
    stS.inita(N);

    scanf("%d", &Q);
    for(int i=0; i<Q; i++) {
        int t, a, b;
        scanf("%d%d%d", &t, &a, &b);
        if(t==1)
            queryCng(a-1, b);
        else
            queryG(a-1, b);
    }
}


int main() {
    while(scanf("%d", &N)!=EOF) {
        testCase();
        // break;
    }
}
