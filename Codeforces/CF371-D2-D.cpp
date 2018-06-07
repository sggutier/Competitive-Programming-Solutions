#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;

struct BIT {
    int n = limN;
    int arr[limN];
    void mete(int pos, int nov) {
        for(; pos<n; pos+=(pos & -pos))
            arr[pos] += nov;
    }
    int saca(int pos) {
        int ans = 0;
        for(; pos; pos-=(pos & -pos))
            ans += arr[pos];
        return ans;
    }
    int rng(int ini, int fin) {
        return saca(fin) - saca(ini-1);
    }
};

int N;
int caps[limN], acum[limN];
BIT bt;

void query(int pos, int wot) {
    int ini = pos, fin = N;
    while(ini < fin) {
        int piv = (ini+fin)/2;
        if(bt.rng(pos, piv))
            fin = piv;
        else
            ini = piv+1;
    }
    for(pos = ini; pos<=N && wot; pos++) {
        if(!caps[pos]) continue;
        int w = min(wot, caps[pos]);
        acum[pos] += w;
        caps[pos] -= w;
        wot -= w;
        if(caps[pos]==0)
            bt.mete(pos, -1);
    }
}

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &caps[i]);
        bt.mete(i, 1);
    }
    int Q ;
    for(scanf("%d", &Q); Q; Q--) {
        int a, b, t;
        scanf("%d%d", &t, &a);
        if(t==1) {
            scanf("%d", &b);
            query(a, b);
        }
        else
            printf("%d\n", acum[a]);
    }
}
