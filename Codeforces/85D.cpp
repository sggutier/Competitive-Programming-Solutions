#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct item {
    int key, prior;
    item *l, *r;
    int cnt ;
    ll sumKs ;
    item() {
    }
    item(int key) : key(key), prior(rand()), l(NULL), r(NULL), cnt(1), sumKs(key) {}
};
typedef item* pitem;

ll getSm(pitem t) {
    return t? t->sumKs : 0;
}

int cnt(pitem t) {
    return t? t->cnt : 0;
}

void updSms(pitem t) {
    if(!t) return;
    t -> sumKs = t->key + getSm(t->l) + getSm(t->r);
    t -> cnt = 1 + cnt(t->l) + cnt(t->r);
}

void split(const pitem t, const int k, pitem &l, pitem &r) {
    if(!t)
        l = r = NULL;
    else if(k < t->key)
        split(t->l, k, l, t->l), r = t;
    else
        split(t->r, k, t->r, r), l = t;
    updSms(t);
}

void merge(pitem &t, const pitem l, const pitem r) {
    if(!l || !r)
        t = l? l : r;
    else if(l->prior > r->prior)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    updSms(t);
}

void insert(pitem &t, const pitem it) {
    if(!t)
        t = it;
    else if(it->prior > t->prior)
        split(t, it->key, it->l, it->r), t = it;
    else
        insert(it->key < t->key? t->l : t->r, it);
    updSms(t);
}

void erase(pitem &t, const int k) {
    if(!t)
        return;
    else if(t->key == k) {
        pitem w ;
        merge(w, t->l, t->r);
        delete t;
        t = w;
    }
    else
        erase(k < t->key? t->l : t->r, k);
    updSms(t);
}

void printKeys(pitem t, bool bl = true) {
    if(t == NULL) {
        if(bl)
            printf("\n");
        return;
    }
    printKeys(t->l, false);
    printf("%d ", t->key);
    printKeys(t->r, false);
    if(bl)
        printf("\n");
}

pitem genT;
pitem ts[5];

void addX(const int x) {
    pitem genL, genR;
    pitem ls[5], rs[5];
    int pos ;
    for(int i=0; i < 5; i++) {
        split(ts[i], x, ls[i], rs[i]);
    }
    split(genT, x, genL, genR);
    pos = cnt(genL);
    // printf("Tgt pos = %d\n", pos);
    merge(ls[pos % 5], ls[pos % 5], new item(x));
    merge(genL, genL, new item(x));
    for(int i=0; i < 5; i++) {
        merge(ts[i], ls[i], rs[(i+4) % 5]);
    }
    merge(genT, genL, genR);
}

void remX(const int x) {
    pitem genL, genR;
    pitem ls[5], rs[5];
    pitem px ;
    int pos ;
    for(int i=0; i < 5; i++) {
        split(ts[i], x, ls[i], rs[i]);
    }
    split(genT, x, genL, genR);
    split(genL, x-1, genL, px);
    pos = cnt(genL);
    split(ls[pos % 5], x-1, ls[pos % 5], px);
    for(int i=0; i < 5; i++) {
        merge(ts[i], ls[i], rs[(i+1) % 5]);
    }
    merge(genT, genL, genR);
}

int main() {
    srand(time(NULL));
    int Q ;
    char tmp[15];

    scanf("%d", &Q);
    for(int i=0; i < Q; i++) {
        scanf("%s", tmp);
        if(tmp[0] == 's') {
            printf("%lld\n", getSm(ts[2]));
            continue;
        }
        int x ;
        scanf("%d", &x);
        (tmp[0] == 'a'? addX : remX)(x);
        // printf("T:\n\t");
        // printKeys(genT);
        // for(int i=0; i < 5; i++) {
        //     printf("%d:\n\t", i);
        //     printKeys(ts[i]);
        // }
    }
}
