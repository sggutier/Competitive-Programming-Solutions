#include <bits/stdc++.h>
using namespace std;
const int limN = 1e4;

int minP[limN];
int numCnt;
int nums[limN];

void bfs(int pos) {
    queue <int> Q;
    minP[pos] = 1;
    Q.push(pos);
    while(!Q.empty()) {
        pos = Q.front(); Q.pop();
        for(int i=0; i<numCnt; i++) {
            int sig = (pos+nums[i])%limN;
            if(!minP[sig]) {
                minP[sig] = minP[pos]+1;
                Q.push(sig);
            }
        }
    }
}

void testCase(int ini, int fin) {
    for(int i=0; i<numCnt; i++)
        scanf("%d", &nums[i]);

    memset(minP, 0, sizeof(minP));
    bfs(ini);
    if(minP[fin])
        printf("%d\n", minP[fin]-1);
    else
        printf("Permanently Locked\n");
}

int main() {
    int a, b;
    int tc = 0;

    while(scanf("%d%d%d", &a, &b, &numCnt)!=EOF && (a || b || numCnt)) {
        printf("Case %d: ", ++tc);
        testCase(a,b);
    }
}
