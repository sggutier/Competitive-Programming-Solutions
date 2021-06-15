#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 15;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
const int LIM_C = 128;

int dirs[LIM_C];

inline bool inside(const int x, const int y, const int R, const int C) {
    return 0 <= x && x < R && 0 <= y && y < C ;
}

void testCase(const int R, const int C, const int K) {
    vector <vector<int>> stp(R, vector<int>(C, -1));
    char mapa[LIM_N][LIM_N];
    for(int i=0; i < R; i++)
        scanf("%s", mapa[i]);
    int x = 0, y = K - 1;
    int t = 0 ;
    while(inside(x, y, R, C) && stp[x][y] == -1) {
        stp[x][y] = t++;
        int d = dirs[(int) mapa[x][y]];
        x += dr[d];
        y += dc[d];
    }
    if(inside(x, y, R, C)) {
        printf("%d step(s) before a loop of %d step(s)\n", stp[x][y], t - stp[x][y]);
    }
    else {
        printf("%d step(s) to exit\n", t);
    }
}

int main() {
    dirs['N'] = 0;
    dirs['E'] = 1;
    dirs['S'] = 2;
    dirs['W'] = 3;
    int R, C, K ;
    while(scanf("%d%d%d", &R, &C, &K) != EOF && (R && C)) {
        testCase(R, C, K);
    }
}
