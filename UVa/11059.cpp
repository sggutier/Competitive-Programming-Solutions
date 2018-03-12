#include <bits/stdc++.h>
using namespace std;

void testCase(int n) {
    long long ans = 0;
    long long ant=1LL, fstNeg=1LL;
    for(int i=0; i<n; i++) {
        int a;
        scanf("%d", &a);
        ant *= a;
        ans = max(ans, ant);
        ans = max(ans, ant/fstNeg);
        if(a==0) {
            ant = 1LL;
            fstNeg = 1;
        }
        else if(a<0 && fstNeg==1)
            fstNeg = ant;
    }
    printf("%lld.\n\n", ans);
}

int main() {
    int n;

    for(int tc=1; scanf("%d", &n)!=EOF && n; tc++) {
        printf("Case #%d: The maximum product is ", tc);
        testCase(n);
    }
    
    return 0;
}
