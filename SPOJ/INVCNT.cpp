#include <bits/stdc++.h>
using namespace std;
const int limN = 1e7 + 5;

int crgs[limN];

void mete(int pos) {
    for(; pos; pos-=(pos & -pos))
        crgs[pos] ++;
}

int saca(int pos) {
    int ans = 0;
    for(; pos<limN; pos += (pos & -pos))
        ans += crgs[pos];
    return ans;
}

void testCase() {
    memset(crgs, 0, sizeof(crgs));
    long long ans = 0;
    int N, a;
    for(scanf("%d", &N); N; N--) {
        scanf("%d", &a);
        ans += saca(a);
        mete(a);
    }
    printf("%lld\n", ans);
}

int main() {
    int tc;
    for(scanf("%d", &tc); tc; tc--)
        testCase();
}
