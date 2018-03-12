#include <bits/stdc++.h>
using namespace std;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, -1, 0, 1};
const int limN = 105;

int N ;
int mapa[limN][limN];

int leeNum(int &n) {
    static int ult = -1;
    if(ult!=-1)
        n = ult;
    else
        n = 0;
    int sl = 0;
    char c ;
    if(ult==-1) {
        while(true) {
            c = getchar();
            if(c!='\n' && c!=' ')
                break;
        }
        n = n*10 + c-'0';
    }
    while(true) {
        c = getchar();
        if(!isdigit(c))
            break;
        n = n*10 + c-'0';
    }
    while(!isdigit(c) && c!='\n') {
        c = getchar();
    }
    if(isdigit(c))
        ult = c-'0';
    else {
        sl = true;
        ult = -1;
    }
    // printf("%d %d\n", sl, ult);
    return sl;
}

int dfs(int r, int c, int t) {
    if(mapa[r][c] != t)
        return 0;
    mapa[r][c] = 0;
    int ans = 1;
    for(int d=0; d<4; d++)
        ans += dfs(r+dr[d], c+dc[d], t);
    return ans;
}

int testCase() {
    memset(mapa, 0, sizeof(mapa));
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            mapa[i][j] = 1;
    // printf("CASO %d\n", N);
    for(int a=2; a<=N; ) {
        int r, c ;
        int t ;
        t = leeNum(r);
        t = leeNum(c);
        mapa[r][c] = a;
        // printf("%d %d ", r, c);
        if(t) {
            a++;
            // printf("\n");
        }
    }
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(mapa[i][j] && dfs(i, j, mapa[i][j])!=N)
                return false;
        }
    }
    return true;
}

int main() {
    while(leeNum(N)!=2 && N)
        printf("%s\n", testCase()? "good" : "wrong");
}
