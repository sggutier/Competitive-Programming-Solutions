#include <bits/stdc++.h>
using namespace std;

void testCase(int drinkCnt) {
    priority_queue <int> Q;
    vector <int> parentCnt(drinkCnt, 0);
    vector <list<int>> adj(drinkCnt);
    vector <string> drinkNames(drinkCnt);
    map <string, int> dict;
    int edgeCnt;

    for(int i=0; i<drinkCnt; i++) {
        char tmp[500];
        scanf("%s", tmp);
        drinkNames[i] = tmp;
        dict[drinkNames[i]] = i;
    }
    scanf("%d", &edgeCnt) ;
    for(int i=0; i<edgeCnt; i++) {
        char tmpA[500], tmpB[500];
        int a, b;
        scanf("%s%s", tmpA, tmpB);
        a = dict[tmpA], b = dict[tmpB];
        parentCnt[b] ++;
        adj[a].push_back(b);
    }

    for(int i=0; i<drinkCnt; i++) {
        if(!parentCnt[i])
            Q.push(-i);
    }
    while(!Q.empty()) {
        int pos = -Q.top(); Q.pop();
        printf(" %s", drinkNames[pos].c_str());
        for(const int &sig:adj[pos]) {
            if((--parentCnt[sig])==0)
                Q.push(-sig);
        }
    }
    printf(".\n\n");
}

int main() {
    int n, tc=0;

    while(scanf("%d", &n)!=EOF && n) {
        printf("Case #%d: Dilbert should drink beverages in this order:", ++tc);
        testCase(n);
    }
   
    return 0;
}
