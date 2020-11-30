#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long ull;
const int LIM_N = 8;
const int DFS_L = 8;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, -1, 0, 1};

int N ;
char mapa[LIM_N][LIM_N + 1];
int totCnt = 0;
set <ll> pss;

ull toBt(const int r, const int c) {
    return 1ULL << (r * LIM_N + c);
}

void dfs(const int r, const int c, const ull msk, const int rem = DFS_L - 1) {
    if(!rem) {
        pss.insert(msk);
        return;
    }
    for(int d = 0; d < 4; d++) {
        int x = r + dr[d], y = c + dc[d];
        if(x < 0 || x >= N || y < 0 || y >= N || mapa[x][y] == '*') {
            continue;
        }
        ull k = toBt(x, y);
        if(k & msk) {
            continue;
        }
        dfs(x, y, msk | k, rem-1);
    }
}

void testCase() {
    pss.clear();
    scanf("%d", &N);
    for(int i=0; i < N; i++) {
        scanf("%s", mapa[i]);
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(mapa[i][j] == '*') {
                continue;
            }
            dfs(i, j, toBt(i, j));
        }
    }

    printf("%d\n", (int) pss.size());
}

int main() {
    int T ;
    scanf("%d", &T);
    for(int i=0; i < T; i++) {
        testCase();
    }
}
