#include <bits/stdc++.h>
using namespace std;
const int limN = (1<<16) + 5;

int main() {
    int N;
    queue <int> Q;
    int deg[limN], xo[limN];
    vector <pair<int,int>> ans;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d%d", &deg[i], &xo[i]);
        if(deg[i]==1)
            Q.push(i);
    }

    while(!Q.empty()) {
        int p = Q.front(); Q.pop();
        if(deg[p]==0)
            continue;
        ans.push_back(make_pair(p, xo[p]));
        deg[xo[p]] --;
        xo[xo[p]] ^= p;
        if(deg[xo[p]]==1)
            Q.push(xo[p]);            
    }

    printf("%d\n", (int) ans.size());
    for(const auto &p:ans)
        printf("%d %d\n", p.first, p.second);
}
