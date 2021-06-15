#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
const int limN = 1e5 + 5;
const int mod = 1e9 + 7;
typedef pair<int,int> par;

bool usdPt[limN];
int pots2[limN];
vector <int> adj[limN];
int N ;
par pts[limN];
int idx[limN];
set <int> usdX, usdY;

bool hasCycle(int pos, int prev) {
    if(usdPt[pos])
        return true;
    usdPt[pos] = true;
    bool ans = false;
    usdX.insert(pts[pos].x);
    usdY.insert(pts[pos].y);
    for(const int &sig:adj[pos])
        if(sig!=pos && sig!=prev)
            ans |= hasCycle(sig, pos);
    return ans;
}

int main() {
    long long ans = 1;
    
    pots2[0] = 1;
    for(int i=1; i<limN; i++)
        pots2[i] = (pots2[i-1]*2)%mod;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d%d", &pts[i].x, &pts[i].y);
        idx[i] = i;
    }
    
    sort(idx, idx+N,
         [](int a, int b) {
             return pts[a] < pts[b];
         });
    for(int i=0; i+1<N; i++) {
        if(pts[idx[i]].x == pts[idx[i+1]].x) {
            adj[idx[i]].push_back(idx[i+1]);
            adj[idx[i+1]].push_back(idx[i]);
        }
    }
    sort(idx, idx+N,
         [](int a, int b) {
             return pts[a].y==pts[b].y? pts[a].x < pts[b].x : pts[a].y < pts[b].y;
         });
    for(int i=0; i+1<N; i++) {
        if(pts[idx[i]].y == pts[idx[i+1]].y) {
            adj[idx[i]].push_back(idx[i+1]);
            adj[idx[i+1]].push_back(idx[i]);
        }
    }

    for(int i=0; i<N; i++) {
        if(usdPt[i])
            continue;        
        int linCnt = usdX.size() + usdY.size();
        int d = hasCycle(i, -1)? 0 : 1;
        linCnt = usdX.size() + usdY.size() - linCnt;
        //printf("%d %d\n", linCnt, d);
        ans = (ans * (pots2[linCnt] + mod-d)%mod)%mod;
    }

    printf("%d\n", (int) ans);
}
