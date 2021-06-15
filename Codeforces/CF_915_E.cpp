#include <bits/stdc++.h>
using namespace std;
const int limN = 1.2e6 + 5;
// const int limN = 9e5 + 5;
// const int limN = 8;
const int limW = 6*limN;

struct SegTree {
    int tams[limW];
    int actv[2*limW];
    char crg[2*limW];

    SegTree() {
        memset(tams, 0, sizeof(tams));
        memset(actv, 0, sizeof(actv));
        memset(crg, 0, sizeof(crg));
    }

    void mete(const int k, const int v, const int pos=1, const int l=0, const int r=limN) {
        // if(l==0 && r ==limN) {
        //     printf("Metiendo %d en %d\n", v, k);
        // }
        if(k < l || r <= k || r <= l) return;
        tams[pos] += v;
        actv[pos] += v;
        crg[pos] = 0;
        int piv = (l+r) / 2;
        mete(k, v, pos*2, l, piv);
        if(piv != l)
            mete(k, v, pos*2 + 1, piv, r);
    }

    void push(const int pos) {
        if(!crg[pos]) return;
        crg[pos*2] = crg[pos];
        crg[pos*2 + 1] = crg[pos];
        actv[pos] = crg[pos]==2? tams[pos] : 0;
        crg[pos] = 0;
    }

    void upd(const int kl, const int kr, const char c, const int pos=1, const int l=0, const int r = limN) {
        if(kr <= l || r <= kl || r <= l) return;
        
        if(kl <= l && r <= kr) {
            // printf("Actualizando :\n");
            // printf("kl = %d, kr = %d, c = %d, pos = %d, l = %d, r = %d\n", kl, kr, c, pos, l, r);
            crg[pos] = c;
            push(pos);
            // printf("\tactv termina siendo %d (tiene tam de %d)\n", actv[pos], tams[pos]);
            return;
        }
        push(pos);
        int piv = (l + r) / 2;
        upd(kl, kr, c, pos*2, l, piv);
        if(piv != l)
            upd(kl, kr, c, pos*2 + 1, piv, r);
        actv[pos] = 0;
        push(pos*2);
        push(pos*2 + 1);
        actv[pos] = actv[pos*2] + actv[pos*2 + 1];
        // printf("kl = %d, kr = %d, c = %d, pos = %d, l = %d, r = %d\n", kl, kr, c, pos, l, r);
        // printf("\tactv termina siendo %d\n", actv[pos]);
    }

    int cnt() {
        return actv[1];
    }
};

int K = 0, R = 0;
int nums[limN];
int revo[limN], poss[limN];
int ls[limN], rs[limN], ks[limN];
SegTree st;

int main() {
    srand(time(NULL));
    int N, Q;

    scanf("%d%d", &N, &Q);
    for(int i=0; i<Q; i++) {
        scanf("%d%d%d", &ls[i], &rs[i], &ks[i]);
        nums[K++] = ls[i];
        nums[K++] = rs[i];
        // ks[i] --;
    }
    nums[K++] = 1;
    nums[K++] = N;

    sort(nums, nums+K);

    int ult = 0;
    int w = 0;
    for(int i=0, c; i<K; i++) {
        c = nums[i];
        if(ult + 1 < c) {
            st.mete(w++, c-ult-1);
        }
        if(ult != c) {            
            st.mete(w++, 1);
            revo[R] = c;
            poss[R] = w-1;
            R++;
            ult = c;
        }
    }

    // printf("%d %d %d\n", t->cnt, t->key, t->maxR);
    for(int i=0, l, r, k; i<Q; i++) {
        l = lower_bound(revo, revo+R, ls[i]) - revo;
        r = lower_bound(revo+l, revo+R, rs[i]) - revo;
        k = ks[i];
        st.upd(poss[l], poss[r] + 1, k);
        printf("%d\n", st.cnt() );
    }
}
