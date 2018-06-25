#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 50000;
// const int H = (1<<16);
const int H = 250005;

struct STree {
    int cnt = 0;
    STree *l = NULL, *r = NULL;
    void insert(const int p) {
        int l = 1;
        int r = limN-1;
        STree *t = this;
        int mt;
        while(true) {
            t->cnt ++;
            if(l==r)
                break;
            mt = (l+r) / 2;
            if(p <= mt) {
                if(t->l == NULL)
                    t->l = new STree();
                r = mt;
                t = t->l;
            }
            else {
                if(t->r == NULL)
                    t->r = new STree();
                l = mt+1;
                t = t->r;
            }
        }
    }
    // void erase(const int p)  {
    //     int l = 1;
    //     int r = limN-1;
    //     STree *t = this;
    //     int mt;
    //     while(true) {
    //         t->cnt --;
    //         if(l==r)
    //             break;
    //         mt = (l+r) / 2;
    //         if(p <= mt) {
    //             r = mt;
    //             t = t->l;
    //         }
    //         else {
    //             l = mt+1;
    //             t = t->r;
    //         }
    //     }
    // }
    
    void erase(const int p, const int xl = 1, const int xr = limN-1) {
        cnt --;
        if(xl == xr)
            return;
        int mt = (xl + xr) / 2;
        if(p <= mt) {
            l->erase(p, xl, mt);
            if(l->cnt == 0) {
                delete l;
                l = NULL;
            }
        }
        else {
            r->erase(p, mt+1, xr);
            if(r->cnt == 0) {
                delete r;
                r = NULL;
            }
        }
    }
    int order_of_key(const int p) {
        int l = 1;
        int r = limN-1;
        STree *t = this;
        int mt;
        int ans = 0;
        while(l < r) {
            mt = (l+r) / 2;
            if(p <= mt) {
                if(t->l == NULL)
                    break;
                r = mt;
                t = t->l;
            }
            else {                
                if(t->l)
                    ans += t->l->cnt ;
                if(t->r == NULL)
                    break;
                l = mt+1;
                t = t->r;
            }
        }
        return ans;
    }
};

STree ords[H*2 + 5];

void mete(int x, int y) {
    for(y += H; y; y>>=1)
        ords[y].insert(x);
}

void saca(int x, int y) {
    for(y += H; y; y>>=1)
        ords[y].erase(x);
}

int cuenta(int xl, int xr, int yl, int yr) {
    if(xr < xl || yr < yl)
        return 0;
    int ans = 0;
    for(yl += H, yr += H+1; yl<yr; yl>>=1, yr>>=1) {
        if(yl & 1) {
            ans += ords[yl].order_of_key(xr+1) - ords[yl].order_of_key(xl) ;
            yl ++;
        }
        if(yr & 1) {
            yr --;
            ans += ords[yr].order_of_key(xr+1) - ords[yr].order_of_key(xl) ;
        }
    }
    return ans;
}

int main() {
    int N ;
    int arr[250005];
    int Q ;
    ll ans = 0;

    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &arr[i]);
        mete(i, arr[i]);
        ans += cuenta(1, i-1, arr[i]+1, H);
    }

    for(scanf("%d", &Q); Q; Q--) {
        int x, y, z;
        scanf("%d%d", &x, &y);
        z = y;        
        y = arr[x];

        if(z==y) {
            printf("%lld\n", ans);
            continue;
        }

        if(z < y) {
            ans += cuenta(1, x-1, z+1, y);
            ans -= cuenta(x+1, N, z, y-1);
        }
        else {
            ans -= cuenta(1, x-1, y+1, z);
            ans += cuenta(x+1, N, y, z-1);
        }
        // ans -= cuenta(1, x-1, y+1, H);
        // ans -= cuenta(x+1, N, 0, y-1);
        saca(x, y);
        arr[x] = z;
        mete(x, z);
        // y = z;
        // ans += cuenta(1, x-1, y+1, H);
        // ans += cuenta(x+1, N, 0, y-1);
        
        printf("%lld\n", ans);
    }
}
