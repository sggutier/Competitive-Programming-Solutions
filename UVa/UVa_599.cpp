#include <bits/stdc++.h>
using namespace std;
const int limN = 300;

list <int> adj[limN];
bool usd[limN];

void dfs(int pos) {
    usd[pos] = true;
    for(const int &sig:adj[pos])
        if(!usd[sig])
            dfs(sig);
}

void testCase() {
    memset(usd, 0, sizeof(usd));
    for(int i=0; i<limN; i++)
        adj[i].clear();
    int ac=0, tr=0;
    char str[limN];

    while(scanf("%s", str)!=EOF && str[0]!='*') {
        adj[(int) str[1]].push_back(str[3]);
        adj[(int) str[3]].push_back(str[1]);
    }
    scanf("%s", str);
    for(int i=0; str[i]; i++) {
        if(str[i]==',')
            continue;
        int k = str[i];
        if(adj[k].size()==0)
            ac ++;
        else if(!usd[k]) {
            tr ++;
            dfs(k);
        }
    }

    printf("There are %d tree(s) and %d acorn(s).\n", tr, ac);
}

int main() {
    int tc;

    scanf("%d", &tc);
    while(tc--)
        testCase();
    
    return 0;
}
