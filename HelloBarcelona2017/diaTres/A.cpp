#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
typedef pair<int,int> par;
#define f first
#define s second

struct BIT {
    int N;
    int arr[limN];
    BIT() {
        N = limN;
    }
    void mete(int pos, int nov) {
        for(; pos<N; pos+=(pos & -pos))
            arr[pos] += nov;
    }
    int saca(int pos) {
        int ans = 0;
        for(; pos>0; pos-=(pos & -pos))
            ans += arr[pos];
        return ans;
    }
    void meteRango(int L, int R) {
        mete(L, 1);
        mete(R+1, -1);
    }
    void quitaRango(int L, int R) {
        mete(L, -1);
        mete(R+1, 1);
    }
};

void testCase() {
    int N, M;
    BIT bt;
    vector <int> ptsY[limN];
    vector <par> rans[limN];

    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a++, b++;
        ptsY[a].push_back(b);
    }
    for(int i=0; i<M; i++) {
        int xini, yini, xfin, yfin;
        scanf("%d%d%d%d", &xini, &xfin, &yini, &yfin);
        xini++, xfin++, yini++, yfin++;
        rans[xini].push_back(par(yini, yfin));
        rans[xfin+1].push_back(par(-yini, -yfin));
    }

    long long ans = 0;

    for(int i=0; i<limN; i++) {
        for(const par &r:rans[i]) {
            if(r.f < 0)
                bt.quitaRango(-r.f, -r.s);
            else
                bt.meteRango(r.f, r.s);
        }
        for(const int &y:ptsY[i]) {
            ans += bt.saca(y);
        }
    }

    printf("%lld\n", ans);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        testCase();
    }
}
