#include <bits/stdc++.h>
using namespace std;
const int inf = (1<<30);

vector<list <int>> adj;
vector <string> names;
vector <int> dfs_low, dfs_num;
vector <bool> active;
stack <int> S;
int dfsCnt ;

void tarjanSCC(const int pos) {
    if(dfs_num[pos] != inf)
        return;
    active[pos] = true ;
    dfs_low[pos] = dfs_num[pos] = dfsCnt++;
    S.push(pos);
    for(const int &sig: adj[pos]) {
        tarjanSCC(sig);
        if(active[sig])
            dfs_low[pos] = min(dfs_low[pos], dfs_low[sig]);
    }

    if(dfs_low[pos] == dfs_num[pos]) {
        bool fst = true ;
        int sig ;
        do {
            sig = S.top(); S.pop();
            active[sig] = false;
            if(!fst)
                printf(", ");
            fst = false;
            printf("%s", names[sig].c_str());
        } while(sig!=pos);
        printf("\n");
    }
}

void testCase(int nodeCnt, int edgeCnt) {
    adj = vector<list <int>> (nodeCnt);
    names = vector <string>(nodeCnt);
    dfs_num = dfs_low = vector <int>(nodeCnt, inf);
    active = vector <bool>(nodeCnt, false);
    dfsCnt = 0;
    map <string, int> dict;

    nodeCnt = 0;
    for(int i=0; i<edgeCnt; i++) {
        char A[500], B[500];
        int idA, idB;

        scanf("%s%s", A, B);
        
        if(dict.count(A)==0) {
            idA = dict[A] = nodeCnt++;
            names[idA] = A;
        }
        else
            idA = dict[A];
        if(dict.count(B)==0) {
            idB = dict[B] = nodeCnt++;
            names[idB] = B;
        }
        else
            idB = dict[B];

        adj[idA].push_back(idB);
    }

    for(int i=0; i<nodeCnt; i++) {
        tarjanSCC(i);
    }
}

int main() {
    int tc = 1;
    int a, b;

    while(scanf("%d%d", &a, &b)!=EOF && a!=0 && b!=0) {
        if(tc>1)
            printf("\n");
        printf("Calling circles for data set %d:\n", tc++);
        testCase(a, b);
    }
    
    return 0;
}
