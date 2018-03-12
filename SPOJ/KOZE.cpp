#include <bits/stdc++.h>
using namespace std;
const int limN = 305;
typedef pair<int,int> par;
#define f first
#define s second
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, -1, 0, 1};

int R, C ;
char mapa[limN][limN];

pair <int,int> dfs(int r, int c) {
    if(r<0 || r>=R || c<0 || c>=C || mapa[r][c]=='#')
        return {0, 0};
    par ans = {mapa[r][c]=='v'? 1 : 0,
               mapa[r][c]=='k'? 1 : 0};
    mapa[r][c] = '#';
    for(int d=0; d<4; d++) {
        par tmp = dfs(r+dr[d], c+dc[d]);
        ans = {ans.f + tmp.f, ans.s + tmp.s};
    }
    return ans;
}

int main() {
    par ans = {0, 0};
    
    scanf("%d%d", &R, &C);
    for(int i=0; i<R; i++)
        scanf("%s", mapa[i]);

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            par tmp = dfs(i, j);
            if(tmp.f >= tmp.s)
                ans.f += tmp.f;
            else
                ans.s += tmp.s;
        }
    }

    printf("%d %d\n", ans.s, ans.f);
}
