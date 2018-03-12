#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;

int lampCnt;
list <int> adj[2*limN];
bool active[2*limN];
int dfs_low[2*limN], dfs_num[2*limN];
int dfsCnt = 1;
stack <int> comp;

void tarjan(int pos) {
    dfs_low[pos] = dfs_num[pos] = dfsCnt++;
    active[pos] = true;
    comp.push(pos);
    for(const int &sig: adj[pos]) {
        if(!dfs_low[sig])
            tarjan(sig);
        if(active[sig])
            dfs_low[pos] = min(dfs_low[pos], dfs_low[sig]);
    }
    if(dfs_low[pos] == dfs_num[pos]) {
        int nod;
        // printf("%d --> ", pos);
        do {
            nod = comp.top();
            // printf("%d ", nod);
            comp.pop();
            active[nod] = false;
        } while(nod!=pos);
        // printf("\n");
    }
}

inline bool inRange(const int &a, const int &b, const int &r) {
    return abs(a-b)<=2*r;
}

void lee() {
    int r, l;
    scanf("%d%d%d", &l, &r, &lampCnt);
    int lamps[lampCnt][2];

    for(int i=0; i<lampCnt; i++) {
        for(int j=0; j<2; j++)
            scanf("%d", &lamps[i][j]);
    }
    for(int i=0; i<lampCnt; i++) {
        for(int j=0; j<lampCnt; j++) {
            if(i==j)
                continue;
            for(int k=0; k<2; k++) {
                if(lamps[i][1-k]==lamps[j][1-k] && inRange(lamps[i][k], lamps[j][k], r)) {
                    adj[2*i + k].push_back(2*j+(k+1)%2);
                    adj[2*j + k].push_back(2*i+(k+1)%2);
                    // printf("%d => %d\n", 2*i + k, (2*j+(k+1)%2));
                    // printf("%d => %d\n", 2*j + k, (2*i+(k+1)%2));
                }
            }
        }
    }
}

bool resolvible() {
    for(int i=2*lampCnt-1; i>=0; i--) {
        if(!dfs_num[i])
            tarjan(i);
        if(dfs_low[i]==dfs_low[i + (i%2==0? 1 : -1)])
            return false;
    }
    return true;
}

int main() {
    lee();

    printf("%s\n", resolvible()? "YES" : "NO");
    
    return 0;
}
