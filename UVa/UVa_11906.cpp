#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
#define r first
#define c second
const int dirCnt = 8;

void testCase() {
    int rowCnt, colCnt;
    par pos;
    int ans[] = {0, 0};
    vector<vector<int>> usd;
    queue <par> Q;
    int queryCnt;

    scanf("%d%d%d%d", &rowCnt, &colCnt, &pos.r, &pos.c);
    int dr[] = {-pos.r, -pos.r, -pos.c, -pos.c, pos.c, pos.c, pos.r, pos.r};
    int dc[] = {-pos.c, pos.c, -pos.r, pos.r, -pos.r, pos.r, -pos.c, pos.c};
    usd = vector<vector<int>> (rowCnt, vector<int>(colCnt));
    scanf("%d", &queryCnt);
    while(queryCnt--) {
        scanf("%d%d", &pos.r, &pos.c);
        usd[pos.r][pos.c] = 2 ;
    }

    if(usd[0][0] != 2) {
        Q.push(par(0,0));
        usd[0][0] = 1;
    }
    while(!Q.empty()) {
        pos = Q.front(); Q.pop();
        set<par> vald ;
        for(int d=0; d<dirCnt; d++) {
            par sig = pos;
            sig.r += dr[d], sig.c += dc[d];
            if(0 <= sig.r && sig.r < rowCnt && 0 <= sig.c && sig.c < colCnt && usd[sig.r][sig.c]!=2) {
                vald.insert(sig);
                if(usd[sig.r][sig.c]!=1) {
                    Q.push(sig);
                    usd[sig.r][sig.c]=1;
                }
            }
        }
        ans[((int) vald.size())%2] ++;
    }

    printf("%d %d\n", ans[0], ans[1]);
}

int main() {
    int tc;

    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("Case %d: ", i);
        testCase();
    }
    
    return 0;
}
