#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;

struct BIT {
    int N ;
    vector <int> arr;
    BIT(int N) : N(N) {
        arr.resize(N+2);
    }
    void mete(int pos, int val) {
        for(; pos<=N; pos += (pos & -pos))
            arr[pos] += val;
    }
    int saca(int pos) {
        int ans = 0;
        for(; pos; pos -= (pos & -pos))
            ans += arr[pos];
        return ans;
    }
};

BIT *crgs[2];
vector <int> adj[limN];
int W = 0;
int fapr[limN], rng[limN], tip[limN];

void dfs(int pos=1, int ant=-1, int dep=0) {
    rng[pos] = fapr[pos] = ++W;
    tip[pos] = dep;
    for(const int & sig : adj[pos])
        if(sig != ant) {
            dfs(sig, pos, 1-dep);
            rng[pos] = max(rng[pos], rng[sig]);
        }
}

int main() {
    int N, Q;
    int arr[limN];

    scanf("%d%d", &N, &Q);
    crgs[0] = new BIT(N);
    crgs[1] = new BIT(N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &arr[i]);
    }
    for(int i=1; i<N; i++) {
        int a, b ;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();

    while(Q--) {
        int t;
        scanf("%d", &t);
        if(t==1) {
            int x, val, pr;
            scanf("%d%d", &x, &val);
            pr = tip[x];
            crgs[pr]->mete(fapr[x], val);
            crgs[pr]->mete(rng[x]+1, -val);
            crgs[1-pr]->mete(fapr[x], -val);
            crgs[1-pr]->mete(rng[x]+1, val);
        }
        else {
            int x, pr;
            scanf("%d", &x);
            pr = tip[x];
            printf("%d\n", arr[x] + crgs[pr]->saca(fapr[x]));
        }
    }
}
