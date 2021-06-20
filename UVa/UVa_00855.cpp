#include <bits/stdc++.h>
using namespace std;

pair<int,int> calcaA(int N, vector <int> &crg) {
    vector <int> crgL(N, 0), crgR(N, 0);
    vector <int> dstL(N, 0), dstR(N, 0);
    pair <int,int> ans(1e9, 0);
    for(int i=1; i<N; i++) {
        crgL[i] = crgL[i-1] + crg[i-1];
        dstL[i] = dstL[i-1] + crgL[i];
    }
    for(int i=N-2; i>=0; i--) {
        crgR[i] = crgR[i+1] + crg[i+1];
        dstR[i] = dstR[i+1] + crgR[i];
    }

    for(int i=0; i<N; i++)
        ans = min(ans, {dstL[i] + dstR[i], i});

    return ans;
}

void testCase() {
    int dims[2], F;
    pair <int, int> a[] = {{1e9, 0}, {1e9, 0}};
    vector <int> crg[2];

    scanf("%d%d%d", &dims[0], &dims[1], &F);
    crg[0].resize(dims[0], 0);
    crg[1].resize(dims[1], 0);
    for(int i=0; i<F; i++) {
        int a, b ;
        scanf("%d%d", &a, &b);
        a--, b--;
        crg[0][a]++;
        crg[1][b]++;
    }

    for(int i=0; i<2; i++)
        a[i] = calcaA(dims[i], crg[i]);

    printf("(Street: %d, Avenue: %d)\n", a[0].second+1, a[1].second+1);
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
}
