// - More or less like in the editorial: https://www.hackerrank.com/challenges/meeting-point/editorial
#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
typedef long long ll;

int N;
int xs[limN], ys[limN];
int posX[limN], posY[limN];
ll sumXP[limN], sumXM[limN], sumYP[limN], sumYM[limN];
int invX[limN], invY[limN];

void cargaSum(int *pos, int *ord, ll *ans, const int ini, const int fin, const int dir) {
    ans[ini] = 0;
    ll cnt = 1;
    for(int i=ini+dir, p, q; i!=fin; i+=dir, cnt++) {
        p = ord[i], q = ord[i-dir];
        ans[i] = ans[i-dir] + cnt*abs(pos[p] - pos[q]);
    }
    // printf("Cords are:");
    // for(int i=0; i<N; i++)
    //     printf("%d ", pos[ord[i]]);
    // printf("\n");
    // printf("%d %d %d => ", ini, fin, dir);
    // for(int i=0; i<N; i++)
    //     printf("%lld ", ans[i]);
    // printf("\n");
}

int main() {
    ll ans = (1LL<<62) - 1;
    
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d%d", &xs[i], &ys[i]);
        int a, b ;
        a = xs[i] + ys[i];
        b = ys[i] - xs[i];
        xs[i] = a;
        ys[i] = b;
        posX[i] = i;
        posY[i] = i;
        // printf("\t%d %d\n", a, b);
    }
    sort(posX, posX+N,
         [](const int a, const int b) {
             return xs[a] < xs[b];});
    sort(posY, posY+N,
         [](const int a, const int b) {
             return ys[a] < ys[b];});
    cargaSum(xs, posX, sumXP, 0, N, 1);
    cargaSum(xs, posX, sumXM, N-1, -1, -1);
    cargaSum(ys, posY, sumYP, 0, N, 1);
    cargaSum(ys, posY, sumYM, N-1, -1, -1);
    for(int i=0; i<N; i++) {
        invX[posX[i]] = i;
        invY[posY[i]] = i;
    }

    // printf("----- ");
    // for(int i=0; i<N; i++)
    //     printf("%lld ", sumXP[i]);
    // printf("\n");
    // printf("----- ");
    // for(int i=0; i<N; i++)
    //     printf("%lld ", sumXM[i]);
    // printf("\n");
    // printf("----- ");
    // for(int i=0; i<N; i++)
    //     printf("%lld ", sumYP[i]);
    // printf("\n");
    // printf("----- ");
    // for(int i=0; i<N; i++)
    //     printf("%lld ", sumYM[i]);
    // printf("\n");
    // printf("<<<<< ");
    // for(int i=0; i<N; i++)
    //     printf("%d ", invX[i]);
    // printf("\n");
    // printf("<<<<< ");
    // for(int i=0; i<N; i++)
    //     printf("%d ", invY[i]);
    // printf("\n");

    for(int i=0; i<N; i++) {
        int px = invX[i], py = invY[i];
        ans = min(ans,
                  sumXP[px] + sumXM[px] + sumYP[py] + sumYM[py]);
    }

    printf("%lld\n", ans/2);

    // for(int i=0; i<N; i++) {
    //     ll sumo = 0;
    //     for(int j=0; j<N; j++) {
    //         sumo += abs(xs[i] - xs[j]);
    //         sumo += abs(ys[i] - ys[j]);
    //     }
    //     ans = min(sumo, ans);
    //     printf("For %d %d sum is %lld\n", xs[i], ys[i], sumo);
    // }
    // printf("\ttru ans is %lld\n", ans/2);
}
