#include <bits/stdc++.h>
using namespace std;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, -1, 0, 1};
const int LIM_N = 1e6 + 5;

int orgReps[LIM_N];

vector <vector<int>> vals ;

inline bool isValid(const int R, const int C, const int r, const int c) {
    return 0 <= r && r < R && 0 <= c && c < C && vals[r][c] == -1;
}

bool bfs(const int R, const int C, const int iniX, const int iniY) {
    queue <int> qx, qy;
    vector <int> reps(R + C);
    vals = vector <vector<int>>(R, vector<int>(C, -1));
    qx.push(iniX);
    qy.push(iniY);
    vals[iniX][iniY] = 0;
    while(!qx.empty()) {
        int x = qx.front(); qx.pop();
        int y = qy.front(); qy.pop();
        for(int d=0; d < 4; d++) {
            int a = x + dr[d], b = y + dc[d];
            if(!isValid(R, C, a, b)) continue;
            vals[a][b] = vals[x][y] + 1;
            qx.push(a);
            qy.push(b);
        }
    }
    for(int i=0; i < R; i++) {
        for(int j=0; j < C; j++) {
            reps[vals[i][j]] ++;
        }
    }
    for(int i=0; i < R + C; i++)
        if(reps[i] != orgReps[i])
            return false;
    return true;
}

int main() {
    int K, maxV = 0 ;
    int W = 0 ;

    scanf("%d", &K);
    for(int i=0, a; i < K; i++) {
        scanf("%d", &a);
        orgReps[a] ++;
        maxV = max(maxV, a);
    }
    if(orgReps[0] != 1) {
        printf("-1\n");
        return 0 ;
    }
    for(W=1; orgReps[W] == 4*W; W++);
    W --;

    for(int R=1; R*R <= K; R++) {
        if(K % R) continue;
        int C = K / R;
        if((R-1) + (C-1) < maxV) continue;
        // maxV = (R - 1 - x) + (C - 1 - y)
        // x = W || y = W
        // y = R + C - 2 - maxV - x
        for(int i = 0, x = W, y = R + C - 2 - maxV - x; i < 2; swap(x, y), i++) {
            if(x < 0 || R <= x || y < 0 || C <= y) continue;
            if(bfs(R, C, x, y)) {
                printf("%d %d\n%d %d\n", R, C, x + 1, y + 1);
                return 0 ;
            }
            if(x == y) continue;
        }
    }
    printf("-1\n");
}
