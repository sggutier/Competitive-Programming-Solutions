#include <bits/stdc++.h>
using namespace std;

int nodeCnt;
vector <list<int>> adj;

void testCase(int start) {
    queue <int> *qCur = new queue<int>(), *qSig = new queue<int>();
    vector <int> minP(nodeCnt, -1);
    int maxBoom = 0;
    int maxBoomDay = 0;
    int d = 1;

    qCur -> push(start);
    minP[start] = 0;
    while(!qCur -> empty()) {
        while(!qCur -> empty()) {
            int pos = qCur -> front(); qCur -> pop();
            for(const int &sig:adj[pos]) 
                if(minP[sig]==-1) {
                    qSig -> push(sig);
                    minP[sig] = minP[pos]+1;
                }
        }
        if((int) qSig -> size() > maxBoom) {
            maxBoom = qSig -> size();
            maxBoomDay = d;
        }
        swap(qCur, qSig);
        d ++ ;
    }

    printf("%d", maxBoom);
    if(maxBoom)
        printf(" %d", maxBoomDay);
    printf("\n");
    
    delete qCur;
    delete qSig;
}

int main() {
    int queryCnt, a;
    
    scanf("%d", &nodeCnt);
    adj = vector<list<int>> (nodeCnt);
    for(int i=0; i<nodeCnt; i++) {
        scanf("%d", &queryCnt);
        while(queryCnt--) {
            scanf("%d", &a);
            adj[i].push_back(a);
        }
    }
    scanf("%d", &queryCnt);
    while(queryCnt--) {
        scanf("%d", &a);
        testCase(a);
    }
    
    return 0;
}
