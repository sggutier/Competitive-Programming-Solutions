/*
ID: me60
LANG: C++11
TASK: ariprog
*/
#include <bits/stdc++.h>
using namespace std;
const int limN = 251*251*2;

int maxCnt = 0;

void markBisq(int a, int b, bool* isBisq, int* bisq) {
    int cnt = 1;
    for(; a>=0; a-=b) {
        if(!isBisq[a])
            break;
        bisq[a] = cnt++;
    }
    maxCnt = max(maxCnt, cnt);
}

int main() {
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);
    
    int seqLen;
    int biLim;
    bool isBisq[limN];
    int bisqCnt[limN];
    vector<int> bisq;
    set <pair<int,int>> ans;

    scanf("%d%d", &seqLen, &biLim) ;

    memset(isBisq, 0, sizeof(isBisq));
    for(int i=0; i<=biLim; i++) {
        for(int j=i; j<=biLim; j++) {
            isBisq[i*i + j*j] = true;
        }
    }
    for(int i=0; i<limN; i++)
        if(isBisq[i])
            bisq.push_back(i);

    for(int b=1, iterLim=(2*biLim*biLim)/(seqLen-1); b<=iterLim; b++) {
        memset(bisqCnt, 0, sizeof(bisqCnt));
        for(int i=bisq.size()-1; i>=0; i--) {
            if(!bisqCnt[bisq[i]])
                markBisq(bisq[i], b, isBisq, bisqCnt);
            if(bisqCnt[bisq[i]] >= seqLen)
                ans.insert(make_pair(b, bisq[i]));
        }
    }

    for(auto& a: ans)
        printf("%d %d\n", a.second, a.first);
    if(ans.size()==0)
        printf("NONE\n");
 
    return 0;
}
