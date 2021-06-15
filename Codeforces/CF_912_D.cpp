#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define x first
#define y second
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, -1, 0, 1};

int R, C, L ;
priority_queue <pair<long double, pii> > Q ;
set <pii> usd;

long double clc(const int N, const int x) {
    return max(0, min(N-1-L, x) - max(0, x - L) + 1);
}

void mete(const pii nv) {
    if(nv.x < 0 || R <= nv.x || nv.y < 0 || C <= nv.y || usd.count(nv))
        return;    
    usd.insert(nv);
    Q.push({clc(R, nv.x) * clc(C, nv.y),
            nv});
}

int main() {
    int K ;
    long double ans = 0, div;

    scanf("%d%d%d%d", &R, &C, &L, &K);
    div = (R-L+1.0) ;
    div *= (C - L +1.0);
    L--;

    mete({R/2, C/2});
    mete({R/2 - 1, C/2});
    mete({R/2, C/2 - 1});
    mete({R/2 - 1, C/2 - 1});
   
    for(; K; K--) {
        pii pos = Q.top().y;
        ans += Q.top().x / div;
        Q.pop();
        for(int d=0; d<4; d++)
            mete({pos.x + dr[d], pos.y + dc[d]});
    }

    printf("%.9Lf\n", ans);
}
