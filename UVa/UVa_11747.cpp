#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>

void testCase(int nodCnt, int edgCnt) {
    vector<list<par>> adj(nodCnt);
    vector <bool> usdNod(nodCnt, false);
    int usdNodCnt = -1;
    set <int> ans;    

    for(int i=0; i<edgCnt; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back(par(-c, b));
        adj[b].push_back(par(-c, a));
    }

    priority_queue <par> Q;
    for(int i=0; i<nodCnt; i++) {
        if(usdNod[i])
            continue ;
        Q.push(par(0, i));
        while(!Q.empty()) {
            int pos = Q.top().second, k = Q.top().first;
            Q.pop();
            if(usdNod[pos]) {
                ans.insert(-k);
                continue ;
            }
            usdNod[pos] = true;
            usdNodCnt ++;
            for(const auto &e:adj[pos]) {
                if(!usdNod[e.second])
                    Q.push(e);
            }
        }
    }
    if((int) ans.size() == 0) {
        printf("forest\n");
        return;
    }
    bool prev = false;
    for(const int &a:ans) {
        if(prev) 
            printf(" " );
        prev = true;
        printf("%d", a);
    }
    printf("\n");
}

int main() {
    int a, b;

    while(scanf("%d%d", &a, &b)!=EOF && (a || b))
        testCase(a, b);
    
    return 0;
}
