#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define f first
#define s second
const int limN = 1e5 + 5;
const int ro = 316;
// const int ro = 2;
const int limR = limN / ro + 1;

struct Rgo {
    vector <pll> elems;
    vector<int> ords;
    deque <int> Q ;
    int id;
    void mete(ll a, ll b) {
        elems.push_back({a, b});
        ords.push_back((int) ords.size());
    }
    void prepara(int _id) {
        id = _id;
        sort(ords.begin(), ords.end(),
             [this] (const int &a, const int &b) {
                 if(elems[a].s != elems[b].s)
                     return elems[a].s < elems[b].s;
                 return elems[a].f > elems[b].f;
             });
        int N = elems.size();
        for(int w=0; w<N; w++) {
            if(w && elems[ords[w]].s == elems[ords[w-1]].s && elems[ords[w]].f < elems[ords[w-1]].f)
                continue;
            int i = ords[w];
            while(Q.size() >= 2) {
                int p = Q.front(); Q.pop_front();
                int q = Q.front();
                if( (elems[q].f - elems[p].f) * (elems[i].s - elems[p].s) <
                    (elems[p].f - elems[i].f) * (elems[p].s - elems[q].s) ) {
                    Q.push_front(p);
                    break;
                }
            }
            Q.push_front(i);
        }
        // printf("Rango preparado.  Elementos son: (%lld)\n", elems[Q.back()].f);
        // for(int i=0; i<(int) Q.size(); i++) {
        //     printf("%lld %lld (%d)\n", elems[Q[i]].f, elems[Q[i]].s, Q[i]);
        // }
    }
    pll sacaT(ll t) {
        while(Q.size() >= 2) {
            int p = Q.back(); Q.pop_back();
            int q = Q.back();
            if( elems[p].f + elems[p].s * t > elems[q].f + elems[q].s * t) {
                Q.push_back(p);
                break;
            }
        }
        int p = Q.back();
        return pll(elems[p].f + elems[p].s * t, p + id);
    }
};

int N ;
Rgo rangos[limR];
int A[limN], B[limN];

ll query(ll t, int l, int r) {
    pll ans = {0LL, 0LL};
    int pl = l, pr = r;
    for(; pl % ro && pl <= pr; pl++)
        ans = max(ans, {A[pl] + B[pl] * t, pl});
    for(; (pr+1) % ro && pl <= pr; pr--)
        ans = max(ans, {A[pr] + B[pr] * t, pr});
    // printf("=> %d %d\n", pl, pr);
    if(pl / ro < (pr+1) / ro) {
        int x = pl / ro, y = (pr+1) / ro;
        for(; x < y; x++) {
            ans = max(ans, rangos[x].sacaT(t) );
        }
    }
    // printf("El res fue %lld %lld\n", ans.f, ans.s);
    return ans.s + 1;
}

int main() {
    int Q ;
    ll anso[limN];
    tuple <int, int, int, int> qs[limN];

    scanf("%d%d", &N, &Q);
    for(int i=0; i<N; i++) {
        scanf("%d%d", &A[i], &B[i]);
        rangos[i/ro].mete(A[i], B[i]);
    }
    for(int i=0; i<Q; i++) {
        int a, b, t;
        scanf("%d%d%d", &a, &b, &t);
        a--, b--;
        qs[i] = {t, a, b, i};
    }

    sort(qs, qs+Q);
    for(int i=0; i<N; i+=ro)
        rangos[i/ro].prepara(i);
    for(int i=0; i<Q; i++) {
        int t, a, b, p;
        tie(t, a, b, p) = qs[i];
        // printf("Query %d %d %d %d\n", t, a, b, p);
        anso[p] = query(t, a, b);
    }

    for(int i=0; i<Q; i++)
        printf("%lld\n", anso[i]);    
}
