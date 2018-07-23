#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define f first
#define s second
const int limN = 5e5 + 5;
const int inf = 1e9;
const pii infp = {inf, -1};

struct node {
    pii val;
    node *l, *r;
    node(pii val) : val(val), l(NULL), r(NULL) {}
    node(node *l, node *r) ;
};
typedef node* nodep;

pii getVal(nodep t) {
    return t? t->val : infp;
}

node::node(nodep l, nodep r) {
    this->l = l;
    this->r = r;
    this->val = min(getVal(l), getVal(r));
}

pii query(nodep t, int l, int r, int L, int R) {
    if(L > R || r < L || R < l)
        return infp;
    // printf("querieando de %d a %d buscando %d %d\n", L, R, l, r);
    if(l <= L && R <= r)
        return t->val;
    int mt = (L + R) / 2;
    return min(query(t->l, l, r, L, mt),
               query(t->r, l, r, mt+1, R));
}

nodep update(nodep t, int pos, int nov, int L, int R) {
    if(L == R)
        return new node({nov, pos});
    int mt = (L + R) / 2;
    if(pos <= mt)
        return new node(update(t->l, pos, nov, L, mt),
                        t->r);
    else
        return new node(t->l,
                        update(t->r, pos, nov, mt+1, R));
}

map <int, int> ultApr;
nodep arbos[limN];
int arr[limN];

int main() {
    int N, Q;
    scanf("%d", &N);

    arbos[0] = new node(infp);
    arbos[0]->r = arbos[0]->l = arbos[0];
    for(int i=1, a, u; i<=N; i++) {
        scanf("%d", &a);
        arbos[i] = arbos[i-1];
        u = ultApr.count(a)? ultApr[a] : -1;
        if(u != -1)
            arbos[i] = update(arbos[i], ultApr[a], inf, 1, N);
        // printf("En %d con %d el u es %d\n", i, a, u);
        arbos[i] = update(arbos[i], i, u, 1, N);
        ultApr[a] = i;
        arr[i] = a;        
    }
    
    scanf("%d", &Q);
    for(int i=0, l, r; i<Q; i++) {
        scanf("%d%d", &l, &r);
        pii ans = query(arbos[r], l, r, 1, N);
        // printf("%d %d\n", ans.f, ans.s);
        printf("%d\n", ans.f >= l? 0 : arr[ans.s] );
    }
}
