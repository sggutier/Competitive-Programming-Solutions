#include <bits/stdc++.h>
using namespace std;
const int limN = 105;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
const int limD = 4;

int N;
char mapa[limN][limN];

inline bool isinside(const int &r, const int &c) {
    return 0 <= r && r <N && 0 <= c && c<N;
}

bool anyOn(int r, int c) {
    bool ans = mapa[r][c] == 'x';
    mapa[r][c] = '.';
    for(int d=0; d<limD; d++) {
        int r2=r+dr[d], c2=c+dc[d];
        if(isinside(r2, c2) && mapa[r2][c2]!='.')
            ans |= anyOn(r2, c2);
    }
    return ans;
}

void testCase() {
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%s", mapa[i]);
    int ans = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(mapa[i][j]!='.')
                ans += anyOn(i, j);
        }
    }

    printf("%d\n", ans);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("Case %d: ", i);
        testCase();
    }
}
