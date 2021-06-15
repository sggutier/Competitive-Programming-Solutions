#include <bits/stdc++.h>
using namespace std;
const int limN = 60;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

int R, C ;
char mapa[limN][limN];
bool usd[limN][limN];

int dfs(int r, int c, bool d=false) {
    if(r < 0 || r > R || c < 0 || c > C || mapa[r][c]=='*' ||
       (!d && usd[r][c]))
        return 0;
    usd[r][c] = true;
    if(d) mapa[r][c] = '*';
    int ans = 1;
    for(int i=0; i<4; i++)
        ans += dfs(r+dr[i], c+dc[i], d);
    return ans;
}

int main() {
    int K ;
    vector <tuple<int, int, int> > lks;
    
    scanf("%d%d%d", &R, &C, &K);
    R++, C++;
    for(int i=0; i<=C; i++)
        mapa[0][i] = mapa[R][i] = '.';
    for(int i=1; i<R; i++) {
        scanf("%s", mapa[i] + 1);
        mapa[i][0] = mapa[i][C] = '.';
    }
    dfs(0, 0);

    for(int i=1; i<R; i++) {
        for(int j=1; j<C; j++) {
            int w = dfs(i, j);
            if(w)
                lks.push_back({w, i, j});
        }
    }

    int ans = 0;
    sort(lks.begin(), lks.end());
    K = lks.size()-K;
    for(int i=0; i<K; i++) {
        int r, c, w;
        tie(w, r, c) = lks[i];
        // printf("Tapando en %d %d con %d\n", r, c, w);
        dfs(r, c, true);
        ans += w;
    }

    printf("%d\n", ans);
    for(int i=1; i<R; i++) {
        for(int j=1; j<C; j++) {
            printf("%c", mapa[i][j]);
        }
        printf("\n");
    }
}
