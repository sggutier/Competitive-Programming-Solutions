#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 15;
const int LIM_C = 12;
const int LIM_B = 1 << LIM_C;

bool usd[LIM_N][LIM_N][LIM_B];
int dst[LIM_N][LIM_N][LIM_B];
int mat[LIM_N][LIM_N];
int movsX[LIM_C], movsY[LIM_C];

void testCase(const int R, const int C, const int K, const int T) {
    memset(usd, 0, sizeof(usd));
    int x, y, msk = 0 ;
    for(int i = 0; i < K; i++) {
        scanf("%d%d", &movsY[i], &movsX[i]);
        movsX[i] *= -1;
    }
    for(int i=0; i < T; i++) {
        int a ;
        scanf("%d", &a);
        a-- ;
        msk |= 1 << a;
        // printf(">> %d\n", a);
    }
    // printf("<><> %d %d\n", R, C);
    for(int i=0; i < R; i++) {
        for(int j=0; j < C; j++) {
            scanf("%d", &mat[i][j]);
            mat[i][j] --;
        }
    }
    queue <tuple<int,int,int>> Q ;
    x = R-1;
    y = 0;
    // printf("%d %d %d => ", x, y, msk);
    // printf("\n");
    Q.push({x,y,msk});
    usd[x][y][msk] = true;
    dst[x][y][msk] = 0;
    while(!Q.empty()) {
        auto w = Q.front(); Q.pop();
        tie(x,y,msk) = w;
        int s = dst[x][y][msk];
        // printf("%d %d %d => ", x, y, msk);
        // printf("%d\n", s);
        if(x == 0 && y == C-1) {
            printf("%d\n", s);
            return ;
        }
        s ++;
        for(int d=0; d < K; d++) {
            if(!((1 << d) & msk))
                continue;
            int a = x + movsX[d],  b = y + movsY[d];
            // printf("\t%d %d\n", a, b);
            if(a < 0 || a >= R || b < 0 || b >= C || usd[a][b][msk])
                continue;
            // printf("\tOK\n");
            usd[a][b][msk] = true;
            dst[a][b][msk] = s;
            Q.push({a, b, msk});
        }
        // printf("\tMat at %d %d is %d\n", x, y, mat[x][y]);
        if(mat[x][y] != -1) {
            msk |= 1 << mat[x][y];
            // printf("\tNeomsk %d\n", msk);
            if(!usd[x][y][msk]) {
                usd[x][y][msk] = true;
                dst[x][y][msk] = s;
                Q.push({x,y,msk});
            }
        }
    }
    printf("-1\n");
}

int main() {
    int a, b, c, d;
    int tc = 0 ;
    while(scanf("%d%d%d%d", &a, &b, &c, &d) != EOF && a) {
        printf("Case #%d: ", ++tc);
        testCase(a, b, c, d);
    }
}
