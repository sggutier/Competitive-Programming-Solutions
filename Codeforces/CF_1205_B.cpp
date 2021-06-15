#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
const int limB = 60;
const int inf = 1<<30;

int N ;
long long nums[limN];
int bitCnt[limN];
vector <int> adj[limN];

int dfs(const int ini) {
    bool dep[limB*3 + 5][limB*3 + 5];
    memset(dep, 0, sizeof(dep));
    queue < pair<int, pair<int, int> > > Q ;
    Q.push({ini, {1, -1}});
    dep[ini][1] = 1;
    while(!Q.empty()) {
        int pos = Q.front().first;
        int d = Q.front().second.first + 1;
        int prev = Q.front().second.second;
        Q.pop();
        for(const int sig : adj[pos]) {
            if(sig == prev)
                continue;
            if(sig == ini) {
                return d - 1 ;
            }
            if(!dep[sig][d]) {
                dep[sig][d] = 1;
                Q.push({sig, {d, pos}});
            }
        }
    }
    return inf;
}

int main() {
    int N2;
    scanf("%d", &N2);
    for(int i=0; i<N2; i++) {
        long long a;
        scanf("%lld", &a);
        if(a == 0)
            continue;
        nums[N++] = a;
        for(int j=0; j<limB; j++) {
            if(((1LL<<j) & a) == 0)
                continue;
            bitCnt[j] ++;
        }
    }

    for(int i=0; i<limB; i++) {
        if(bitCnt[i] >= 3) {
            printf("3\n");
            return 0 ;
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(i != j && (nums[i] & nums[j]))
                adj[i].push_back(j);
        }
    }

    int ans = inf;
    for(int i=0; i<N; i++) {
        ans = min(ans, dfs(i));
        // cout << ans << endl;
    }
    // cout << ans << endl;

    if(ans == inf) {
        ans = -1;
    }

    cout << ans << endl;
}
