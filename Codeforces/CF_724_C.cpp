#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> pii;
#define x first
#define y second
const int limN = 1e5 + 5;
typedef long long ll;

int N, M ;

tuple<int, pii, int, int> iseca(pii pos, int dx, int dy) {
    int txl, txr, tyl, tyr;
    int mino ;
    txl = -pos.x/dx;
    txr = (N-pos.x)/dx;
    tyl = -pos.y/dy;
    tyr = (M-pos.y)/dy;
    mino = min(txl>0? txl : txr, tyl>0? tyl : tyr);
    pos.x += dx*mino;
    pos.y += dy*mino;
    if(txl == mino || txr == mino)
        dx *= -1;
    else
        dy *= -1;
    return {mino, pos, dx, dy};
}

set <int> dias[2*limN + 5][2];
ll usdSenc[limN];

int main() {
    int K ;
    int dx = 1, dy = 1;
    pii pos = {0, 0};
    set < pair<pii, pii> > usdPos;
    pii cords[limN];

    scanf("%d%d%d", &N, &M, &K);
    for(int i=0; i<K; i++) {
        int a, b ;
        scanf("%d%d", &a, &b);
        cords[i] = {a, b};
        dias[a+b][0].insert(i);
        dias[a-b + limN][1].insert(i);
        // printf("Insertando %d en %d %d\n", i, a+b, 0);
        // printf("Insertando %d en %d %d\n", i, a-b+limN, 1);
    }

    ll t = 0;
    while(usdPos.count({pos, {dx, dy}}) == 0) {
        if(t!=0 && pos.x % N == 0 && pos.y % M == 0)
            break;
        int dg, tp ;
        usdPos.insert({pos, {dx, dy}});
        if(dx != dy)
            dg = pos.x + pos.y, tp = 0;
        else
            dg = pos.x - pos.y + limN, tp = 1;
        // printf("pos es %d %d\n", pos.x, pos.y);
        // printf("dg es %d, tp es %d\n", dg, tp);
        for(const int &i:dias[dg][tp]) {
            usdSenc[i] = usdSenc[i]==0? t + min(abs(cords[i].x - pos.x), abs(cords[i].y - pos.y)) : usdSenc[i];
            if(tp==0)
                dias[cords[i].x - cords[i].y + limN][1].erase(i);
            else
                dias[cords[i].x + cords[i].y][0].erase(i);
            // printf("\t%d %d encontrado en %d\n", cords[i].x, cords[i].y, min(abs(cords[i].x - pos.x), abs(cords[i].y - pos.y)) + t);
        }
        dias[dg][tp].clear();
        tie(tp, pos, dx, dy) = iseca(pos, dx, dy);
        t += tp;
    }

    for(int i=0; i<K; i++) {
        printf("%lld\n", usdSenc[i]==0? -1 : usdSenc[i]);
    }
}
