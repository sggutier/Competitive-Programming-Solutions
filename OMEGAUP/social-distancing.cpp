#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 1005;
const int D = 2;
const int D2 = D*D;
typedef pair<int,int> pii;
#define x first
#define y second

int C, W, H;

bool touchesL(const pii &pos) {
    return pos.x <= D;
}

bool touchesR(const pii &pos) {
    return W - pos.x <= D;
}

bool touch(const pii &a, const pii &b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return dx*dx + dy*dy <= D2*4;
}

bool dfs(const int pos, const vector <int> *adj, bool *usd) {
    if(pos == C+1) {
        return true;
    }
    if(usd[pos]) {
        return false;
    }
    usd[pos] = true;
    for(const int sig : adj[pos]) {
        if(dfs(sig, adj, usd)) {
            return true;
        }
    }
    return false;
}

inline void connectG(vector <int> *adj, const int a, const int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
}

bool testCase() {
    vector <int> adj[LIM_N];
    bool usd[LIM_N];
    pii ppl[LIM_N];
    scanf("%d%d%d", &C, &W, &H);
    for(int i=0; i < C; i++) {
        usd[i] = 0;
        scanf("%d%d", &ppl[i].x, &ppl[i].y);
        if(touchesL(ppl[i])) {
            connectG(adj, i, C);
        }
        if(touchesR(ppl[i])) {
            connectG(adj, i, C+1);
        }
        for(int j=0; j < i; j++) {
            if(touch(ppl[i], ppl[j])) {
                connectG(adj, i, j);
            }
        }
    }
    usd[C] = usd[C+1] = false;
    return !dfs(C, adj, usd);
}

int main() {
    int T;
    scanf("%d", &T);
    for(int i=0; i < T; i++) {
        printf(testCase()? "SAFE\n" : "RISKY\n");
    }
}
