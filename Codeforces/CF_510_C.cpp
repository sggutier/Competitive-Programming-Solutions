#include <bits/stdc++.h>
using namespace std;

int crg[305];

int main() {
    int N ;
    string wds[105];
    vector <int> adj[305];
    queue <int> Q;
    char ans[30];
    char *s = ans;

    cin >> N ;
    for(int i=0; i<N; i++)
        cin >> wds[i];
    for(int i=1; i<N; i++) {
        int l = min(wds[i].size(), wds[i-1].size());
        bool any = false;
        for(int j=0; j<l; j++) {
            if(wds[i-1][j] == wds[i][j])
                continue;
            adj[(int) wds[i-1][j]].push_back(wds[i][j]);
            crg[(int) wds[i][j]]++;
            any = true;
            break;
        }
        if(!any && wds[i].size() < wds[i-1].size()) {
            printf("Impossible\n");
            return 0;
        }
    }

    for(int i='a'; i<='z'; i++) {
        if(crg[i]==0)
            Q.push(i);
    }
    while(!Q.empty()) {
        int p = Q.front(); Q.pop();
        *(s++) = p;
        for(const int &sig:adj[p]) {
            if((--crg[sig]) == 0)
                Q.push(sig);
        }
    }
    *s = 0;

    for(int i='a'; i<='z'; i++) {
        if(crg[i]) {
            printf("Impossible\n");
            return 0;
        }
    }

    printf("%s\n", ans);
}
