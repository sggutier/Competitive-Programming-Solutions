#include <bits/stdc++.h>
using namespace std;

void testCase(long long n) {
    long long ans = (n*(n-1))/2;
    if(ans%2)
        printf("%lld/2\n", ans);
    else
        printf("%lld\n", ans/2);
}

int main() {
    int tc, n;
    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        scanf("%d", &n);
        printf("Case %d: ", i);
        testCase(n);
    }
}
