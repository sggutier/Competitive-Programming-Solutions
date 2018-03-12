#include <bits/stdc++.h>
using namespace std;
const int limN = 3e5 + 5 ;
const int inf = 1e9 + 5;

int nodeN; 
int str[limN];
list <int> adj[limN];

int maxStr(int pos, int depth, int lst) {
    int ans = str[pos] + min(depth, 2);
    for(int &nov: adj[pos])
        if(nov!=lst)
            ans = max(ans, maxStr(nov, depth+1, pos));
    return ans;
}

pair<pair <int,int>, int> calcPower(int pos, int maxS = -inf) {
    if(maxS==-inf)
        maxS = str[pos];
    int cnt = 0;
    for(int &nov: adj[pos])
        if(str[nov]==maxS)
            cnt ++;
    return make_pair(make_pair(maxS, cnt), pos);
}

int main() {
    pair < pair<int, int>, int> stPos ;
    pair < pair<int, int>, int> stPos2 ;
    scanf("%d", &nodeN);
    for(int i=0; i<nodeN; i++)
        scanf("%d", &str[i]);
    for(int i=1; i<nodeN; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    stPos = calcPower(0);
    for(int i=1; i<nodeN; i++)
        stPos = max(stPos, calcPower(i));
    stPos2 = calcPower(0, stPos.first.first);
    for(int i=1; i<nodeN; i++)
        stPos2 = max(stPos2, calcPower(i, stPos.first.first));

    printf("%d\n", min(maxStr(stPos.second, 0, -1),
                       maxStr(stPos2.second, 0, -1)));

    return 0;
}
