#include <stdio.h>
#include <set>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <random>
using namespace std;
typedef long long ll;

// random_device rd;
// mt19937 gen(rd());
// uniform_int_distribution<> dis;
// set <int> genos;


struct item {
    ll key;
    int prior;
    ll ps;
    int cnt ;
    item *l, *r;
    item() {}
    item(long long k) : key(k), prior(), ps(0LL), cnt(1), l(NULL), r(NULL) {        
        //do {
        //prior = dis(gen);
        prior = rand();
        //prior = random();
        // } while(genos.count(prior));
        // genos.insert(prior);
        //cout << prior << endl;
    }
};
typedef item* pitem;

int cnt(const pitem t) {
    return t? t->cnt : 0;
}

void updCnt(const pitem t) {
    if(t)
        t->cnt = 1 + cnt(t->l) + cnt(t->r);
}

void push(const pitem t) {
    if(t && t->ps) {
        t->key += t->ps;
        if(t->l) t->l->ps += t->ps;
        if(t->r) t->r->ps += t->ps;
        t->ps = 0;
    }
}


void split(const pitem t, ll k, pitem &l, pitem &r) {
    push(t);
    if(!t)
        l = r = NULL;
    else if(k < t->key)
        split(t->l, k, l, t->l), r = t;
    else
        split(t->r, k, t->r, r), l = t;
    updCnt(t);
}

void insert(pitem &t, const pitem it) {
    push(t);
    if(!t)
        t = it;
    else if(it->prior > t->prior)
        split(t, it->key, it->l, it->r), t = it;
    else
        insert(it->key < t->key? t->l : t->r, it);
    updCnt(t);
}

int cuenta(pitem t, ll k) {
    int ans = 0;
    while(t) {
        push(t);
        if(t->key < k)
            t = t->r;
        else {
            ans += 1+cnt(t->r);
            t = t->l;
        }
    }
    return ans;
}

int main() {
    //srandom(time(NULL));
    //srand(time(NULL));
    pitem t = NULL ;
    int n;
    unsigned int k ;
    long long ansaro = 0;
    scanf("%d", &n);
    scanf("%u", &k);
    //dis = uniform_int_distribution<>(-2147483647, 2147483647);
    for(long long i=1; i<=n; i++) {
        unsigned int a;
        scanf("%u", &a);
        // cin >> a;
        if(t)            
            t->ps += a;
        insert(t, new item(a + (i-1)*k));
        ansaro += cuenta(t, i*k);
        // if(t)            
        //     t->ps += a-k;
        // insert(t, new item(a -k));
        // ansaro += cuenta(t, 0LL);
    }
    printf("%lld\n", ansaro);
    return 0;
}
