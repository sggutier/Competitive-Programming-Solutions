#include <bits/stdc++.h>
using namespace std;

void testCase(int n) {
    int a, ans=0;
    for(; n; n--) {
        scanf("%d", &a);
        ans += a? 1 : -1 ;
    }
    printf("%d\n", ans);
}

int main() {
    int n;
    int tc = 0;

    while(scanf("%d", &n)!=EOF && n) {
        printf("Case %d: ",++tc);
        testCase(n);
    }
    
    return 0;
}
