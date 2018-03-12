#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
#define f first
#define s second
#define tri pair<int, par>
const int inf = (1<<30);

bool mejora(vector <tri> &edges, vector <int> &minP) {
    bool ans = false;
    for(const auto &e: edges) {
        if(minP[e.s.f] + e.f < minP[e.s.s]) {
            ans = true ;
            minP[e.s.s] = minP[e.s.f] + e.f;
        }
    }
    return ans;
}

void testCase() {
    int nodeCnt, edgeCnt;
        
    scanf("%d%d", &nodeCnt, &edgeCnt);
    vector <int> minP(nodeCnt, inf);
    vector <tri> edges(edgeCnt);

    for(auto &e: edges)
        scanf("%d%d%d", &e.s.f, &e.s.s, &e.f);

    minP[0] = 0;
    for(int i=1; i<nodeCnt; i++)
        mejora(edges, minP);

    printf("%spossible\n", mejora(edges, minP)? "" : "not ");
}

int main() {
    int tc;

    for(scanf("%d", &tc); tc; tc--)
        testCase();
    
    return 0;
}
