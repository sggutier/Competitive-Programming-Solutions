#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int limN = 3005;

bool forb[limN];

struct Mod {
    ll x ;
    Mod() {}
    Mod(ll _x) : x(_x) {}
};

Mod operator-(const Mod a, const Mod b) {
    return (a.x + mod - b.x) % mod;
}

Mod operator+(const Mod a, const Mod b) {
    return (a.x + b.x) % mod;
}

Mod operator*(const Mod a, const Mod b) {
    return (a.x * b.x) % mod;
}

struct nodo {
    nodo *p = NULL;
    nodo *l = NULL, *r = NULL;
    char c = 0;
    Mod cnt = 0;
    nodo() {
        cnt = Mod(1);
    }
    nodo(nodo *_p, char _c) : p(_p), c(_c) {
        // printf("\tcreando con %c\n", c);
        nodo *pos = this, *a = p;
        int nm = 0;
        for(int i=1; i<=4 && a; i++) {
            nm = (nm<<1) + pos->c - '0';
            // printf("\t %d %d\n", i, nm);
            if(i != 4 || !forb[nm])
                cnt = cnt + a->cnt;
            pos = a;
            a = a->p;
        }
    }
};

Mod ans[limN];

void mete(nodo *p, char *s, int pos) {
    if(*s == 0) return;
    // printf("en %s\n", s);
    if(*s == '0') {
        if(p -> l == NULL) {
            p -> l = new nodo(p, *s);
            ans[pos] = ans[pos] + p->l->cnt;
        }
        mete(p->l, s+1, pos+1);
    }
    else {
        if(p -> r == NULL) {
            p -> r = new nodo(p, *s);
            ans[pos] = ans[pos] + p->r->cnt;
        }
        mete(p->r, s+1, pos+1);
    }
}

nodo *rt = new nodo() ;

int N ;
char S[limN];

int main() {
    forb[12] = forb[10] = forb[7] = forb[15] = 1;

    scanf("%d", &N);
    for(int i=0, a; i<N; i++) {
        scanf("%d", &a);
        S[i] = a + '0';
    }

    for(int i=0; i<N; i++)
        mete(rt, S+i, i);

    Mod w = 0;
    for(int i=0; i<N; i++) {
        w = w + ans[i];
        printf("%lld\n", w.x);
    }
}
                      
