#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define r first
#define c second
const int LIM_N = 305;
const int LIM_P = LIM_N * LIM_N;
const int INF = 1e8;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, -1, 0, 1};

int R, C;
vector<pii> poss[LIM_P];
vector<int> minP[LIM_P];

void bfs(const int k) {
    vector <int> ords(minP[k].size());
    vector <vector<int>> ps(R, vector<int>(C, -1));
    int T = ords.size(), pos = 0;
    for(int i=0; i < T; i++) {
        ords[i] = i;
    }
    sort(ords.begin(), ords.end(),
         [k](const int a, const int b) {
             return minP[k][a] < minP[k][b];
         });
    queue <pii> _Q, _P ;
    queue <pii> *Q = &_Q, *P = &_P;
    for(int curD = minP[k][ords[0]]; ; curD++, swap(Q, P)) {
        for(; pos < T && minP[k][ords[pos]] == curD; pos++) {
            auto &z = poss[k][ords[pos]];
            if(ps[z.r][z.c] != -1)
                continue;
            ps[z.r][z.c] = curD;
            Q->push(z);
        }
        if(Q->empty()) {
            break;
        }
        while(!Q->empty()) {
            auto pos = Q->front(); Q->pop();
            for(int d=0; d < 4; d++) {
                int x = pos.r + dr[d];
                int y = pos.c + dc[d];
                if(x < 0 || x >= R || y < 0 || y >= C || ps[x][y] != -1)
                    continue;
                ps[x][y] = curD + 1;
                P->push({x,y});
            }
        }
    }
    for(int i=poss[k+1].size()-1; i >= 0; i--) {
        auto &pos = poss[k+1][i];
        minP[k+1][i] = ps[pos.r][pos.c];
    }
}

inline int dst(const pii &a, const pii &b) {
    return abs(a.r - b.r) + abs(a.c - b.c);
}

int main() {
    int P ;
    poss[0].push_back({0, 0});
    minP[0].push_back(0);
    scanf("%d%d%d", &R, &C, &P);
    for(int i=0, a; i < R; i++) {
        for(int j=0; j < C; j++) {
            scanf("%d", &a);
            minP[a].push_back(INF);
            poss[a].push_back({i, j});
        }
    }
    for(int k=0; k < P; k++) {
        if((int) (poss[k].size() * poss[k+1].size()) > R*C) {
            bfs(k);
            continue;
        }
        for(int i=poss[k].size() - 1; i >= 0; i--) {
            for(int j=poss[k+1].size() - 1; j >= 0; j--) {
                minP[k+1][j] = min(minP[k+1][j], dst(poss[k][i], poss[k+1][j]) + minP[k][i]);
            }
        }
    }
    printf("%d\n", minP[P][0]);
}
