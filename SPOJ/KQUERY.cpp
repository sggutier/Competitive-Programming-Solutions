#include <bits/stdc++.h>
using namespace std;
const int limN = 200005;
typedef pair<int,int> par;
typedef pair<int,par> tri;
typedef pair<int,tri> kva;
#define f first
#define s second

struct item {
    int key, prior;
    int cnt;
    item *l, *r;
    item(int key) : key(key), prior(rand()), cnt(1), l(NULL), r(NULL) {}
};
typedef item* pitem;

int cnt(pitem t) {
    return t? t->cnt : 0;
}

void updCnt(pitem t) {
    if(t)
        t->cnt = 1 + cnt(t->l) + cnt(t->r);
}

void merge(pitem &t, pitem l, pitem r) {
    if(!l || !r)
        t = l? l : r;
    else if(l->prior > r->prior)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    updCnt(t);
}

void split(pitem t, int k, pitem &l, pitem &r) {
    if(!t)
        l = r = NULL;
    else if(k < t->key)
        split(t->l, k, l, t->l), r = t;
    else
        split(t->r, k, t->r, r), l = t;
    updCnt(t);
}

void insert(pitem &t, pitem it) {
    if(!t)
        t = it;
    else if(it->prior > t->prior)
        split(t, it->key, it->l, it->r), t = it;
    else
        insert(it->key < t->key? t->l : t->r, it);
    updCnt(t);
}

int mens(pitem t, int k) {
    int ans = 0;
    while(t) {
        if(k < t->key)
            t = t->l;
        else {
            ans += cnt(t->l) + 1;
            t = t->r;
        }
    }
    return ans;
}

int cuenta(pitem t, int ini, int fin) {
    return mens(t, fin) - mens(t, ini-1);
}

int main() {
    srand(time(NULL));
    pitem t = NULL;
    int N, Q ;
    par nums[limN];
    kva quers[limN];
    int ans[limN];

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &nums[i].f);
        nums[i].s = i+1;
    }
    scanf("%d", &Q);
    for(int i=0; i<Q; i++) {
        scanf("%d%d%d", &quers[i].s.s.f, &quers[i].s.s.s, &quers[i].f);
        quers[i].s.f = i;
    }

    sort(nums, nums+N);
    sort(quers, quers+Q);
    for(int i=Q-1, j=N-1; i>=0; i--) {
        for(; j>=0 && nums[j].f > quers[i].f; j--) {
            insert(t, new item(nums[j].s));
            //printf("Metiendo %d en la %d\n", nums[j].f, nums[j].s);
        }
        //printf("Querieando %d de %d a %d (%d)\n", quers[i].f, quers[i].s.s.f, quers[i].s.s.s, quers[i].s.f);
        ans[quers[i].s.f] = cuenta(t, quers[i].s.s.f, quers[i].s.s.s);
    }

    for(int i=0; i<Q; i++)
        printf("%d\n", ans[i]);
}
