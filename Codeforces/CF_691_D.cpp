#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;

bitset <limN> usd;
int nums[limN];
int poss[limN], vals[limN];
vector <int> adj[limN];
queue <int> Q;

int main() {
    int N, E ;

    scanf("%d%d", &N, &E);
    for(int i=0; i<N; i++)
        scanf("%d", &nums[i]);
    while(E--) {
        int a, b ;
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=0; i<N; i++) {
        if(usd[i]) continue;
        int W = 0;
        usd[i] = true;
        Q.push(i);
        while(!Q.empty()) {
            int pos = Q.front(); Q.pop();
            poss[W] = pos, vals[W] = nums[pos];
            W ++;
            for(const int &sig:adj[pos]) {
                if(usd[sig]) continue;
                usd[sig] = true;
                Q.push(sig);
            }
        }
        sort(poss, poss+W);
        sort(vals, vals+W);
        for(int i=0; i<W; i++) {
            nums[poss[i]] = vals[W-1-i];
            // printf("%d %d\n", poss[i], vals[i]);
        }
    }

    for(int i=0; i<N; i++)
        printf("%d ", nums[i]);
    printf("\n");
}
