#include <bits/stdc++.h>
using namespace std;

void testCase(int ant) {
    int act, ans=0;
    while(scanf("%d", &act)!=EOF && act) {
        ans = __gcd(ans, abs(ant-act));
        ant = act;
    }
    printf("%d\n", ans);
}

int main() {
    int n;
    while(scanf("%d", &n)!=EOF && n)
        testCase(n);
}
