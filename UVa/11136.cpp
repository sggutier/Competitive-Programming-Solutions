#include <bits/stdc++.h>
using namespace std;

void testCase(int d) {
    multiset <int> S;
    int k, tmp;
    long long ans = 0;
    while(d--) {
        scanf("%d", &k);
        while(k--)  {
            scanf("%d", &tmp);
            S.insert(tmp);
        }
        if(S.size() < 2)
            continue;
        auto it=S.begin(), it2=S.end();
        it2--;
        ans += *it2 - *it;
        S.erase(it);
        S.erase(it2);
    }
    printf("%lld\n", ans);
}

int main() {
    int n;

    while(scanf("%d", &n)!=EOF && n)
        testCase(n);
    
    return 0;
}
