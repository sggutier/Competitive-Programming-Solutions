#include <bits/stdc++.h>
using namespace std;
const int limN = 30001;

bool usd[limN];
pair<int,int> ans[limN];

pair<int,int> testCase(int n) {
    if(usd[n])
        return ans[n];
    usd[n] = true;
    int b = 31 - __builtin_clz(n);
    if((1<<(b+1))-1 == n)
        return ans[n] = make_pair(0, n);
    pair<int,int> k = testCase(((n^(1<<b))<<1) | 1);
    k.first ++;
    return ans[n] = k;
}

int main() {
    int tc;

    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        int tmp;
        scanf("%d", &tmp);
        pair<int,int> ans = testCase(tmp);
        printf("Case %d: %d %d\n", i, ans.first, ans.second);
    }

    return 0;
}
