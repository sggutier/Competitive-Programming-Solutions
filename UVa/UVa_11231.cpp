#include <bits/stdc++.h>
using namespace std;

long long calco(long long n, long long m) {
    n = max(n-7, 0LL);
    m = max(m-7, 0LL);
    return n*m - (n*m)/2LL;
}

long long testCase(long long n, long long m, bool c) {
    if(c) {
        return calco(n, m);
    }
    else {
        return calco(n, m-1) + calco(n-1, 8);
    }
}

int main() {
    int a, b, c;

    while(scanf("%d%d%d", &a, &b, &c)!=EOF && a!=0 && b!=0)
        printf("%lld\n", testCase(a, b, c));
    
    return 0;
}
