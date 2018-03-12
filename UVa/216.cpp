#include <bits/stdc++.h>
using namespace std;
#define par pair<int, int>
#define x first
#define y second

double dist(par A, par B) {
    return hypot(A.x - B.x, A.y - B.y) + 16.0;
}

void testCase(int nodeCnt) {
    vector <par> nodes(nodeCnt);
    pair<double, vector<par>> ans = make_pair(1e40, vector<par>(0));
    for(auto &n: nodes)
        scanf("%d%d", &n.x, &n.y);
    sort(nodes.begin(), nodes.end());
    do {
        double dst = 0.0;
        for(int i=1; i<nodeCnt; i++)
            dst += dist(nodes[i], nodes[i-1]);
        ans = min(ans, make_pair(dst, nodes));
    } while(next_permutation(nodes.begin(), nodes.end()));

    // for(int i=ans.second; i; i--, next_permutation(nodes.begin(), nodes.end()));
    
    for(int i=1; i<nodeCnt; i++) {
        printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", ans.second[i-1].x, ans.second[i-1].y, ans.second[i].x, ans.second[i].y, dist(ans.second[i-1], ans.second[i]));
    }
    printf("Number of feet of cable required is %.2lf.\n", ans.first);
}

int main() {
    int tc = 0, n;

    while(scanf("%d", &n) != EOF && n!=0) {
        printf("**********************************************************\n");
        printf("Network #%d\n", ++tc);
        testCase(n);
    }
    
    return 0;
}
