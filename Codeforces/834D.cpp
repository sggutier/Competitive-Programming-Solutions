#include <bits/stdc++.h>
using namespace std;
const int LIM_K = 55;
const int LIM_N = 35005;

const int inf = 1e9;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi, mset = inf, madd = 0, val = -inf;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
    Node(vector<int>& v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo)/2;
            l = new Node(v, lo, mid); r = new Node(v, mid, hi);
            val = max(l->val, r->val);
        }
        else val = v[lo];
    }
    int query(int L, int R) {
        if (R <= lo || hi <= L) return -inf;
        if (L <= lo && hi <= R) return val;
        push();
        return max(l->query(L, R), r->query(L, R));
    }
    void set(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) mset = val = x, madd = 0;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = max(l->val, r->val);
        }
    }
    void add(int L, int R, int x) {
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

int K ;
Node* dps[LIM_K];
int lastApr[LIM_N];
set <int> usds;

void procNum(const int x, const int pos) {
    for(int i=0; i < K; i++)
        dps[i]->add(lastApr[x], pos, 1);
    usds.insert(x);
    dps[0]->set(pos, pos+1, usds.size());
    for(int i=1; i < K; i++) {
        dps[i]->set(pos, pos+1, dps[i-1]->query(1, pos));
    }
    // for(int i=0; i < K; i++) {
    //     for(int j=1; j <= pos; j++)
    //         printf("%d ", dps[i]->query(j, j+1));
    //     printf("\n");
    // }
    // printf("-----\n");
    lastApr[x] = pos;
}

int main() {
    int N;
    vector<int> bas;
    scanf("%d%d", &N, &K);
    bas.resize(N+1, 0);
    for(int i=0; i < K; i++)
        dps[i] = new Node(bas, 0, N+1);
    for(int i=1, x; i <= N; i++) {
        scanf("%d", &x);
        procNum(x, i);
    }
    printf("%d\n", dps[K-1]->query(N, N+1));
}
