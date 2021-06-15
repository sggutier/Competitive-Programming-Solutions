#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define f first
#define s second
typedef long long ll;
const int limN = 1e5 + 5;

set <int> chld[limN];
vector <int> adj[limN];
int lev[limN];

int main() {
    queue <int> Q ;
    int N, K ;

    scanf("%d%d", &N, &K);
    for(int i=1, a, b; i<N; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1; i<=N; i++)
        if((int) adj[i].size() == 1) {
            Q.push(i);
            lev[i] = 1;
        }

    while(!Q.empty()) {
        int pos = Q.front();
        Q.pop();
        int parCnt = 0;
        for(const int sig : adj[pos]) {
            if(chld[pos].count(sig)) continue;
            if(lev[sig] == 0) {
                lev[sig] = lev[pos] + 1;
                Q.push(sig);
            }
            if(lev[sig] != lev[pos] + 1) {
                printf("No\n");
                return 0 ;
            }
            chld[sig].insert(pos);
            parCnt ++;
        }
        if(parCnt > 1) {
            printf("No\n");
            return 0 ;
        }
    }

    bool fca = true;
    bool fd = false;
    for(int i=1; i<=N; i++) {
        if(lev[i]-1 > K || lev[i] == 0 || (lev[i] != 1 && (int) chld[i].size() <= 2)) {
            fca = false;
        }
        fd |= lev[i]-1 == K;
    }

    printf("%s\n", fca && fd? "Yes" : "No");
}
