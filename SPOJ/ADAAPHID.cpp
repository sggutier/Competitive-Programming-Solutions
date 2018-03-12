#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uu;

struct item {
    int prior;
    ll key;
    uu sumo ;
    uu sumoTot ;
    item *l = NULL, *r = NULL;
    item() {
        sumo = 0;
    }
    item(ll key) : key(key), l(NULL), r(NULL) {
        prior = random();
        sumoTot = sumo;
        sumo = 0;
    }
    item(ll key, uu sumo) : key(key), l(NULL), r(NULL) {
        prior = random();
        sumoTot = sumo;
        this->sumo = sumo;
    }
};
typedef item* pitem;

uu sumo (pitem t) {
    return t ? t->sumoTot : 0;
}

void upd_sumo (pitem t) {
    if (t)
        t->sumoTot = t->sumo + sumo(t->l) + sumo(t->r);
}

void split(pitem t, ll k, pitem &l, pitem &r) {
    if(!t)
        l = r = NULL;
    else if(k < t->key)
        split(t->l, k, l, t->l), r = t;
    else
        split(t->r, k, t->r, r), l = t;
    upd_sumo(t);
}

void insert(pitem &t, pitem it) {
    if(!t)
        t = it;
    // else if(t -> key == it->key) {
    //     t->sumo += it->sumo;
    //     delete it;
    // }
    else if(it->prior > t->prior)
        split(t, it->key, it->l, it->r), t = it;
    else
        insert(it->key < t->key? t->l : t->r, it);
    upd_sumo(t);
}

void merge(pitem &t, pitem l, pitem r) {
    if(!l || !r)
        t = l? l : r;
    else if(l->prior > r->prior)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    upd_sumo(t);
}

// void printa(pitem t) {
//     if(t==NULL)
//         return;
//     printf("%lld (%lld %lld) =>", (ll) t->key, (ll) t->sumo, (ll) t->sumoTot);
//     if(t->l)
//         printf(" %lld", (ll) t->l->key);
//     else
//         printf(" x");
//     if(t->r)
//         printf(" %lld", (ll) t->r->key);
//     else
//         printf(" x");
//     printf("\n");
//     printa(t->l);
//     printa(t->r);
// }

// void pll(ll a) {
//     printf("%lld", (ll) a);
//     return;
//     if(a==0)
//         return;
//     pll(a/10);
//     printf("%d", (int) a%10);
// }
bool find(const pitem t, const ll k, const uu val) {
    if(t==NULL)
        return false;
    else if(t->key == k) {
        t->sumo += val;
        t->sumoTot += val;
        return true;
    }
    bool ans = find(t->key < k? t->l : t->r, k, val);
    if(ans)
        upd_sumo(t);
    return ans;
}

int main() {
    srand(time(NULL));
    pitem t = NULL;
    int Q;
    ll L = 0;
    scanf("%d", &Q);
    while(Q--) {
        //ll x, y;
        ll a, b ;
        pitem t2, t3 ;
        scanf("%lld%lld", &a, &b);
        //ll a, b;
        // a = ((ll) x) ^ L;
        // b = ((ll) y) ^ L;
        a ^= L;
        b ^= L;
        // while(b >= 1000) ;
        //printf("%lld %lld => ", a, b);
        // split(t, a-1, t2, t3);
        // split(t3, a, t3, t4);
        // printf("Menos\n");
        // printa(t2);
        // printf("Igual\n");
        // printa(t3);
        // printf("Mas\n");
        // printa(t4);
        // if(t3 != NULL) {
        //     t3 -> sumo += b;
        //     merge(t3, t3, t4);
        //     merge(t, t2, t3);
        // }
        // else {
        //     merge(t, t2, t4);
        //     insert(t, new item(a, b));
        // }
        if(!find(t, a, b))
            insert(t, new item(a, b));
        // printf("Res\n");
        // printa(t);        
        split(t, a, t2, t3);
        L = sumo(t2);
        //printf("%lld %lld\n", a, L);
        //printf("========== ");
        // pll(a);
        // printf(" ");
        // //pll(sumo(t2));
        // pll(L);
        // printf("\n");
        printf("%lld %lld\n", a, L);
        merge(t, t2, t3);
    }
}
