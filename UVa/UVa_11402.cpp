#include <bits/stdc++.h>
using namespace std;
const int limN = 1.1e6;

class SegmentTree {
private:
    vector<int> st;
    vector<char> lazy;
    vector<bool> A;
    int n;
    inline int left (int p) { return p << 1; }
    inline int right(int p) { return (p << 1) + 1; }
    void build(int p, int L, int R) {
        if (L == R)
            st[p] = A[L]? 1:0;
        else {
            build(left(p) , L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = p1 + p2;
        }
    }
    inline char flipo(char k) {
        return 3 - k;
    }
    void lazyUpdate(int p, int L, int R) {
        if(!lazy[p])
            return;
        if(lazy[p]<=2) {
            st[p] = (R-L+1)*(lazy[p]-1);
            if(L!=R) {
                lazy[left(p)] = lazy[p];
                lazy[right(p)] = lazy[p];
            }
            lazy[p] = 0;
        }
        else {
            st[p] = (R-L+1) - st[p];
            if(L!=R) {
                lazy[left(p)] = flipo(lazy[left(p)]);
                lazy[right(p)] = flipo(lazy[right(p)]);
            }
            lazy[p] = 0;
        }
    }
    void rangeUpdate(int p, int L, int R, int i, int j, char nov) {
        lazyUpdate(p, L, R);
        if (i > R || j < L)
            return ;
        // printf("statini %d -> %d %d -> %d %d => %d\n", p, L, R, i, j, st[p]);
        if (L >= i && R <= j) {
            // printf("%d %d => ", st[p], lazy[p]);
            lazy[p] = nov;
            lazyUpdate(p, L, R);
            // printf("updo %d -> %d %d -> %d %d => %d\n", p, L, R, i, j, st[p]);
            return ;
        }
        rangeUpdate(left(p) , L, (L+R) / 2, i, j, nov);
        rangeUpdate(right(p), (L+R) / 2 + 1, R, i, j, nov);
        // printf("%d %d >> ( %d %d ) ", st[p], lazy[p], st[left(p)] , st[right(p)]);
        st[p] = st[left(p)] + st[right(p)];
        // printf("updo %d -> %d %d -> %d %d => %d\n", p, L, R, i, j, st[p]);
    }
    int getSum(int p, int L, int R, int i, int j) {
        lazyUpdate(p, L, R);
        if (i > R || j < L)
            return 0;
        if (L >= i && R <= j) {
            // printf("%d -> %d %d -> %d %d => %d\n", p, L, R, i, j, st[p]);
            return st[p];
        }
        int p1 = getSum(left(p) , L, (L+R) / 2, i, j);
        int p2 = getSum(right(p), (L+R) / 2 + 1, R, i, j);
        // printf("%d -> %d %d -> %d %d => %d\n", p, L, R, i, j, p1 + p2);
        return p1 + p2;
    }
public:
    SegmentTree(const vector<bool> &_A) {
        A = _A; n = (int)A.size();
        st.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(1, 0, n - 1);
    }
    int getSum(int i, int j) { return getSum(1, 0, n - 1, i, j); }
    void rangeUpdate(int i, int j, char nov) { rangeUpdate(1, 0, n - 1, i, j, nov); }
    // overloading
};

char pirStr[limN];
vector <bool> pirs;

void testCase() {
    int pirCnt = 0, Q;    
    for(scanf("%d", &Q); Q; Q--) {
        int rep ;
        char tmp[200];
        for(scanf("%d%s", &rep, tmp); rep; rep--)
            for(int w=0; tmp[w]; w++)
                pirStr[pirCnt++] = tmp[w];
    }
    pirStr[pirCnt] = 0;
    // printf("%s\n", pirStr);
    pirs.assign(pirCnt, false);
    for(int i=0; i<pirCnt; i++)
        if(pirStr[i]=='1')
            pirs[i] = true;
    SegmentTree st(pirs);
    int qCnt = 0;
    for(scanf("%d\n", &Q); Q; Q--) {
        char tip;
        int a, b;
        scanf("%c %d %d\n", &tip, &a, &b);
        // printf("%d %c %d %d\n", Q, tip, a, b);
        if(tip=='S') {
            printf("Q%d: %d\n", ++qCnt, st.getSum(a, b));
        }
        else {
            switch(tip) {
            case 'E':
                tip = 1;
                break;
            case 'F':
                tip = 2;
                break;
            default:
                tip = 3;
            }
            st.rangeUpdate(a, b, tip);
        }
    }
}

int main() {
    int tc;

    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("Case %d:\n", i);
        testCase();
    }
    
    return 0;
}
