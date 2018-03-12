#include <bits/stdc++.h>
#define fs first
#define sn second
using namespace std;

typedef pair <int, int> pii;
typedef pair <int, pii> piii;

long long ANS;
int H, W, A, B, MP[505][505], CT[505][505];
priority_queue <piii> Q;

int di[] = {-1, -1, -1, 0, 0, 1, 1, 1},
    dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool inside(int i, int j) {
    return 0 <= i && i < H && 0 <= j && j < W;
}

int main() {
    scanf("%d %d", &H, &W);

    for(int i=0;i<H;i++)
        for(int j=0;j<W;j++)
            scanf("%d", &MP[i][j]), MP[i][j] *= -1;

    scanf("%d %d", &A, &B); A--, B--;

    CT[A][B] = MP[A][B];
    Q.push({ MP[A][B], { A, B } });

    while(!Q.empty()) {
        piii E = Q.top(); Q.pop();
        if(E.fs < CT[E.sn.fs][E.sn.sn]) continue;

        for(int k = 0; k < 8; k++) {
            int ni = E.sn.fs + di[k],
                nj = E.sn.sn + dj[k];

            if(!inside(ni, nj) || MP[ni][nj] <= 0)
                continue;

            piii NE = { min(E.fs, MP[ni][nj]), { ni, nj } };

            if(NE.fs > CT[NE.sn.fs][NE.sn.sn]) {
                CT[NE.sn.fs][NE.sn.sn] = NE.fs;
                Q.push(NE);
            }
        }
    }

    for(int i=0;i<H;i++)
        for(int j=0;j<W;j++)
            ANS += CT[i][j];

    printf("%lld\n", ANS);

    return 0;
}
