#include <bits/stdc++.h>
using namespace std;
const int inf = 1<<30;
const int limN = 1e5 + 5;

struct item {
    int val, prior;
    bool crg;
    int cnt;
    item *l, *r;
    int mino;
    item() {}
    item(int val) : val(val), prior(random()), crg(false), cnt(1), l(NULL), r(NULL), mino(val) {}
};
typedef item* pitem;

int cnt(pitem t) {
    return t? t->cnt : 0;
}

int mino(pitem t) {
    return t? t->mino : inf;
}

void upd(pitem t) {
    if(!t) return;    
    t->cnt = 1 + cnt(t->l) + cnt(t->r);
    t->mino = min(min(mino(t->l), mino(t->r)),
                      t->val);
}

void push(pitem t) {
    if(t && t->crg) {
        t->crg = 0;
        swap(t->l, t->r);
        if(t->l) t->l->crg ^= 1;
        if(t->r) t->r->crg ^= 1;
    }
}

void split(pitem t, int k, pitem &l, pitem &r) {
    push(t);
    if(!t)
        l = r = NULL;
    else if(k < cnt(t->l) )
        split(t->l, k, l, t->l), r = t;
    else 
        split(t->r, k-cnt(t->l)-1, t->r, r), l = t;
    
    upd(t);
}

void merge(pitem &t, pitem l, pitem r) {
    push(l), push(r);
    if(!l || !r)
        t = l? l : r;
    else if(l->prior > r->prior)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    upd(t);
}

int posMino(pitem t) {
    if(!t) return -1;
    int ans = 0;
    int v = mino(t);
    while(mino(t) == v) {
        push(t);
        // printf("Estoy en %d con val %d y mino %d\n", cnt(t->l) + ans, t->val, mino(t));
        // printf("\tL tiene mino %d\n", mino(t->l));
        // printf("\tR tiene mino %d\n", mino(t->r));
        if(mino(t->l) > v) {
            ans += cnt(t->l) + 1;
            t = t->r;
        }
        else
            t = t->l;
    }
    return ans -1;
}

void printa(pitem t) {
    push(t);
    if(t->l) printa(t->l);
    printf("%d ", t->val);
    if(t->r) printa(t->r);
}

void printoro(pitem t) {
    printf("Arbol: ");
    if(t)
        printa(t);
    printf("\n");
    printf("\tTiene mino de %d en pos %d\n", mino(t), posMino(t));
}

void cga(pitem t) {
    if(t)
        t->crg ^= 1;
}

pitem t ;
int arr[limN];
int ordo[limN], invo[limN];

void testCase(int N) {
    t = NULL;
    for(int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
        ordo[i] = i;
    }
    sort(ordo, ordo+N,
         [](const int a, const int b) {
             if(arr[a] != arr[b])
                 return arr[a] < arr[b];
             return a < b;
         });
    for(int i=0; i<N; i++)
        invo[ordo[i]] = i;
    for(int i=0; i<N; i++) {
        merge(t, t, new item(invo[i]));
    }
    for(int i=1; i<=N; i++) {
        int sp = posMino(t);
        pitem x, y, z;
        // printf("i: %d\n", i);
        // printf("Anso es %d %d\n", mino(t), sp);
        printf("%d ", sp +i );
        // printoro(t);
        split(t, sp-1, x, y);
        split(y, 0, y, z);
        // printoro(x);
        // printoro(y);
        // printoro(z);
        cga(x);
        if(y)
            delete y;
        merge(t, x, z);
    }
    printf("\n");
}

int main() {
    int N ;
    while(scanf("%d", &N)!=EOF && N)
        testCase(N);
}
