#include <bits/stdc++.h>
using namespace std;
const int limN = 105;

int minTimeMemo[limN][limN];
bool usd[limN][limN];

int pointCnt;
int dist[limN], fuel[limN];

int minTime(int pos=0, int ef=0) {
    if(usd[pos][ef]) {
        return minTimeMemo[pos][ef];
    }
    usd[pos][ef] = true;
    if(pos==pointCnt) {
        return minTimeMemo[pos][ef]=0;
    }
    return minTimeMemo[pos][ef] = min(ef>0? dist[pos]/2 + minTime(pos+1, min(pointCnt, ef-1+fuel[pos])) : (1<<30),
                                        dist[pos] + minTime(pos+1, min(pointCnt, ef + fuel[pos])));
}

int testCase() {
    memset(usd, 0, sizeof(usd));
    for(int i=0; i<pointCnt; i++)
        scanf("%d%d", &dist[i], &fuel[i]);
    return minTime();
}

int main() {
    while(scanf("%d", &pointCnt)!=EOF && pointCnt)
        printf("%d\n", testCase());
    
    return 0;
}
