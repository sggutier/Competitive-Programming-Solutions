#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int N ;
int val[limN];
int sigP[limN][2];
vector <int> poss[2];

int getEss(int t) {
    int acum[] = {0, 0};
    int pos = 0;
    int lw = -1;
    while(pos < N) {
        int ps[2] = {sigP[pos][0], sigP[pos][1]};
        int sp = N;
        for(int i=0; i<2; i++) {
            if(ps[i] + t-1 >= (int) poss[i].size()) continue;
            sp = min(sp, poss[i][ ps[i] + t-1 ]);
        }
        if(sp==N)
            return -1;
        lw = val[sp];
        acum[val[sp]]++;
        pos = sp+1;
    }
    return acum[lw]<=acum[1-lw]? -1 : acum[lw];
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &val[i]);
        val[i]--;
        poss[val[i]].push_back(i);
    }
    int up[] = {(int) poss[0].size(), (int) poss[1].size()};
    for(int i=N-1; i>=0; i--) {
        up[val[i]]--;
        for(int j=0; j<2; j++)
            sigP[i][j] = up[j];
    }
    vector < pair<int, int> > ans;
    for(int t=1; t<=N; t++) {
        int s = getEss(t);
        if(s != -1)
            ans.push_back({s, t});
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", (int) ans.size());
    for(auto &p : ans)
        printf("%d %d\n", p.first, p.second);
}
