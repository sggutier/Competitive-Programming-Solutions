#include <bits/stdc++.h>
using namespace std;
const int limN = 5005;

int cnt[limN];
vector <int> adj[limN];
stack <int> S;
bool actv[limN];
int W = 0;
int iddfs[limN], minDep[limN], rt[limN];

void tarjan(const int pos) {
    if(iddfs[pos]) return;
    S.push(pos);
    actv[pos] = true;
    minDep[pos] = iddfs[pos] = ++W;
    for(const int &sig : adj[pos]) {
        tarjan(sig);
        if(actv[sig])
            minDep[pos] = min(minDep[pos], minDep[sig]);
        else
            cnt[rt[sig]]++;
    }
    if(minDep[pos] != iddfs[pos])
        return;
    int sig;
    // printf("Group with %d as leader:\n\t", pos);
    do {
        sig = S.top(); S.pop();
        rt[sig] = pos;
        // printf("%d ", sig);
        actv[sig] = false;
    } while(sig != pos);
    // printf("\n");
}


int main() {
    int ans = 0;
    int N, E, S;

    scanf("%d%d%d", &N, &E, &S);
    for(int i=0, a, b; i<E; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
    }

    for(int i=1; i<=N; i++)
        tarjan(i);

    for(int i=1; i<=N; i++)
        if(rt[i] != rt[S] && rt[i]==i && !cnt[i])
            ans ++;

    printf("%d\n", ans);
}
