#include <bits/stdc++.h>
using namespace std;
const int limN = 55;
const int limB = 12;
#define par pair<int,int>
#define f first
#define s second
#define tri pair<int,par>
#define mp make_pair

int nodCnt, storCnt;
int minP[limN][1<<limB];
int storNum[limN];
int prices[limB];
list <par> adj[limN];

void dijkstra() {
    priority_queue <tri> Q;
    minP[0][0] = 1;
    Q.push(tri(-1, par(0, 0)));
    while(!Q.empty()) {
        int pos = Q.top().s.f, msk = Q.top().s.s, dst = -Q.top().f; Q.pop();
        if(minP[pos][msk] > dst)
            continue;
        for(const auto &edg:adj[pos]) {
            int msk2 = msk | (storNum[edg.s]? (1<<(storNum[edg.s]-1)) : 0), sig = edg.s ;
            if(!minP[sig][msk2] || minP[sig][msk2] > dst + edg.f) {
                minP[sig][msk2] = dst + edg.f ;
                Q.push(mp(-minP[sig][msk2], mp(sig, msk2)));
            }
        }
    }
}

int calcMinPrice(int pos=0, int msk=0, int sum=0) {
    if(pos==storCnt) {
        if(minP[0][msk]) {
            // printf("%d ", pos);
            // for(int i=0; i<storCnt; i++)
            //     printf("%d", ((1<<i) & msk)!=0);
            // printf(" => %d (%d) [%d]\n", sum, minP[0][msk], sum - (minP[0][msk]-1));
            return max(0, sum - (minP[0][msk]-1));
        }
        return 0;
    }
    return max(calcMinPrice(pos+1, msk, sum),
               calcMinPrice(pos+1, msk | (1<<pos), sum + prices[pos]));
}

void testCase() {
    memset(minP, 0, sizeof(minP));
    memset(storNum, 0, sizeof(storNum));
    int edgCnt ;
    scanf("%d%d", &nodCnt, &edgCnt);
    for(int i=0; i<=nodCnt; i++) adj[i].clear();
    for(int i=0; i<edgCnt; i++) {
        int a, b, c, d;
        scanf("%d %d %d.%d", &a, &b, &c, &d);
        c = c*100 + d;
        adj[a].push_back(par(c, b));
        adj[b].push_back(par(c, a));
    }
    scanf("%d", &storCnt);
    for(int i=0; i<storCnt; i++) {
        int a, b, c ;
        scanf("%d %d.%d", &a, &b, &c);
        prices[i] = b*100 + c;
        storNum[a] = i+1;
    }
    dijkstra();
    int ans = calcMinPrice();
    if(ans!=0)
        printf("Daniel can save $%d.%02d\n", ans/100, ans%100);
    else
        printf("Don't leave the house\n");
}

int main() {
    int tc;

    scanf("%d", &tc);
    while(tc--) {
        testCase();
    }
    
    return 0;
}
