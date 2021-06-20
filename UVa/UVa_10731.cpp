#include <bits/stdc++.h>
using namespace std;
const int limN = 300;

bool inQuiz[limN];
bool active[limN];
set <int> groups[limN];
int dfs_num[limN], dfs_low[limN];
int cnt = 0;
list <int> adj[limN];
stack <int> S;

void tarjanSCC(int pos) {
    active[pos] = true;
    dfs_low[pos] = dfs_num[pos] = ++cnt;
    S.push(pos);
    for(const int &sig:adj[pos]) {
        if(!dfs_num[sig])
            tarjanSCC(sig);
        if(active[sig])
            dfs_low[pos] = min(dfs_low[pos], dfs_low[sig]);
    }
    if(dfs_low[pos]!=dfs_num[pos])
        return;
    int k, minK = limN;
    list <int> g;
    do {
        k = S.top(); S.pop();
        g.push_back(k);
        minK = min(minK, k);
        active[k] = false;        
    } while(k!=pos) ;
    
    for(const int &a:g)
        groups[minK].insert(a);
}

void testCase(int ansCnt) {
    memset(inQuiz, 0, sizeof(inQuiz));
    cnt = 0;
    memset(dfs_num, 0, sizeof(dfs_num));
    for(int i=0; i<limN; i++) {
        groups[i].clear();
        adj[i].clear();
    }

    while(ansCnt--) {
        char lets[5], d;
        char tmp[5];
        for(int i=0; i<5; i++) {
            scanf("%s", tmp);
            lets[i] = tmp[0];
            inQuiz[(int) lets[i]] = true;
        }
        scanf("%s", tmp);
        d = tmp[0];
        inQuiz[(int) d] = true;
        for(int i=0; i<5; i++)
            adj[(int) d].push_back(lets[i]);
    }

    for(int i=0; i<300; i++)
        if(inQuiz[i] && !dfs_num[i])
            tarjanSCC(i);

    for(int i=0; i<300; i++) {
        if(groups[i].size()==0)
            continue;
        bool fst = false;
        for(const int &a:groups[i]) {
            if(fst)
                printf(" ");
            printf("%c", a);
            fst = true;
        }
        printf("\n");
    }
}

int main() {
    int n, tc=0;

    while(scanf("%d", &n)!=EOF && n) {
        if(tc++)
            printf("\n");
        testCase(n);
    }
    
    return 0;
}
