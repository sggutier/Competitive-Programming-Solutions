#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector <int> vals;
    BIT() {
        n = 0;
    }
    BIT(int _n) {
        n = _n;
        vals.resize(n+1);
    }
    void mete(int pos, int nov) {
        for(; pos<n; pos+=(pos & -pos))
            vals[pos] = max(vals[pos], nov);
    }
    int saca(int pos) {
        int ans = 0;
        for(; pos; pos-=(pos & -pos))
            ans = max(ans, vals[pos]);
        return ans;
    }
};

int testCase() {
    int n, upCnt, downCnt;
    scanf("%d%d%d", &n, &upCnt, &downCnt);
    upCnt++, downCnt++;
    vector <int> dict((n*n)+1);
    BIT bt(upCnt);
    int ans = 0;

    for(int i=1; i<=upCnt; i++) {
        int a;
        scanf("%d", &a);
        dict[a] = i;
    }
    for(int i=1; i<=downCnt; i++) {
        int a, pos, w;
        scanf("%d", &a);
        pos = dict[a];
        // printf("%d %d\n", a, pos);
        if(!pos)
            continue;
        w = bt.saca(pos-1) + 1;
        // printf("%d %d => %d\n", a, pos, w);
        ans = max(ans, w);
        bt.mete(pos, w);
    }
    // printf("%d\n", ans);
    return ans;
}

int main() {
    int tc;

    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("Case %d: %d\n", i, testCase());
    }
    
    return 0;
}
