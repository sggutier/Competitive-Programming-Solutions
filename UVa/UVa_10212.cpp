#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9;

void testCase(int N, int M) {
    int fin = N-M;
    long long ans = 1;
    for(int i=N; i>fin; i--) {
        ans *= i;
        while(ans%10==0)
            ans /= 10;
        ans %= mod;
    }
    printf("%lld\n", ans%10);
}

int main() {
    int a, b;

    while(scanf("%d%d", &a, &b)!=EOF)
        testCase(a, b);
    
    return 0;
}
