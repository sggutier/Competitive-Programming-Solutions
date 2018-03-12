#include <bits/stdc++.h>
using namespace std;
const int limN = 2e4 + 5;
#define par pair<int,int>
#define f first
#define s second

class SegmTree {
private:
    int n;
    vector <par> vals;
    par _get(int l, int r) {
        par ans = par(limN, limN);
        l += n;
        r += n;
        for(; l<r; l>>=1, r>>=1) {
            if(l&1)
                ans = min(ans, vals[l++]);
            if(r&1)
                ans = min(ans, vals[--r]);
        }
        return ans;
    }
public:
    SegmTree(int K, int *arr, int *brr) {
        n = K;
        vals.resize(2*n);
        for(int i=0; i<n; i++)
            vals[i+n] = par(arr[i], brr[i]);
        for(int i=n-1; i; i--) {
            vals[i] = min(vals[(i<<1)], vals[(i<<1) | 1]);
        }
    }
    int get(int l, int r) {
        return _get(l, r+1).second;
    }
};

int N;
int L[2*limN], E[2*limN], H[limN], helCnt;
list <int> adj[limN];
int padr[limN];

void dfs(int prev=-1, int pos=0, int depth=0) {
    padr[pos] = prev;
    H[pos] = helCnt;
    E[helCnt] = pos;
    L[helCnt++] = depth;
    for(const int &sig:adj[pos]) {
        if(sig==prev)
            continue;
        dfs(pos, sig, depth+1);
        E[helCnt] = pos;
        L[helCnt++] = depth;
    }
}

void buildRMQ() {
    helCnt = 0;
    memset(H, -1, sizeof H);
    dfs();
}

void calcQuery(SegmTree &st, int a, int b) {
    int aPos = H[a], bPos = H[b];
    if(aPos > bPos) {
        swap(aPos, bPos);
        swap(a, b);
    }
    int c = st.get(aPos, bPos);
    int cPos = H[c];
    int aDep = L[aPos], bDep = L[bPos], cDep = L[cPos];
    int av ;
    bDep -= cDep;
    aDep -= cDep;
    av = (aDep + bDep)/2;
    int pos = (aDep > bDep? a : b);
    while(av--) {
        pos = padr[pos];
    }
    if((aDep + bDep)%2) {
        a = pos, b= padr[pos];
        if(a>b)
            swap(a, b);
        printf("The fleas jump forever between %d and %d.\n", a+1, b+1);
    }
    else
        printf("The fleas meet at %d.\n", pos+1);
}

void testCase() {
    for(int i=0; i<N; i++)
        adj[i].clear();
    for(int i=1; i<N; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    buildRMQ();
    SegmTree st(helCnt, L, E);
    int Q, a, b;
    scanf("%d", &Q);
    while(Q--) {
        scanf("%d%d", &a, &b);
        calcQuery(st, a-1, b-1);
    }
}

int main() {
    while(scanf("%d", &N)!=EOF && N)
        testCase();
}
