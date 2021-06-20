#include <bits/stdc++.h>
using namespace std;
#define par pair<int, int>
#define f first
#define s second
const int limN = 5e4 + 5 ;

int calcChildren(vector <int> &adj, vector<int> &childNum, vector<int> &depth, int pos, int d) {
    if(childNum[pos])
        return childNum[pos];
    if(depth[pos]) {
        // cout << pos << " " << d << " " << depth[pos] << " " << depth[pos]-d << endl;
        d = depth[pos] - d ;
        depth[pos] = 0;
        return d ;
    }
    depth[pos] = d;
    int k = calcChildren(adj, childNum, depth, adj[pos], d+1);
    // printf("%d -> %d --> %d\n", pos+1, k, depth[pos]);
    if(depth[pos]==0) {
        k *= -1 ;
        depth[pos] = d;
        k -- ;
    }
    if(k<0) {
        childNum[pos] = -k;
        return k;
    }
    else
        return childNum[pos] = k+1;
}

void testCase() {
    int nodeCnt ;
    vector <int> childNum, depth ;
    vector <int> adj;
    par maxChild = par(0, 0);

    scanf("%d", &nodeCnt);
    childNum = vector <int>(nodeCnt);
    depth = vector<int>(nodeCnt);
    adj = vector<int>(nodeCnt);
    for(int i=0; i<nodeCnt; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a-1] = b-1;
    }

    for(int i=0; i<nodeCnt; i++) {
        maxChild = max(maxChild, par(calcChildren(adj, childNum, depth, i, 1), -i));
    }

    printf("%d\n", -maxChild.s+1);
}

int main() {
    int tc;

    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("Case %d: ", i);
        testCase();
    }
    
    return 0 ;
}
