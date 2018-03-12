#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
typedef long long ll;

struct item {
    int val, prior;
    int cnt;
    item *l, *r;
    item() {}
    item(int val) : val(val), prior(rand()), cnt(1), l(NULL), r(NULL) {}
};
typedef item* pitem;

int cnt(const pitem t) {
    return t? t->cnt : 0;
}

void updCnt(const pitem t) {
    if(t)
        t->cnt = 1 + cnt(t->l) + cnt(t->r);
}

void merge(pitem &t, const pitem l, const pitem r) {
    if(!l || !r)
        t = l? l : r;
    else if(l->prior > r->prior)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    updCnt(t);
}

void split(const pitem t, const int k, pitem &l, pitem &r) {
    if(!t)
        l = r = NULL;
    else if(k < cnt(t->l))
        split(t->l, k, l, t->l), r = t;
    else
        split(t->r, k-cnt(t->l)-1, t->r, r), l = t;
    updCnt(t);
}

int erase(pitem &t, const int k) {
    // printf("%d (%d) => %d\n", cnt(t), t? cnt(t->l) : -1, k);
    // getchar();
    if(!t)
        return -1;
    int pos=cnt(t->l), ans;
    if(pos == k) {
        ans = t->val;
        merge(t, t->l, t->r);
    }
    else if(k < pos)
        ans = erase(t->l, k);
    else
        ans = erase(t->r, k-pos-1);
    updCnt(t);
    return ans;
}

void printa(pitem t) {
    if(t==NULL)
        return;
    printf("%lld (%lld) =>", (ll) t->val, (ll) cnt(t));
    if(t->l)
        printf(" %lld", (ll) t->l->val);
    else
        printf(" x");
    if(t->r)
        printf(" %lld", (ll) t->r->val);
    else
        printf(" x");
    printf("\n");
    printa(t->l);
    printa(t->r);
}

int main() {
    srand(time(NULL));
    pitem t = NULL;
    int N;
    int arr[limN];

    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr+N);
    for(int i=0; i<N; i++) {
        merge(t, t, new item(arr[i]));
        //printf("%d ", cnt(t));
    }
    //printf("\n");
    for(int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
    }
    //printa(t);
    for(int i=N-1; i>=0; i--) {
        //printf("Borrando %d\n", arr[i]);
        arr[i] = erase(t, arr[i]);
        // printf("El arbol ahora es\n");
        // printa(t);
    }
    for(int i=0; i<N; i++) {
        printf("%d\n", arr[i]);
    }
}
