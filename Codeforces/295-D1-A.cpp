#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 1e5 + 5;

class Node {
public:
    ll val, crg;
    Node *L, *R;
    Node(ll v): val(v), crg(0), L(NULL), R(NULL) {}
    Node(): val(0), crg(0), L(NULL), R(NULL) {}

    void push(ll len) {
        if(crg == 0) {
            return;
        }
        val += crg*len;
        if(L) {
            L->crg += crg;
            if(R) {
                R->crg += crg;
            }
        }
        crg = 0;
    }
};

class STree {
public:
    int n ;
    Node* root;

    static Node* makeTree(const int *arr, const int L, const int R) {
        if(L == R) {
            return new Node(arr? arr[L] : 0);
        }
        Node* ans = new Node();
        const int piv = (L + R) / 2;
        ans->L = makeTree(arr, L, piv);
        ans->val = ans->L->val;
        if(piv + 1 <= R) {
            ans->R = makeTree(arr, piv+1, R);
            ans->val += ans->R->val;
        }
        return ans;
    }

    STree(const int n, const int *arr): n(n) {
        root = makeTree(arr, 0, n-1);
    }

    ll query(const int qL, const int qR, const int L, const int R, Node* pos) {
        if(qR < L || R < qL) {
            return 0;
        }
        pos->push(R-L+1);
        if(qL <= L && R <= qR) {
            return pos->val;
        }
        const int piv = (L + R) / 2;
        return query(qL, qR, L, piv, pos->L) + (piv + 1 <= R? query(qL, qR, piv+1, R, pos->R) : 0LL);
    }

    ll query(const int qL, const int qR) {
        return query(qL, qR, 0, n-1, root);
    }

    void update(const int qL, const int qR, const ll crg, const int L, const int R, Node* pos) {
        if(qR < L || R < qL) {
            return ;
        }
        if(qL <= L && R <= qR) {
            pos->crg += crg;
            pos->push(R-L+1);
            return;
        }
        pos->push(R-L+1);
        const int piv = (L + R) / 2;
        update(qL, qR, crg, L, piv, pos->L);
        pos->val = pos->L->val;
        if(piv + 1 <= R) {
            update(qL, qR, crg, piv+1, R, pos->R);
            pos->val += pos->R->val;
        }
    }

    void update(const int qL, const int qR, const ll crg) {
        update(qL, qR, crg, 0, n-1, root);
    }
};

int main() {
    int N, M, K;
    STree *st, *qs;
    int arr[limN];
    int xs[limN], ys[limN], zs[limN];

    scanf("%d%d%d", &N, &M, &K);
    for(int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
    }
    st = new STree(N, arr);
    for(int i=0; i<M; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        xs[i] = a;
        ys[i] = b;
        zs[i] = c;
    }
    qs = new STree(M, NULL);
    for(int i=0; i<K; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        qs->update(a, b, 1);
    }
    for(int i=0; i<M; i++) {
        st->update(xs[i], ys[i], zs[i]*qs->query(i, i));
    }
    for(int i=0; i<N; i++) {
        printf("%lld ", st->query(i, i));
    }
    printf("\n");
}
