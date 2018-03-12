#include <bits/stdc++.h>
using namespace std;
const int limN = 405;

bool act[limN];
vector <int> adj[limN];
int dfsLow[limN], dfsNum[limN];
int tarCnt = 0;
stack <int> S;
int color[limN];
int grupSiz[limN];

void tarjan(int pos) {
    if(dfsNum[pos])
        return;
    act[pos] = true;
    dfsNum[pos] = ++tarCnt;
    dfsLow[pos] = dfsNum[pos];
    S.push(pos);
    for(const int &sig:adj[pos]) {
        tarjan(sig);
        if(act[sig])
            dfsLow[pos] = min(dfsLow[pos], dfsLow[sig]);
    }
    if(dfsLow[pos]!=dfsNum[pos])
        return;
    int ult,  cnt=0;
    do {
        ult = S.top(); S.pop();
        color[ult] = pos;
        act[ult] = false;
        cnt++;
    } while(ult!=pos);
    grupSiz[pos] = cnt;
}

int main() {
    int R, C;
    int tot ;
    char mapa[limN][limN];

    scanf("%d%d", &R, &C);
    for(int i=0; i<R; i++)
        scanf("%s", mapa[i]);

    tot = R+C;

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(mapa[i][j]=='B') {
                adj[i].push_back(j+R);
                adj[j+R].push_back(i);
                adj[i+tot].push_back(j+R+tot);
                adj[j+R+tot].push_back(i+tot);
            }
            else {
                adj[i].push_back(j+R+tot);
                adj[j+R+tot].push_back(i);
                adj[i+tot].push_back(j+R);
                adj[j+R].push_back(i+tot);
            }
        }
    }

    for(int i=0; i<2*tot; i++) {
        printf("%d => ", i);
        for(const int &sig:adj[i])
            printf("%d ", sig);
        printf("\n");
    }

    int sumo = 0;

    for(int i=2*tot-1; i>=0; i--) {
        tarjan(i);
    }
    for(int i=0; i<tot; i++) {
        if(color[i]==color[i+tot]) {
            printf("No\n");
            return 0;
        }
        if(color[i]==i)
            sumo += grupSiz[i];
    }

    printf("%d\n", sumo);
}
