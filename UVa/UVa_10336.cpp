#include <bits/stdc++.h>
using namespace std;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
typedef pair<int,int> par;
#define r first
#define c second

int cntSpc(const int &R, const int &C, vector <string> &mapo, par pos) {
    int ans = 0;
    queue <par> Q;
    char coro = mapo[pos.r][pos.c];
    mapo[pos.r][pos.c] = '.';
    Q.push(pos);
    while(!Q.empty()) {
        pos = Q.front(); Q.pop();
        ans ++;
        for(int d=0; d<4; d++) {
            par sig = par(pos.r + dr[d], pos.c+dc[d]);
            if(0 <= sig.r && sig.r < R && 0 <= sig.c && sig.c < C && mapo[sig.r][sig.c]==coro) {
                mapo[sig.r][sig.c] = '.';
                Q.push(sig);
            }
        }
    }
    return ans;
}

void testCase() {
    int R, C;
    scanf("%d%d", &R, &C);
    vector <string> mapo(R);
    vector <int> cnt(300);
    char tmp[C+5];
    for(int i=0; i<R; i++) {
        scanf("%s", tmp);
        mapo[i] = tmp;
    }

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(mapo[i][j]=='.')
                continue;
            int w = mapo[i][j];
            cntSpc(R, C, mapo, par(i, j));
            cnt[w] ++ ;
        }
    }

    vector <par> ans;

    for(int i=0; i<300; i++) {
        if(cnt[i])
            ans.push_back(par(-cnt[i], i));
    }
    

    sort(ans.begin(), ans.end());

    for(const auto &a:ans)
        printf("%c: %d\n", a.second, -a.first);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("World #%d\n", i);
        testCase();
    }
}
