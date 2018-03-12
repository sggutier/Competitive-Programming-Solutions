#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
#define r first
#define c second
const int limN = 30;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

int rows, cols;
char mapa[limN][limN];
char gutChar ;

inline bool validPos(par pos) {
    return 0 <= pos.r && pos.r < rows && 0 <= pos.c && pos.c < cols && mapa[pos.r][pos.c]==gutChar; 
}

int dfs(par pos) {
    int ans = 1;
    mapa[pos.r][pos.c] = gutChar+1;
    for(int d=0; d<4; d++) {
        par sig = pos;
        sig.r += dr[d], sig.c = (sig.c + cols + dc[d])%cols;
        if(validPos(sig))
            ans += dfs(sig);
    }
    return ans;
}

void testCase() {
    par pos;
    int ans =0;
    for(int i=0; i<rows; i++)
        scanf("%s", mapa[i]);
    scanf("%d%d", &pos.r, &pos.c);
    gutChar = mapa[pos.r][pos.c];
    dfs(pos);
    // pos.r--, pos.c--;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(mapa[i][j]==gutChar) {
                // ans ++;
                ans = max(ans, dfs(par(i,j)));
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    while(scanf("%d%d", &rows, &cols)!=EOF)
        testCase();
    
    return 0;
}
