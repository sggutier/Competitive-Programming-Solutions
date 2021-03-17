#include <bits/stdc++.h>
using namespace std;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, -1, 0, 1};

int R, C ;
vector <vector<int>> vals ;

inline bool isValid(const int r, const int c) {
    return 0 <= r && r < R && 0 <= c && c < C && vals[r][c] == -1;
}

void bfs(const int R, const int C, const int iniX, const int iniY) {
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
            if(!isValid(a, b)) continue;
            vals[a][b] = vals[x][y] + 1;
            qx.push(a);
            qy.push(b);
        }
    }
    for(int i=0; i < R; i++) {
        for(int j=0; j < C; j++) {
            printf("%2d ", vals[i][j]);
            reps[vals[i][j]] ++;
        }
        printf("\n");
    }
    printf("> ");
    for(int i=0; i < R + C; i++)
        if(reps[i])
            printf("%d ", reps[i]);
    printf("\n");
    printf("---------------\n");
}

int main() {
    R = 7, C = 15;
    for(int iniX = 0; iniX * 2 < R; iniX ++) {
        for(int iniY = 0; iniY * 2 < C; iniY++) {
            bfs(R, C, iniX, iniY);
        }
    }
}
